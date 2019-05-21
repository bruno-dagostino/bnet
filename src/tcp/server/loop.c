/*
 * loop.c
 *
 *  Created on: May 21, 2019
 *      Author: bruno-dagostino
 */

#include <sys/socket.h>
#include <pthread.h>
#include "create_socket.h"
#include "accept_connection.h"
#include "loop.h"
#include "./../../utils/die_with_error.h"

/* Type Defs ******************************************************************/

/**
 * This structure contains all the arguments passed to the new thread.
 */
struct threadargs {
	int client_socket;
};

/* Private API ****************************************************************/

/*
 * The following function is used to handle client.
 */
static void *client_handler(void *args);

/*
 * The following function is used to handle new thread behavior.
 */
void server_loop(unsigned short port) {
	int server_socket, client_socket;
	pthread_t thread_id;
	struct threadargs *args;

	server_socket = create_socket(port);

	for (;;) {
		client_socket = accept_connection(server_socket);

		if ((args = (struct threadargs *) malloc(sizeof(args))) == NULL)
			die_with_error("malloc() failed");

		args->client_socket = client_socket;

		if (pthread_create(&thread_id, NULL, client_handler, (void *) args) != 0)
			die_with_error("pthread_create() failed");
	}
}

void *client_handler(void *args) {
	int client_socket;

	pthread_detach(pthread_self());

	client_socket = ((struct threadargs *) args) -> client_socket;

	free(args);

	// handle_client(client_socket);

	return (NULL);
}
