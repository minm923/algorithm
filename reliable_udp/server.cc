#include "uv.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


static void alloc_cb(uv_handle_t* handle,
    size_t suggested_size,
    uv_buf_t* buf) 
{
    static char slab[65536];

    buf->base = slab;
    buf->len = sizeof(slab);
}

static void close_cb(uv_handle_t* handle) 
{
    uv_is_closing(handle);
}

static void sv_send_cb(uv_udp_send_t* req, int status) 
{
    //uv_close((uv_handle_t*) req->handle, close_cb);

    if (status) 
    {
        printf("Send error %s\n", uv_strerror(status));
        return;
    }
    else
    {
    }
}

static void sv_recv_cb(uv_udp_t* handle,
    ssize_t nread,
    const uv_buf_t* rcvbuf,
    const struct sockaddr* addr,
    unsigned flags) 
{
    if (nread < 0) 
    {

    }

    if (nread == 0) 
    {
        return;
    }

    printf("I receive the message from client:%s.\n", rcvbuf->base);

    //uv_udp_recv_stop(handle);

    char snd[] = "PONG";
    uv_buf_t sndbuf;
    sndbuf = uv_buf_init(snd, 4);

    printf("I send the message to client:%s.\n", sndbuf.base);

    uv_udp_send_t req;
    uv_udp_send(&req, handle, &sndbuf, 1, addr, sv_send_cb);
}

int main(void) 
{
    uv_loop_t *loop = uv_default_loop();
    uv_udp_t server;

    int r = uv_udp_init(loop, &server);
    struct sockaddr_in addr;
    r = uv_ip4_addr("127.0.0.1", 8899, &addr);
    r = uv_udp_bind(&server, (const struct sockaddr*) &addr, UV_UDP_REUSEADDR);
    r = uv_udp_recv_start(&server, alloc_cb, sv_recv_cb);

    uv_run(loop, UV_RUN_DEFAULT);

    return 0;
}

