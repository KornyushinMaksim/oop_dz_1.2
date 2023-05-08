#pragma once
#include <iostream>
#include <string>
#include "Phone_book.h"
using namespace std;

class File_open
{
private:
	ifstream in;
	string path;
public:
	File_open(string _path) {
		this->path = _path;
	}

	Phone_book& open_file();
};

