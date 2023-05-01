#include "Contact.h"
#include "Phone_book.h"
#include <iostream>
#include <fstream>
using namespace std;

char* Contact :: set_name() {
	return name;
}

void Contact :: get_name(char* _name) {
	if (_name && name) {
		//delete[] name;
		name = new char[strlen(_name) + 1];
		_if_for_construstot(name, _name);
	}
}

char* Contact :: set_lastname() {
	return lastname;
}

void Contact :: get_lastname(char* _lastname) {
	if (_lastname && lastname) {
		//delete[] lastname;
		lastname = new char[strlen(_lastname) + 1];
		_if_for_construstot(lastname, _lastname);
	}
}

char* Contact :: set_homephone() {
	return homephone;
}

void Contact :: get_homephone(char* _homephone) {
	if (_homephone && homephone) {
		//delete[] homephone;
		homephone = new char[strlen(_homephone) + 1];
		_if_for_construstot(homephone, _homephone);
	}
}

char* Contact :: set_workphone() {
	return workphone;
}

void Contact :: get_workphone(char* _workphone) {
	if (_workphone && workphone) {
		//delete[] workphone;
		workphone = new char[strlen(_workphone) + 1];
		_if_for_construstot(workphone, _workphone);
	}
}

char* Contact :: set_mobilephone() {
	return mobilephone;
}

void Contact :: get_mobilephone(char* _mobilephone) {
	if (_mobilephone && mobilephone) {
		//delete[] mobilephone;
		mobilephone = new char[strlen(_mobilephone) + 1];
		_if_for_construstot(mobilephone, _mobilephone);
	}
}

char* Contact :: set_info() {
	return info;
}

void Contact :: get_info(char* _info) {
	if (_info && info) {
		//delete[] info;
		info = new char[strlen(_info) + 1];
		_if_for_construstot(info, _info);
	}
}

string Contact::to_string()
{
	string s = "";
	s.append(name);
	s.append("\n");
	s.append(lastname);
	s.append("\n");
	s.append(homephone);
	s.append("\n");
	s.append(workphone);
	s.append("\n");
	s.append(mobilephone);
	s.append("\n");
	s.append(info);
	s.append("\n");
	s.append("---------------");
	s.append("\n");
	return s;
}

Contact::~Contact()
{
	if (this->name) {
		delete[] name;
	}
	if (this->lastname) {
		delete[] lastname;
	}
	if (this->homephone) {
		delete[] homephone;
	}
	if (this->workphone) {
		delete[] workphone;
	}
	if (this->mobilephone) {
		delete[] mobilephone;
	}
	if (this->info) {
		delete[] info;
		cout << "диструктор контакт сработал" << this << endl;
	}
}
	

