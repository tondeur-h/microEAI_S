/*
 * files.cpp
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


#include "files.h"


namespace dirfile {

DIR* did;
dirent*  dif;
struct stat sf;
std::string fullpath;

files::files() {
	// TODO Auto-generated constructor stub
}

bool files::verif_ext(std::string fp, std::string ext){
std::string t=fp.substr((fp.length()-ext.length()),ext.length());
if (t.compare(ext)==0){return true;}
	return false;
}


bool files::list_files(std::string path, std::string extension){

	//ouvrir le répertoire
	if ((did=opendir(path.c_str()))==NULL){
		return false;
	}

	//pour chaque element si celui n'est pas un repertoire
	while ((dif=readdir(did))!=NULL){
		//si ce n'est pas un répertoire...
		if (dif->d_type!=DT_DIR){
			//garder le fichier
			//convertir en un chemin complet
			fullpath=path+"/"+std::string(dif->d_name);


			//recuperer la date de derniere modification
			if ((stat(fullpath.c_str(), &sf)!=-1) && (verif_ext(fullpath,extension))){
				std::cout<<fullpath<<" # "<<&sf.st_mtim.tv_nsec<<std::endl;

			}

		}
	}

return true;
}

files::~files() {
	// TODO Auto-generated destructor stub
}

} /* namespace pawk */
