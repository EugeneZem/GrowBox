#pragma once

#include <windows.h>
#include <iostream>
#include "Menu.h"
#include "..\GrowBox.h"

class Menu
{
	class Menu_item;
	Menu_item* _Menu_items = nullptr;
	int _active_element = 0;
	const int _quantity_elements;

public:
	Menu(const int quantity_elements);

	/*
	Настройка элементов меню
	item  - номер настраиваемого элемента меню
	name  - наименование пункта меню
	next  - номер следующего элемента меню (если следующего элемента не предусмотрено, указывается item)
	child - номер подчиненного элемента меню (если подчиненного элемента не предусмотрено, указывается item)
	p_function - указатель на вызываемую функцию void function()
	*/
	void new_item(int item, char* p_name, int next, int child);
	void new_item(int item, char* p_name, int next, void(*p_function)());

//	void rebild();

	void next();
	void children();

	const char* display();

	void info();
	void info(int item);

private:
	class Menu_item
	{
		int _number;		// Номер позиции меню
		char* _name;		// Наименование позиции меню
		int _numb_next;		// Номер следующей позиции меню
		int _numb_child;	// Номер подчиненной позиции меню
		void(*_p_function)() = nullptr;	// Указатель на вызываемую функцию
	public:
		Menu_item();
		Menu_item(int number, char* p_name, int numb_next, int _numb_child);
		Menu_item(int number, char* p_name, int numb_next, void(*_p_function)());
		Menu_item(Menu_item& over) = delete;
		Menu_item& operator = ( const Menu_item& rhs)
		{
			if (&rhs != this)
			{
				_number = rhs._number;
				_name = rhs._name;
				_numb_next = rhs._numb_next;
				_numb_child = rhs._numb_child;
			}
			return *this;

		}
		Menu_item(Menu_item&& over) = delete;

		//Menu_item operator = (Menu_item& rhs) { return rhs; }

		int get_number() { return _number; }
		char* get_name() { return _name; }
		int get_next() const { return _numb_next; }
		int get_child() const { return _numb_child; }
		void(*get_function())() { return _p_function; }
	};
};
