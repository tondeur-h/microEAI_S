/*
 * main.cpp
 *
 *  Created on: 7 juil. 2014
 *      Author: herve
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

