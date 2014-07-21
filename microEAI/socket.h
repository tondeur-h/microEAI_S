/*
 * socket.h
 *
 *  Created on: 17 juil. 2014
 *      Author: herve
 */

#ifndef SOCKET_H_
#define SOCKET_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <linux/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#include <string>

namespace network{

class net{
public:
net();
~net();
void error(const char *msg);
bool sock(std::string fichier, int port, std::string host);
}; //end class

} //end namespace

#endif /* SOCKET_H_ */
