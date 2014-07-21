/*
 * main.cpp
 *
 *  Created on: 07 juillet 2014
 *      Author: Tondeur Herve
 *
 *  This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */


//include read and write console stream
#include <iostream>
#include "files.h"
#include <time.h>
#include "socket.h"


reading::files* f;
network::net* n;
const int port=1234;
const std::string host="127.0.0.1";


int main (int argc, char ** argv){
f=new reading::files();
n=new network::net();


//read list of files
f->list_files("/home/herve");
f->order_by(f->BYDATE);

//read file
std::cout<<f->nb_files()<<std::endl;

for (int i=0;i<f->nb_files();i++){
//std::cout<<f->name_file(i)<<std::endl;
//std::cout<<f->path_file()<<std::endl;
//std::cout<<f->fullname_file(i)<<std::endl;
//std::cout<<f->size_file(i)<<std::endl;
//std::cout<<*f->date_file(i)<<std::endl;
//std::cout<<ctime(f->date_file(i))<<std::endl;

//wrap message for mllp format if needed


//send to socket

	f->mllp(f->fullname_file(i));
if (n->sock(f->fullname_file(i),port,host)){
	//delete file
	f->delete_file(f->fullname_file(i));
}

}

delete(f);
delete(n);

}

