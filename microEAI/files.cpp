/*
 * files.cpp
 *
 *  Created on: 8 juil. 2014
 *      Author: herve
 */

#include "files.h"


namespace reading {

//structure for exploring directories
DIR* dip;
struct dirent* dit;
struct stat sf;

//structure for each file
struct files::fichier afile;

//vector exploit
std::vector<files::fichier>* v_list_files;

/*!
 * Constructeur de la classe initialise le vecteur
 */
files::files() {
   v_list_files=new std::vector<fichier>();
}


/*!
 * Retourne le vecteur
 */
std::vector<files::fichier>* files::list_vector(){
return v_list_files;
}

/*!
 * taille du vecteur
 */
int files::nb_files(){
	return v_list_files->size();
}

std::string files::path_file(){
	return files::path;
}

std::string files::name_file(int pos){
	if (pos>v_list_files->size()) return "-1";

	return v_list_files->at(pos).name;
}

std::string files::fullname_file(int pos){
	if (pos>v_list_files->size()) return "-1";
	return path+"/"+v_list_files->at(pos).name;
}

long int* files::date_file(int pos){
if (pos>v_list_files->size()) return NULL;
return &v_list_files->at(pos).tdate.tv_sec;
}

int files::size_file(int pos){
	if (pos>v_list_files->size()) return -1;
	return v_list_files->at(pos).size;
}

/*!
 * verifie si le fichier contient l'extension xxx
 */
bool verif_extension(std::string fp, std::string ext){
if((fp.substr(fp.length()-ext.length(),ext.length())).compare(ext)==0){return true;} else{return false;}
}


/*!
 * lister tous les fichiers d'un répertoire YYYY
 */
bool files::list_files(std::string path){
if ((dip=opendir(path.c_str()))== NULL){
	return false;
}
chdir(path.c_str());
this->path=path;

while ((dit=readdir(dip))!=NULL){

	if (dit->d_type!=DT_DIR){
		std::string chemin=path+"/"+std::string(dit->d_name);

		if (stat(chemin.c_str(),&sf)==-1){
			std::cout<<"Erreur lecture"<<std::endl;
			return false;
		} else
		{
			//si le fichier correspond à l'extension...
			if (verif_extension(chemin,".hl7")){
				afile.size=sf.st_size;
				afile.name=std::string(dit->d_name);
				afile.tdate=sf.st_mtim;

				v_list_files->push_back(afile);
				//essayer de convertir tdate en t_time

			}
		}

	}
}
//fermer le répertoire courant...
closedir(dip);

return true;
}


bool files::delete_file(std::string fichier){
if (std::remove(fichier.c_str())==0){
	return true;
}
//failed
return false;
}


bool files::order_by(int type){

	return true;
}


files::~files() {
	// TODO Auto-generated destructor stub
}

} /* namespace reading */
