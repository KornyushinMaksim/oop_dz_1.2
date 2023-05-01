//	Задание.
//	Создайте приложение "Телефонная книга".Необходимо
//	хранить данные об абоненте(ФИО, домашний телефон,
//	рабочий телефон, мобильный телефон, дополнительная
//	информация о контакте) внутри соответствующего клас -
//	са.Наполните класс переменными - членами, функция -
//	ми - членами, конструкторами, inline - функциями - членами,
//	используйте инициализаторы, реализуйте деструктор.
//	Обязательно необходимо выделять динамически память
//	под ФИО.Предоставьте пользователю возможность до -
//	бавлять новых абонентов, удалять абонентов, искать або -
//	нентов по ФИО, показывать всех абонентов, сохранять
//	информацию в файл и загружать из файла.


#include <iostream>
#include <string.h>
#include "Contact.h"
#include "Phone_book.h"
#include "File_open.h"

Contact func_add_contact() {
	char name[30];
	char lastname[30];
	char homephone[12];
	char workphone[12];
	char mobilephone[12];
	char info[100];
	cin.get();			//bag
	cout << "Добавление контакта\nИмя: ";
	cin.getline(name, 30);
	cout << "Фамилия: ";
	cin.getline(lastname, 30);
	cout << "Домашний телефон: ";
	cin.getline(homephone, 12);
	cout << "Рабочий телефон: ";
	cin.getline(workphone, 12);
	cout << "Мобильный телефон: ";
	cin.getline(mobilephone, 12);
	cout << "Инфо: ";
	cin.getline(info, 100);
	return Contact(name, lastname, homephone, workphone, mobilephone, info);
	
}

int func_delete_contact() {
	cout << "Выберите номер для удаления: ";
	int num;
	cin >> num;
	return num;
}

char* func_search_contact() {
	bool flag = true;
	char str[] = { "выход" };
	while (flag) {
		cout << "Введите имя/фамилию для поиска или \"выход\": ";
		char search[30];
		cin.get();
		cin.getline(search, 30);
		if (strstr(str, search)) {
			flag = false;
		}
		else {
			return search;
		}
	}
}

//Contact read_file() {
//	File_open open;
//	return open.open_file("Save.txt");
//}

void _interface(Phone_book& pers) {
	//cont.add_contact(open.open_file("Save.txt"));
	//Phone_book cont_copy(pers);
	//Phone_book pers;
	//Contact cont;
	//cont_copy.add_contact(cont);
	bool flag = true;
	while (flag) {
		//system("cls");
		cout << "1. Добавление контакта\n2. Удалить\n3. Показать всех\n4. Поиск\n5. Сохранить\n6. Завершить\n";
		int key;
		cin >> key;
		switch (key) {
		case 1:
			pers.add_contact(func_add_contact());
			break;
		case 2:
			pers.delete_contact(func_delete_contact());
			break;
		case 3:
			cout << pers.to_string_contacts();
			system("pause");
			break;
		case 4:
			cout << pers.search_contact(func_search_contact()/*, pers*/) << endl;
			break;
		case 5:
			pers.save_to_file("Save.txt");
			break;
		case 6:
			flag = false;
			break;
		}
	}
}

int main()
{
	system("chcp 1251 >nul");
	//Contact cont;
	////Contact(pers);
	Phone_book pers;
	File_open open("Save.txt");
	open.open_file();
	
	_interface(pers);
}