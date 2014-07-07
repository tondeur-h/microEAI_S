/*
 * config.cpp
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


#include "config.h"
#include <iostream>
#include <libintl.h>

namespace configSpace {


/*!
 * constructor, just define some variables
 */
config::config() {}


/*!
 * to do nothing...
 */
config::~config() {
	// TODO Auto-generated destructor stub
}



/*!
 * Open and read config file,
 * test parse
 * @param path
 * @return
 */
bool config::init_cfg(std::string path){

// Read the file. If there is an error, report it and exit.
try
{
//open and read file
cfg.readFile(path.c_str());
} //exception for IO error
catch(const libconfig::FileIOException &fioex)
{
std::cerr<<gettext("No config file found...Use default values!")<<std::endl;
return false;
} //exception for parse error
catch(const libconfig::ParseException &pex)
{
std::cerr << gettext("Parse error at ") << pex.getFile() << ":" << pex.getLine()<< " - " << pex.getError() << std::endl;
return false;
}
//all is ok
return true;
}




/*!
 * read value in config file...
 * @param root
 */
std::string config::read_config_string(const libconfig::Setting& root,std::string group,std::string field, std::string default_value){
	 // Read colors config
	std::string ret_val;
	  try
	  {
	    const libconfig::Setting &colors = root["tinyEAI"][group];
	    colors.lookupValue(field,ret_val);
	  }
	  catch(const libconfig::SettingNotFoundException &nfex)
	  {
	   ret_val=default_value; //reset to normal, is the default value...
	  }
return ret_val;
}



/*!
 * read value in config file...
 * @param root
 */
int config::read_config_int(const libconfig::Setting& root,std::string group,std::string field, int default_value){
	 // Read colors config
	int ret_val;
	  try
	  {
	    const libconfig::Setting &colors = root["tinyEAI"][group];
	    colors.lookupValue(field,ret_val);
	  }
	  catch(const libconfig::SettingNotFoundException &nfex)
	  {
	   ret_val=default_value; //reset to normal, is the default value...
	  }
return ret_val;
}




/*!
 * read value in config file...
 * @param root
 */
bool config::read_config_bool(const libconfig::Setting& root,std::string group,std::string field, bool default_value){
	 // Read colors config
	bool ret_val;
	  try
	  {
	    const libconfig::Setting &colors = root["tinyEAI"][group];
	    colors.lookupValue(field,ret_val);
	  }
	  catch(const libconfig::SettingNotFoundException &nfex)
	  {
	   ret_val=default_value; //reset to normal, is the default value...
	  }
return ret_val;
}

} /* namespace config */
