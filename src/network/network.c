#include "network.h"

void serverLog(char *msg)
{
	printf("[SERVER]::LOG -> %s", msg);
}

void onConnect(ws_cli_conn_t *_client)
{
	char *cli;
	cli = ws_getaddress(_client);
	serverLog("\nConnection opened at address:\n");
	serverLog(cli);
}

void onClose(ws_cli_conn_t *_client)
{
	char *cli;
	cli = ws_getaddress(_client);
	serverLog("\nConnection shutdown at address:\n");
	serverLog(cli);
}

void onMessage(ws_cli_conn_t *_client, const unsigned char *msg, uint64_t size, int type2)
{
	char *cli;
	cli = ws_getaddress(client);
	serverLog("Incoming-> request:\n");
	serverLog("FROM::");
	serverLog(cli);
	serverLog("\n");
	serverLog("DATA::");
	serverLog(msg);
	serverLog("\n");
}

int main(void)
{
	struct ws_events evs;
	evs.onopen = &onConnect;
	evs.onclose = &onClose;
	evs.onmessage = &onMessage;
	
	ws_socket(&evs, 80, 0, 1000);
	return (0);
}

