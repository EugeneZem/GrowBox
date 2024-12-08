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
	void new_item(const int item, const char* p_name, const int next, const int child);
	void new_item(const int item, const char* p_name, const int next, void(*p_function)());

	void rebild();

	void next();
	void children();

	const char* display();

	void info();
	void info(int item);

private:
	class Menu_item
	{
		const char _number;				// Номер позиции меню
		const char* _name;				// Наименование позиции меню
		const char _numb_next;			// Номер следующей позиции меню
		const char _numb_child;			// Номер подчиненной позиции меню
		void(*_p_function)() = nullptr;	// Указатель на вызываемую функцию
	public:
		Menu_item();
		Menu_item(const int number, const char* p_name, const int numb_next, const int _numb_child);
		Menu_item(const int number, const char* p_name, const int numb_next, void(*_p_function)());
		Menu_item(Menu_item& over) = delete;
		Menu_item& operator = ( Menu_item& rhs) { return rhs; }
		Menu_item(Menu_item&& over) = delete;

		//Menu_item operator = (Menu_item& rhs) { return rhs; }

		const int get_number() { return _number; }
		const char* get_name() { return _name; }
		const int get_next() const { return _numb_next; }
		const int get_child() const { return _numb_child; }
		void(*get_function())() { return _p_function; }
	};
};
