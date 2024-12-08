/*
* Эмулятор LCD-экрана для разработки и отладки проектов на платформе Arduino
* V1.0

* init();								Инициализация
* setCursor(uint8_t col, uint8_t row);	Установка курсора в позицию
* print(char*);							Вывод на LCD строки символов
* write(char);							Вывод на LCD одного символа
* clear()								Очистка экрана и возврат курсора в начальную позицию;
*
* #include <LiquidCrystal_I2C.h>
*
* LiquidCrystal_I2C lcd(0x27,20,4);  // set the LCD address to 0x27 for a 16 chars and 2 line display
*
* void setup()
* {
*	// initialize the lcd
*   lcd.init();
*   // Print a message to the LCD.
*   lcd.backlight();
*   lcd.setCursor(3,0);
*   lcd.print("Hello, world!");
*   lcd.setCursor(2,1);
*   lcd.print("I robot Arduino!");
*   lcd.setCursor(0,2);
*   lcd.print("Arduino LCM IIC 2004");
*   lcd.setCursor(2,3);
*   lcd.print("Power By Ec-yuan!");
* }
*/
#pragma once

#include <iostream>
#include <string>
#include <vector>

class Quasi_LCD
{
	const int _col;								// размер строки LCD-экрана
	const int _row;								// количество строк	LCD-экрана
	int _col_cursor = 0;						// позиция курсора в строке
	int _row_cursor = 0;						// позиция курсора среди строк
	std::vector<std::string> _display;			// отображаемая информация на LCD-экране
public:
	Quasi_LCD(int adress, int col, int row);	// address - "заглушен" 
	void clear();								// очистка всего содержимого
	void print(std::string text);				// вывод на экран текста с текущего положения курсора
	void print(int value);						// вывод на экран числа с текущего положения курсора
	void set_cursor(int col, int row);			// установка курсора в позицию col, row
private:
	void draw();
};