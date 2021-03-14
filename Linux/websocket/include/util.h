/*
 * cebsocket is a lightweight WebSocket library for C
 *
 * https://github.com/rohanrhu/cebsocket
 *
 * Licensed under MIT
 * Copyright (C) 2020, Oğuzhan Eroğlu (https://oguzhaneroglu.com/) <rohanrhu2@gmail.com>
 *
 */

#ifndef __CEBSOCKET_UTIL_H__
#define __CEBSOCKET_UTIL_H__

void websocket_util_verbose(const char* format, ...);
void websocket_util_set_verbose(int _is_verbose);

char* websocket_util_base64_encode(char* str);
char* websocket_util_base64_decode(char* str);

#endif