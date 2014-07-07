/*
 * config.h
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


#ifndef CONFIG_H_
#define CONFIG_H_

#include <string>
#include <libconfig.h++>
#include <cstdlib>


namespace configSpace {

/*
 *class define for reading config file
 *this class used libconfig++ for this purpose
 */

class config {

public:
	config(); //constructor init values
	bool init_cfg(std::string path); //open and read config file
	int read_config_int(const libconfig::Setting& root,std::string group,std::string field,int default_value); //read integer...
	bool read_config_bool(const libconfig::Setting& root,std::string group,std::string field,bool default_value); //read bool...
	std::string read_config_string(const libconfig::Setting& root,std::string group,std::string field,std::string default_value); //read string...
	virtual ~config();

	//local cfg...
	libconfig::Config cfg;

};

} /* namespace config */

#endif /* CONFIG_H_ */
