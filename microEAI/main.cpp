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
using std::cout;
using std::cin;
using std::string;

//include config manager
#include "config.h"
using configSpace::config;

//include gettext tranlation fonction.
#include <libintl.h>
#include <locale.h>

//include files.h list files
#include "files.h"


config* cfgEAI;
string ip;
int port;
bool mllp;
string filepath;
string fileext;


/*!
 *reading config file for microEAI
 *pathConf = fullpath of the file config file
 */
void readConfig(string pathConf){
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

/*
std::cout<<"ip: "<<ip<<std::endl;
std::cout<<"port: "<<port<<std::endl;
std::cout<<"mllp: "<<mllp<<std::endl;
std::cout<<"path: "<<filepath<<std::endl;
std::cout<<"ext: "<<fileext<<std::endl;
*/

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
//verif number of args


//translation with gettext
setTranslation();

//read config file...
readConfig(argv[1]);

//read list of files
dirfile::files* f = new dirfile::files();

f->list_files(filepath,fileext);
delete f;

//read each file


//wrap message for mllp format if needed


//send to socket


}

