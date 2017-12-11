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

static void cl_recv_cb(uv_udp_t* handle,
    ssize_t nread,
    const uv_buf_t* buf,
    const struct sockaddr* addr,
    unsigned flags) 
{
    if (nread < 0) 
    {
        //error happens
        return;
    }

    if (nread == 0) 
    {
        return;
    }

    printf("I receive the message from server:%s\n", buf->base);
    
    //uv_close((uv_handle_t*) handle, close_cb);
}


static void cl_send_cb(uv_udp_send_t* req, int status) 
{   
    if (status) {
        printf("Send error %s\n", uv_strerror(status));
        return;
    }
    else
    {
        uv_udp_recv_start(req->handle, alloc_cb, cl_recv_cb);    
    }
}

int main(void) 
{
    uv_udp_t client; 
    uv_loop_t* loop = uv_default_loop();
    int r = uv_udp_init(loop, &client);   

    struct sockaddr_in addr;    
    r = uv_ip4_addr("127.0.0.1", 8899, &addr);  

    char snd[] = "PING";
    uv_buf_t buf;
    buf = uv_buf_init(snd, 4);

    printf("I am sending message to server:%s.\n", buf.base);

    uv_udp_send_t req;
    uv_udp_send(
        &req,
        &client,
        &buf,
        1,
        (const struct sockaddr*) &addr,
        cl_send_cb);    

    uv_run(loop, UV_RUN_DEFAULT);

    return 0;
}

