// GrowBox V 0.1 alpha
// Использован фреймворк Quasi Arduino (pre Alpha)
// by slayer0007@mail.ru

#include <iostream>
#include <windows.h>
#include "sketch.ino.h"

int main(int argc, char** argv)
{

	setup();
	while (1)
	{
		std::cout << "The sketch is begin tested\non a Quasi Arduino (Alpha)\n     from Slayer0007\n\n";
		loop();
		system("CLS");
	}
}