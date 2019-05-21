/*
 * main.c
 *
 *  Created on: May 17, 2019
 *      Author: bruno-dagostino
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "bool.h"
#include "./tcp/server/loop.h"

/* Type Defs ******************************************************************/

/**
 * This structure contains all the options parsed from the command line.
 */
struct mainopts {
	BOOL listen;
	BOOL command;
	BOOL upload;
	char *execute;
	char *target;
	char *upload_destination;
	unsigned short port;
};

static const char *optString = "hle:t:p:cu:?";

/* Private API ****************************************************************/

/*
 * The following function is used to translate options set via the command line
 * to usable values.
 */
static void mainopts_parse(struct mainopts *opts, int argc, char *argv[]);

/*
 * The following function is used to show the usage.
 */
static void usage(void);

/* Main ***********************************************************************/

int main(int argc, char *argv[]) {
	struct mainopts opts;

	if (argc == 1)
		usage();

	mainopts_parse(&opts, argc, argv);

	if (opts.listen == TRUE)
		server_loop(opts.port);

	return 0;
}

/* Private Impl ***************************************************************/

void mainopts_parse(struct mainopts *opts, int argc, char *argv[]) {
	int opt = 0;

	opt = getopt(argc, argv, optString);

	while (opt != -1) {
		switch (opt) {
		case 'h':
			usage();
			break;

		case 'l':
			opts->listen = TRUE;
			break;

		case 'e':
			opts->execute = optarg;
			break;

		case 't':
			opts->target = optarg;
			break;

		case 'p':
			opts->port = atoi(optarg);
			break;

		case 'c':
			opts->command = TRUE;
			break;

		case 'u':
			opts->upload = TRUE;
			opts->upload_destination = optarg;
			break;

		case '?':
			usage();
			break;

		default:
			break;
		}

		opt = getopt(argc, argv, optString);
	}
}

void usage(void) {
	printf("B Net Tool\n\n");
	printf("Usage: ./bnet -t <target> -p <port>\n");
	printf("-l\t- listen on [host]:[port] for incoming connections\n");
	printf("-e\t- execute the given file upon receiving a connection\n");
	printf("-c\t- initialize a command shell\n");
	printf(
			"-u\t- upon receiving connection upload a file and write to [destination]\n\n");
	printf("Examples: \n");
	printf("./bnet -l -p 5555\n");
	printf("./bnet -l -p 5555 -c\n");
	printf("./bnet -l -p 5555 -u c:\\target.exe\n");
	printf("./bnet -l -p 5555 -e 'cat /etc/passwd'\n\n");

	exit(1);
}
