#define _GNU_SOURCE

#include <stdio.h>

#include "../include/websocket.h"

void on_data(websocket_clients_t* client, char* data) {
    printf("WebSocket Message: %s\n", data);
    
    websocket_send(client, "Hello from WebSocket server!");
}

void on_connected(websocket_clients_t* client) {
    printf("Client connected #%d\n", client->id);
}

void on_disconnected(websocket_clients_t* client) {
    printf("Client disconnected #%d\n", client->id);
}

int main() {
    printf("Starting WebSocket server..\n");

    websocket_t* ws = websocket_init(8080);

    ws->on_data = on_data;
    ws->on_connected = on_connected;
    ws->on_disconnected = on_disconnected;
    
    websocket_listen(ws);
    
    return 0;
}