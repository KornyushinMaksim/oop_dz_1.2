#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include "Contact.h"
class Phone_book
{
private:
	Contact* arr_contacts;
	int size;
	string path = ("Save.txt");
public:
	Phone_book() {
		arr_contacts = nullptr;
		int size = 0;
		//cout << "конструктор по умолчанию книга: " << this << endl;
	}
	Phone_book(const Phone_book& other) {
		size = other.size;
		for (int i = 0; i < size; i++) {
			arr_contacts[i] = other.arr_contacts[i];
		}
		//cout << "конструктор копир книга: " << this << endl;
	}
	~Phone_book();

	void copy_contact(Contact& new_contact, Contact& this_contact);
	void add_contact(Contact contact);
	void delete_contact(int num);
	string search_contact(char* str);
	string to_string_contacts();
	void save_to_file(string _path);

};

