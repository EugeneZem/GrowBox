#pragma once
// Quasi Arduino pre Alpha
// by slayer0007@mail.ru
// Место написания скетча

#include <iostream>
#include <windows.h>
#include "Menu\Menu.h"
#include "Menu\Config.h"
#include "GrowBox.h"
#include "IODevices\QuasiLCD.h"
#include "IODevices\QuasyEncoder.h"
#include "QuasiArduino\QuasiArduino.h"

static GrowBox GB;
static Menu GB_Menu(14);
static Quasi_LCD GB_LCD(NULL, 16, 2);
static QuasiEncoder GB_Encoder;
void(*f1)();

void setup()
{
//f1 = function1;
config_menu(&GB_Menu, f1);
GB_Menu.info();
}

void loop()
{
	GB_LCD.clear();
	GB_LCD.set_cursor(0, 0);
	GB_LCD.print(GB_Menu.display());

	//GB_Encoder.tick();
	//if (GB_Encoder.isLeft()) GB_LCD.print("<--");
	//else
	//	if (GB_Encoder.isPress()) GB_LCD.print("Pressed");
	//	else
	//		if (GB_Encoder.isRight()) GB_LCD.print("-->");
	//		else
	//		{
	//			GB_LCD.clear();
	//			GB_LCD.set_cursor(0, 0);
	//			GB_LCD.print("");
	//		}
	//delay(50);
}