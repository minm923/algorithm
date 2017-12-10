#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <uv.h>

uv_loop_t *loop;
uv_udp_t send_socket;
uv_udp_t recv_socket;

void alloc_buffer(uv_handle_t *handle, size_t suggested_size, uv_buf_t *buf) {
  buf->base = (char*) malloc(suggested_size);
  buf->len = suggested_size;
}

void on_read(uv_udp_t *req, ssize_t nread, const uv_buf_t *buf, const struct sockaddr *addr, unsigned flags) 
{
    if (nread < 0) {
        fprintf(stderr, "Read error %s\n", uv_err_name(nread));
        uv_close((uv_handle_t*) req, NULL);
        free(buf->base);
        return;
    }

    fprintf(stdout, "recv : ");
    for (int i=0; i<buf->len; ++i)
    {
        fprintf(stdout, "%c", buf->base[i]);
    }

    free(buf->base);
    //uv_udp_recv_stop(req);
}

void on_send(uv_udp_send_t *req, int status) {
    if (status) 
    {
        fprintf(stderr, "Send error %s\n", uv_strerror(status));
        return;
    }
    else
    {
       fprintf(stdout, "Send out....\n");
    }
}

int main(int argc, char* argv[])
{
    loop = uv_default_loop();

    // receive
    uv_udp_init(loop, &recv_socket);
    struct sockaddr_in recv_addr;
    uv_ip4_addr("127.0.0.1", 6666, &recv_addr);
    uv_udp_bind(&recv_socket, (const struct sockaddr *)&recv_addr, UV_UDP_REUSEADDR);
    uv_udp_recv_start(&recv_socket, alloc_buffer, on_read);


    // send
    uv_udp_init(loop, &send_socket);
    struct sockaddr_in send_addr;
    uv_ip4_addr("127.0.0.1", 9999, &send_addr);

    uv_buf_t buffer;
    alloc_buffer(NULL, 256, &buffer);
    memset(buffer.base, 0, buffer.len);
    memcpy(buffer.base, "hello server", 13);

    uv_udp_send_t send_req;
    int ret = uv_udp_send(&send_req, &send_socket, &buffer, 1, (const struct sockaddr *)&send_addr, on_send);
    printf("send ret %d \n", ret);

    return uv_run(loop, UV_RUN_DEFAULT);
}

