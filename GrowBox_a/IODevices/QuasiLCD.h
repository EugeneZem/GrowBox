/*
* �������� LCD-������ ��� ���������� � ������� �������� �� ��������� Arduino
* V1.0

* init();								�������������
* setCursor(uint8_t col, uint8_t row);	��������� ������� � �������
* print(char*);							����� �� LCD ������ ��������
* write(char);							����� �� LCD ������ �������
* clear()								������� ������ � ������� ������� � ��������� �������;
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
	const int _col;								// ������ ������ LCD-������
	const int _row;								// ���������� �����	LCD-������
	int _col_cursor = 0;						// ������� ������� � ������
	int _row_cursor = 0;						// ������� ������� ����� �����
	std::vector<std::string> _display;			// ������������ ���������� �� LCD-������
public:
	Quasi_LCD(int adress, int col, int row);	// address - "��������" 
	void clear();								// ������� ����� �����������
	void print(std::string text);				// ����� �� ����� ������ � �������� ��������� �������
	void print(int value);						// ����� �� ����� ����� � �������� ��������� �������
	void set_cursor(int col, int row);			// ��������� ������� � ������� col, row
private:
	void draw();
};