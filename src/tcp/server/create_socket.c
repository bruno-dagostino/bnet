/*
 * create_socket.c
 *
 *  Created on: May 21, 2019
 *      Author: bruno-dagostino
 */

#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>
#include "create_socket.h"
#include "./../../utils/die_with_error.h"

#define MAXPENDING 5

int create_socket(unsigned short port) {
	int server_socket;
	struct sockaddr_in server_address;

	if ((server_socket = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0)
		die_with_error("socket() failed");

	memset(&server_address, 0, sizeof(server_address));
	server_address.sin_family = AF_INET;
	server_address.sin_addr.s_addr = htonl(INADDR_ANY);
	server_address.sin_port = htons(port);

	if (bind(server_socket, (struct sockaddr *) &server_address, sizeof(server_address)) < 0)
		die_with_error("bind() failed");

	if (listen(server_socket, MAXPENDING) < 0)
		die_with_error("listen() failed");

	return server_socket;
}
