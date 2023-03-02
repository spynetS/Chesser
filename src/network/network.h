#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ws.h>

void serverLog(char *msg);
void onConnect(ws_cli_conn_t *_client);
void onClose(ws_cli_conn_t *_client);
void onMessage(ws_cli_conn_t *_client,
		const unsigned char *msg,
		uint64_t size, int type2);

