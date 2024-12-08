#include "QuasiLCD.h"

Quasi_LCD::Quasi_LCD(int address, int col, int row) :_col(col), _row(row)
{
	std::string str(_col, ' ');
	_display.clear();
	for (int i = 0; i < _row; ++i)
	{
		_display.push_back(str);
	}
}

void Quasi_LCD::clear()
{
	std::string str(_col, ' ');
	_display.clear();
	for (int i = 0; i < _row; ++i)
	{
		_display.push_back(str);
	}
}

void Quasi_LCD::print(std::string text)
{
	int* length_print = new int;
	if (text.size() <= (_col - _col_cursor))
	{
		*length_print = text.size();
	}
	else
	{
		*length_print = _col - _col_cursor;
	}
	for (int i = 0; i < *length_print; ++i)
	{
		_display.at(_row_cursor).at(i + _col_cursor) = text.at(i);
	}
	draw();
	_col_cursor = _col_cursor + *length_print;
	if (_col_cursor > _col) _col_cursor = _col;
	delete length_print;
}

void Quasi_LCD::print(int value)
{
	std::string text = std::to_string(value);
	Quasi_LCD::print(text);
}

void Quasi_LCD::set_cursor(int col, int row)
{
	if (col >= 0 && col <= _col && row >= 0 && row <= _row)
	{
		_row_cursor = row;
		_col_cursor = col;
	}
}

void Quasi_LCD::draw()
{
	std::cout << char(201);
	for (int i = 0; i < _col + 2; ++i) std::cout << char(205);
	std::cout << char(187) << '\n';
	for (int i = 0; i < _row; ++i)
	{
		std::cout << char(186) << ' ';
		for (int j = 0; j < _col; ++j)
		{
			std::cout << _display.at(i).at(j);
		}
		std::cout << ' ' << char(186) << std::endl;
	}
	std::cout << char(200);
	for (int i = 0; i < _col + 2; ++i) std::cout << char(205);
	std::cout << char(188) << '\n';
}