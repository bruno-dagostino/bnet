/*
 * accept_connection.c
 *
 *  Created on: May 21, 2019
 *      Author: bruno-dagostino
 */

#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include "accept_connection.h"
#include "./../../utils/die_with_error.h"

int accept_connection(int server_socket) {
	int client_socket;
	struct sockaddr_in client_address;
	unsigned int client_length;

	client_length = sizeof(client_address);

	if ((client_socket = accept(server_socket, (struct sockaddr *) &client_address, &client_length)) < 0)
		die_with_error("accept() failed");

	printf("Handling client %s\n", inet_ntoa(client_address.sin_addr));

	return client_socket;
}
