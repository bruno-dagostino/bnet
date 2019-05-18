/*
 * send_recv.h
 *
 *  Created on: May 18, 2019
 *      Author: bruno-dagostino
 */

#ifndef SEND_RECV_H_
#define SEND_RECV_H_

int send_string(int sockfd, unsigned char *buffer);
int recv_line(int sockfd, unsigned char *dest_buffer);

#endif /* SEND_RECV_H_ */
