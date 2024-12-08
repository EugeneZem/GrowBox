#pragma once

#include <windows.h>
#include "..\QuasiArduino\QuasiArduino.h"


class QuasiEncoder
{
	enum Keys { LEFT = 37, RIGHT = 39, PRESS = 40 };
	const int _memorization = 50;	// продолжительность запоминания нажатой клавиши
	const int _blocking = 250;		// продолжительность перерыва после предыдущего нажатия
	long int _lastTime = 0;
	int _key = 0;
	int _keyCodes[3] = { LEFT, RIGHT, PRESS };

public:
	void tick()
	{
		if ((millis() - _lastTime) > _blocking)
		{
			for (int i = 0; i < 3; ++i)
			{
				if (GetAsyncKeyState(_keyCodes[i]) & 0x8000)
				{
					_key = _keyCodes[i];
					_lastTime = millis();
				}
			}
		}
	}

	boolean isRight()
	{
		if (inTime() && _key == RIGHT)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	boolean isLeft()
	{
		if (inTime() && _key == LEFT)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	boolean isPress()
	{
		if (inTime() && _key == PRESS)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

protected:
	boolean inTime() const
	{
		if ((millis() - _lastTime) <= _memorization)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
};



// * 0 - нет взаимодействия с энкодером
// * 37 - нажата клавиша [<-], соответствует вращению энкодера влево
// * 39 - нажата клавиша [->], соответствует вращению энкодера вправо
// * 32 - нажата клавиша [Пробел], соответствует нажатию кнопки энкодера
int PressKey()
{
	int keyCode[3] = { 32, 37, 39 };
	for (int i = 0; i < 3; ++i)
	{
		if (GetAsyncKeyState(keyCode[i]) & 0x8000) return keyCode[i];
	}
	return 0;
}

