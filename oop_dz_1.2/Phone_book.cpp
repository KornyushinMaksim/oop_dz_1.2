#include "Phone_book.h"
#include "Contact.h"
#include "File_open.h"


void Phone_book::add_contact(Contact contact) {
	Contact* temp = new Contact[size + 1];
	for (int i = 0; i < size; i++) {
		temp[i].get_name(arr_contacts[i].set_name());
		temp[i].get_lastname(arr_contacts[i].set_lastname());
		temp[i].get_homephone(arr_contacts[i].set_homephone());
		temp[i].get_workphone(arr_contacts[i].set_workphone());
		temp[i].get_mobilephone(arr_contacts[i].set_mobilephone());
		temp[i].get_info(arr_contacts[i].set_info());
	}
	temp[size].get_name(contact.set_name());
	temp[size].get_lastname(contact.set_lastname());
	temp[size].get_homephone(contact.set_homephone());
	temp[size].get_workphone(contact.set_workphone());
	temp[size].get_mobilephone(contact.set_mobilephone());
	temp[size].get_info(contact.set_info());
	delete[] arr_contacts;
	arr_contacts = temp;
	size++;
}

//void Phone_book::add_contact(Contact contact)
//{
//	Contact* temp = new Contact[size + 1];
//	for (int i = 0; i < size; i++) {
//		temp[i] = arr_contacts[i];
//	}
//	temp[size] = contact;
//	delete[] arr_contacts;
//	arr_contacts = temp;
//	size++;
//}

void Phone_book::delete_contact(int num)
{
	Contact* temp = new Contact[size - 1];
	for (int i = 0; i < num - 1; i++) {
		temp[i].get_name(arr_contacts[i].set_name());
		temp[i].get_lastname(arr_contacts[i].set_lastname());
		temp[i].get_homephone(arr_contacts[i].set_homephone());
		temp[i].get_workphone(arr_contacts[i].set_workphone());
		temp[i].get_mobilephone(arr_contacts[i].set_mobilephone());
		temp[i].get_info(arr_contacts[i].set_info());
		//temp[i] = arr_contacts[i];
	}
	for (int i = num; i < size; i++) {
		temp[i - 1].get_name(arr_contacts[i].set_name());
		temp[i - 1].get_lastname(arr_contacts[i].set_lastname());
		temp[i - 1].get_homephone(arr_contacts[i].set_homephone());
		temp[i - 1].get_workphone(arr_contacts[i].set_workphone());
		temp[i - 1].get_mobilephone(arr_contacts[i].set_mobilephone());
		temp[i - 1].get_info(arr_contacts[i].set_info());
		//temp[i - 1] = arr_contacts[i];
	}
	delete[] arr_contacts;
	arr_contacts = temp;
	size--;
}

string Phone_book::search_contact(char* str)
{
	for (int i = 0; i < size; i++) {
		if (arr_contacts[i].set_name() == str || arr_contacts[i].set_lastname() == str) {
			string s = "Совпадений нет...";
			return s;
		}
		else {
			return arr_contacts[i].to_string();
		}
	}
}

string Phone_book::to_string_contacts()
{
	string s = "";
	for (int i = 0; i < size; i++) {
		s.append(arr_contacts[i].to_string());
		s.append("\n");
	}
	return s;
}

void Phone_book::save_to_file(string _path)
{
	path = _path;
	fstream fout;
	fout.open(path);
	if (fout.is_open()) {
		for (int i = 0; i < size; i++) {
			fout << arr_contacts[i].to_string();
		}
		cout << "file saved" << endl;
	}
	fout.close();
	system("pause");
}

Phone_book::~Phone_book()
{
	if (arr_contacts) {
		delete[] arr_contacts;
		cout << "delete phone_book: " << this << endl;
	}
}

