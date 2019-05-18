/*
 * die_with_error.c
 *
 *  Created on: May 15, 2019
 *      Author: bruno-dagostino
 */

#include <stdio.h>
#include <stdlib.h>
#include "die_with_error.h"

void die_with_error(char *error_message) {
	perror(error_message);

	exit(1);
}
