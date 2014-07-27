/*
 * socket.h
 *
 *  Created on: 17 juil. 2014
 *      Author: herve
 */

#ifndef SOCKET_H_
#define SOCKET_H_

#include <cstdio>
#include <cstdlib>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <linux/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#include <string>
#include <iostream>

namespace network{

class net{
public:
bool mllp;

net();
~net();
int sock(std::string fichier, int port, std::string host);
void setMLLP(bool mllp);
void read_file(std::string fichier);
}; //end class

} //end namespace

#endif /* SOCKET_H_ */
