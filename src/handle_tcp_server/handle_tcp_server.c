/*
 * handle_tcp_server.c
 *
 *  Created on: May 18, 2019
 *      Author: bruno-dagostino
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include "handle_tcp_server.h"
#include "./../bool.h"
#include "./../utils/die_with_error.h"
#include "./../network/dump.h"

void client_sender(const char *target, const unsigned short port) {
	int sockfd;
	struct sockaddr_in target_addr;
	char buffer[1024];
	unsigned char response[1024];
	int recv_length = 1;

	if ((sockfd = socket(PF_INET, SOCK_STREAM, 0)) == -1)
		die_with_error("socket() failed.");

	target_addr.sin_family = AF_INET;
	target_addr.sin_port = htons(port);
	target_addr.sin_addr.s_addr = inet_addr(target);
	memset(&(target_addr.sin_zero), "\0", 8);

	if (connect(sockfd, (struct sockaddr *) &target_addr, sizeof(struct sockaddr)) == -1)
		die_with_error("connect() failed");

	while (TRUE) {
		while (recv_length > 0) {
			if ((recv_length = recv(sockfd, &response, 1024, 0)) < 0)
				die_with_error("recv() failed");

			if (recv_length < 1024)
				break;
		}

		printf("RECV: %d bytes\n", recv_length);
		dump(response, recv_length);

		printf("> ");
		gets(buffer);

		if (send(sockfd, buffer, strlen(buffer), 0) == -1)
			die_with_error("send() failed");
	}
}
