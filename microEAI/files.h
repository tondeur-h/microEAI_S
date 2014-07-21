/*
 * files.h
 *
 *  Created on: 8 juil. 2014
 *      Author: herve
 */

#ifndef FILES_H_
#define FILES_H_

#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

#include <string>
#include <iostream>
#include <vector>
#include <cstdio>


namespace reading {


/*
 *
 */
class files {

public:
	struct fichier{
	//std::string path;
	std::string name;
	int size;
	timespec tdate;
	};

	std::string path;
	static const int BYNAME=1;
	static const int BYDATE=2;

	files();
	std::vector<fichier>* list_vector();
	int nb_files();
	std::string name_file(int x);
	std::string path_file();
	std::string fullname_file(int x);
	bool order_by(int type);
	int size_file(int x);
	long int* date_file(int x);
	bool list_files(std::string path);
	bool delete_file(std::string fichier);
	bool mllp(std::string fichier);
	virtual ~files();
};

} /* namespace reading */

#endif /* FILES_H_ */
