// GrowMenu V 0.1 (Alfa)
// 28.11.2024 ����������� ��������� �� ���� ��� lcd ������ 16�2

#include <iostream>
#include <windows.h>
#include "Menu.h"
#include "..\GrowBox.h"
#include "..\IODevices\QuasiLCD.h"


void static config_menu(Menu* Menu, void(*f1)())
{
	Menu->new_item(0, (char*)"GrowBox alfa    ", 0, 1);	//	��������� ������ TODO ������� ��������
	Menu->new_item(1, (char*)"Setting         ", 2, 0);	//	���� � ����� ��������
	Menu->new_item(2, (char*)"System time     ", 3, 255);	//	- ��������� ���������� �������
	Menu->new_item(3, (char*)"Sunshine 1      ", 8, 4);	//	- ��������� ����������� 1
	Menu->new_item(4, (char*)"S1 turn on time ", 5, 255);	//	--	��������� ������� ��������� ����������� 1
	Menu->new_item(5, (char*)"S1 turn off time", 6, 255);	//	--	��������� ������� ���������� ����������� 1
	Menu->new_item(6, (char*)"S1 light bright ", 7, 255);	// 	--	��������� ������������� �������� ����������� 1
	Menu->new_item(7, (char*)"Apply for S1    ", 4, 3);	//	--	��������� � ���������
	Menu->new_item(8, (char*)"Sunshine 2      ", 13, 9);	//	-	��������� ����������� 2
	Menu->new_item(9, (char*)"S2 turn on time ", 10, 255);//	--	��������� ������� ��������� ����������� 2
	Menu->new_item(10, (char*)"S2 turn off time", 11, 255);//	--	��������� ������� ���������� ����������� 2
	Menu->new_item(11, (char*)"S2 light bright ", 12, 255);// 	--	��������� ������������� �������� ����������� 2
	Menu->new_item(12, (char*)"Apply for S2    ", 9, 8);	// 	--	����� �� �������� ����������� 2	
	Menu->new_item(13, (char*)"In work         ", 2, 0);	// 	-	����� �� ������ ��������
}

void function1()
{

}

// All right reserved
// slayer0007@mail.ru