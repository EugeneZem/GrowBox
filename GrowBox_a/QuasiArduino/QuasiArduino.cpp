#include <iostream>
#include <chrono>
#include <windows.h>
#include "QuasiArduino.h"

/*-------------------------- Инициализация --------------------------*/
unsigned long  _start_time = _current_time();

/*------------------ Функции из библиотеки Arduino ------------------*/
long int millis()
{
	return _current_time() - _start_time;
}

void delay(unsigned int time)
{
	Sleep(time);
}

/*------------------------ Служебные функции ------------------------*/
unsigned long _current_time()
{
	auto now = std::chrono::system_clock::now();
	auto duration = now.time_since_epoch();
	return std::chrono::duration_cast<std::chrono::milliseconds>(duration).count();
}