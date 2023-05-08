#include "Phone_book.h"
#include "Contact.h"
#include "File_open.h"
using namespace std;


void Phone_book::copy_contact(Contact& new_contact, Contact& this_contact)
{
	new_contact.get_name(this_contact.set_name());
	new_contact.get_lastname(this_contact.set_lastname());
	new_contact.get_homephone(this_contact.set_homephone());
	new_contact.get_workphone(this_contact.set_workphone());
	new_contact.get_mobilephone(this_contact.set_mobilephone());
	new_contact.get_info(this_contact.set_info());
}


void Phone_book::add_contact(Contact contact) {
	Contact* temp = new Contact[size + 1];
	for (int i = 0; i < size; i++) {
		copy_contact(temp[i], arr_contacts[i]);
	}
	copy_contact(temp[size], contact);
	delete[] arr_contacts;
	arr_contacts = temp;
	size++;
}

void Phone_book::delete_contact(int num)
{
	Contact* temp = new Contact[size - 1];
	for (int i = 0, j = 0; i < size - 1; i++, j++) {
		if (i != num - 1) {
			copy_contact(temp[i], arr_contacts[j]);
		}
		else {
			copy_contact(temp[i], arr_contacts[++j]);
		}
	}
	delete[] arr_contacts;
	arr_contacts = temp;
	size--;
}

string Phone_book::search_contact(char* str)
{
	int counter_size = 0;
	Phone_book* temp = new Phone_book();
	for (int i = 0; i < size; i++) {
		if (string(arr_contacts[i].set_name()) == str || string(arr_contacts[i].set_lastname()) == str) {
			temp->add_contact(arr_contacts[i]);
			counter_size++;
		}
	}
	if (counter_size == 0) {
		string s = "Совпадений нет...";
		return s;
	}
	else {
		return temp->to_string_contacts();
	}
}

string Phone_book::to_string_contacts()
{
	string s = "";
	for (int i = 0; i < size; i++) {
		s.append(arr_contacts[i].to_string());
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

