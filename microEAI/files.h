/*
 * files.h
 *
 *  Created on: 08 juillet 2014
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

#ifndef FILES_H_
#define FILES_H_

//c include
#include <dirent.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>


//c++ include
#include <iostream>
#include <string>


namespace dirfile {

/*
 *
 */
class files {
public:
	files();
	bool list_files(std::string path, std::string extension);
	bool verif_ext (std::string fp,std::string ext);
	virtual ~files();
};

} /* namespace dirfile */
#endif /* FILES_H_ */
