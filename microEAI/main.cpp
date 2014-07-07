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

config* cfgEAI;

//reading config file for tinyEAI
void readConfig(string pathConf){
//get root from the config file
const libconfig::Setting& root = cfgEAI->configSpace::config::cfg.getRoot();

cfgEAI=new config();
//open config file
cfgEAI->init_cfg(pathConf);
//read ip destination
cfgEAI->read_config_string(root,"socket","IP","127.0.0.1");

}


int main (int argc, char ** argv){
//verif number of args


//translation with gettext
	setlocale( LC_ALL, "" );
	bindtextdomain( "microEAI", "/usr/share/locale" );
	textdomain( "microEAI" );


//read config file...
readConfig(argv[1]);

//read list of files

//read file


//wrap message for mllp format if needed

//send to socket


}

