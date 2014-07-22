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
#include <time.h>
#include "socket.h"

//include read and write console stream
#include <iostream>
#include <string>

//include config manager
#include "config.h"
using configSpace::config;

//include gettext tranlation fonction.
#include <libintl.h>
#include <locale.h>

//include files.h list files
#include "files.h"


config* cfgEAI;
std::string ip;
bool mllp;
std::string filepath;
std::string fileext;


reading::files* f;
network::net* n;
int port=1234;
const std::string host="127.0.0.1";



/*!
 *reading config file for microEAI
 *pathConf = fullpath of the file config file
 */
void readConfig(std::string pathConf){
//std::cout<<pathConf<<std::endl;

cfgEAI=new config();
//open config file
cfgEAI->init_cfg(pathConf);
//get root from the config file
const libconfig::Setting& root = cfgEAI->configSpace::config::cfg.getRoot();

//read ip destination
ip=cfgEAI->read_config_string(root,"socket","ip","127.0.0.1");


filepath=cfgEAI->read_config_string(root,"pathfile","path","/home/herve");
fileext=cfgEAI->read_config_string(root,"pathfile","ext","hl7");
port=cfgEAI->read_config_int(root,"socket","port",4200);
mllp=cfgEAI->read_config_bool(root,"socket","mllp",true);


/*std::cout<<"ip: "<<ip<<std::endl;
std::cout<<"port: "<<port<<std::endl;
std::cout<<"mllp: "<<mllp<<std::endl;
std::cout<<"path: "<<filepath<<std::endl;
std::cout<<"ext: "<<fileext<<std::endl;*/


delete cfgEAI;
}


/*!
 * setTranslation function
 * set the gettext translation library on
 * no parameters
 */
void setTranslation(){
	setlocale( LC_ALL, "" );
	bindtextdomain( "microEAI", "/usr/share/locale" );
	textdomain( "microEAI" );
}




int main (int argc, char ** argv){

	//translation with gettext
	setTranslation();

	//read config file...
	readConfig(argv[1]);


f=new reading::files();
n=new network::net();


//read list of files
f->list_files(filepath,fileext);
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

	n->setMLLP(mllp);

if (n->sock(f->fullname_file(i),port,host)){
	//delete file
	f->delete_file(f->fullname_file(i));
}

}

delete(f);
delete(n);

}

