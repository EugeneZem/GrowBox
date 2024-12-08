// GrowMenu V 0.1 (Alfa)
// 28.11.2024 ����������� ��������� �� ���� ��� lcd ������ 16�2

#include <iostream>
#include <windows.h>
#include "Menu.h"
#include "..\GrowBox.h"
#include "..\IODevices\QuasiLCD.h"


void static config_menu(Menu* Menu, void(*f1)())
{
	Menu->new_item(0,  "GrowBox alfa    ", 0, 1);	//	��������� ������ TODO ������� ��������
	Menu->new_item(1,  "Setting         ", 2, 0);	//	���� � ����� ��������
	Menu->new_item(2,  "System time     ", 3, 255);	//	- ��������� ���������� �������
	Menu->new_item(3,  "Sunshine 1      ", 8, 4);	//	- ��������� ����������� 1
	Menu->new_item(4,  "S1 turn on time ", 5, 255);	//	--	��������� ������� ��������� ����������� 1
	Menu->new_item(5,  "S1 turn off time", 6, 255);	//	--	��������� ������� ���������� ����������� 1
	Menu->new_item(6,  "S1 light bright ", 7, 255);	// 	--	��������� ������������� �������� ����������� 1
	Menu->new_item(7,  "Apply for S1    ", 4, 3);	//	--	��������� � ���������
	Menu->new_item(8,  "Sunshine 2      ", 13, 9);	//	-	��������� ����������� 2
	Menu->new_item(9,  "S2 turn on time ", 10, 255);//	--	��������� ������� ��������� ����������� 2
	Menu->new_item(10, "S2 turn off time", 11, 255);//	--	��������� ������� ���������� ����������� 2
	Menu->new_item(11, "S2 light bright ", 12, 255);// 	--	��������� ������������� �������� ����������� 2
	Menu->new_item(12, "Apply for S2    ", 9, 8);	// 	--	����� �� �������� ����������� 2	
	Menu->new_item(13, "In work         ", 2, 0);	// 	-	����� �� ������ ��������
}

// All right reserved
// slayer0007@mail.ru