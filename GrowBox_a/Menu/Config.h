// GrowMenu V 0.1 (Alfa)
// 28.11.2024 Реализована навигация по меню для lcd экрана 16х2

#include <iostream>
#include <windows.h>
#include "Menu.h"
#include "..\GrowBox.h"
#include "..\IODevices\QuasiLCD.h"


void static config_menu(Menu* Menu, void(*f1)())
{
	Menu->new_item(0,  "GrowBox alfa    ", 0, 1);	//	индикатор работы TODO СДЕЛАТЬ ФУНКЦИЕЙ
	Menu->new_item(1,  "Setting         ", 2, 0);	//	вход в режим настроек
	Menu->new_item(2,  "System time     ", 3, 255);	//	- настройка системного времени
	Menu->new_item(3,  "Sunshine 1      ", 8, 4);	//	- настройка светильника 1
	Menu->new_item(4,  "S1 turn on time ", 5, 255);	//	--	настройка времени включения светильника 1
	Menu->new_item(5,  "S1 turn off time", 6, 255);	//	--	настройка времени отключения светильника 1
	Menu->new_item(6,  "S1 light bright ", 7, 255);	// 	--	настройка интенсивности свечения светильника 1
	Menu->new_item(7,  "Apply for S1    ", 4, 3);	//	--	применить и вернуться
	Menu->new_item(8,  "Sunshine 2      ", 13, 9);	//	-	настройка светильника 2
	Menu->new_item(9,  "S2 turn on time ", 10, 255);//	--	настройка времени включения светильника 2
	Menu->new_item(10, "S2 turn off time", 11, 255);//	--	настройка времени отключения светильника 2
	Menu->new_item(11, "S2 light bright ", 12, 255);// 	--	настройка интенсивности свечения светильника 2
	Menu->new_item(12, "Apply for S2    ", 9, 8);	// 	--	выход из настроек светильника 2	
	Menu->new_item(13, "In work         ", 2, 0);	// 	-	выход из режима настроек
}

// All right reserved
// slayer0007@mail.ru