#include "Menu.h"

Menu::Menu(int quantity_elements) : _quantity_elements(quantity_elements)
{
	Menu_item* new_Menu_items = new Menu_item;
	_Menu_items = new_Menu_items;
	for (int i = 0; i < _quantity_elements; ++i)
	{
		Menu_item pre_Menu_item(i, (char*)"0 <-chr[16]-> 16", 0, 0);
		_Menu_items[i] = pre_Menu_item;
	}
}

void Menu::new_item(int item, char* p_name, int next, int child)
{
//	info(item);

	Menu_item updates(item, p_name, next, child);
	_Menu_items[item] = updates;

//	info(item);
}

inline void Menu::new_item(int item, char* p_name, int next, void(*p_function)())
{
	Menu_item updates(item, p_name, next, p_function);
	_Menu_items[item] = updates;
}

void Menu::next()
{
	_active_element = _Menu_items[_active_element].get_next();
}

void Menu::children()
{
	if (_Menu_items[_active_element].get_child() != 255)
	{
		_active_element = _Menu_items[_active_element].get_child();
		return;
	}

	if (_Menu_items[_active_element].get_function())
	{
		void(*ptr_f)() = _Menu_items[_active_element].get_function();
		ptr_f();
	}
}

const char* Menu::display()
{
	return _Menu_items[_active_element].get_name();
}

void Menu::info()
{
	std::cout << "Menu include " << _quantity_elements << " elements\n";
	for (int i = 0; i < _quantity_elements; ++i)
	{
		std::cout << "# " << _Menu_items[i].get_number() << " ";
		std::cout << "pNext " << _Menu_items[i].get_next() << " ";
		std::cout << "pChld " << _Menu_items[i].get_child() << " ";
		std::cout << "pFnct " << _Menu_items[i].get_function() << " ";
		std::cout << "Name " << _Menu_items[i].get_name() << "\n";
	}
	system("pause");
}

void Menu::info(int item)
{
	std::cout << "Info for " << item << " element\n";
	std::cout << "# " << _Menu_items[item].get_number() << " ";
	std::cout << "Name " << _Menu_items[item].get_name() << " ";
	std::cout << "pNext " << _Menu_items[item].get_next() << " ";
	std::cout << "pChld " << _Menu_items[item].get_child() << " ";
	std::cout << "pFnct " << _Menu_items[item].get_function() << "\n";
	system("pause");
}


Menu::Menu_item::Menu_item()
	: _number(255), _name(new char[17]), _numb_next(255), _numb_child(255) { }

Menu::Menu_item::Menu_item(int number, char* p_name, int numb_next, int _numb_child)
	: _number(number), _name(p_name), _numb_next(numb_next), _numb_child(_numb_child) { }

Menu::Menu_item::Menu_item(int number, char* p_name, int numb_next, void(*p_function)())
	: _number(number), _name(p_name), _numb_next(numb_next), _numb_child(255)
{
	_p_function = p_function;
}