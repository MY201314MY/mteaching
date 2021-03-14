#ifndef __CEBSOCKET_H__
#define __CEBSOCKET_H__

#include <bits/stdint-uintn.h>

#define websocket_packet_frame_header \
    uint8_t fin_rsv_opcode; \
    uint8_t mlen8;
;

typedef struct websocket_packet_frame_len8 websocket_packet_frame_len8_t;
struct websocket_packet_frame_len8 {
    websocket_packet_frame_header
};

typedef struct cebsocket_packet_frame_len16 cebsocket_packet_frame_len16_t;
struct cebsocket_packet_frame_len16 {
    websocket_packet_frame_header
    uint16_t len16;
};

typedef struct cebsocket_packet_frame_len64 cebsocket_packet_frame_len64_t;
struct cebsocket_packet_frame_len64 {
    websocket_packet_frame_header
    uint64_t len64;
};

#define CEBSOCKET_GUID "258EAFA5-E914-47DA-95CA-C5AB0DC85B11"

#define HTTP_HEADER_BUFF_SIZE 700
#define HTTP_PROP_BUFF_SIZE 40
#define HTTP_VAL_BUFF_SIZE  50

enum CEBSOCKET_HTTP_HEADER_PARSER_STATE {
    CEBSOCKET_HTTP_HEADER_PARSER_STATE_METHOD = 1,
    CEBSOCKET_HTTP_HEADER_PARSER_STATE_PROP,
    CEBSOCKET_HTTP_HEADER_PARSER_STATE_SPACE,
    CEBSOCKET_HTTP_HEADER_PARSER_STATE_VAL,
    CEBSOCKET_HTTP_HEADER_PARSER_STATE_CR,
    CEBSOCKET_HTTP_HEADER_PARSER_STATE_END
};

enum CEBSOCKET_RESPONSE {
    CEBSOCKET_RESPONSE_INSTANCE_PORT = 1
};

typedef struct websocket websocket_t;
typedef struct websocket_clients websocket_clients_t;

struct websocket {
    int port;
    char* host_address;
    char* bind_address;
    websocket_clients_t* clients;
    void (*on_data)(websocket_clients_t*, char*);
    void (*on_connected)(websocket_clients_t*);
    void (*on_disconnected)(websocket_clients_t*);
};

struct websocket_clients {
    websocket_t* ws;
    int id;
    int socket;
    int server_socket;
    int address;
    char* ws_key;
    void* data;
    websocket_clients_t* prev;
    websocket_clients_t* next;
};

websocket_t* websocket_init(int port);
void websocket_listen(websocket_t* ws);
void websocket_send(websocket_clients_t* client, char* message);

websocket_clients_t* websocket_client_init();
void websocket_free(websocket_t* ws);
void websocket_client_free(websocket_clients_t* client);

static void client_handler(websocket_clients_t* client);
static void receive_http_packet(websocket_clients_t* client);
static void receive_ws_packet(websocket_clients_t* client);
static void client_disconnected(websocket_clients_t* client);

void broken_pipe_handler(int sig);

#endif