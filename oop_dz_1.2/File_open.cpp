#include "File_open.h"

Phone_book& File_open::open_file()
{
	Phone_book* pers = new Phone_book();
	in.open(path);
	if (in.is_open()) {
		while (!in.eof()) {
			string pole_class[6];
			for (int i = 0; i < 6; i++) {
				string str;
				getline(in, str);
				pole_class[i] = str;
			}
			Contact contact(pole_class[0].c_str(),
				pole_class[1].c_str(), 
				pole_class[2].c_str(), 
				pole_class[3].c_str(), 
				pole_class[4].c_str(), 
				pole_class[5].c_str());
			pers->add_contact(contact);
		}
	}
	in.close();
	return *pers;
}
