#include "GrowBox.h"

//  -- system time --
void GrowBox::set_system_time(char hour, char minute)
{
	_system_time.set_hour(hour);
	_system_time.set_minute(minute);
}

Time GrowBox::get_system_time()
{
	return _system_time;
}

//  -- lighting1 --
void GrowBox::set_time_on_lighting1(char hour, char minute)
{
	_time_on_lighting1.set_hour(hour);
	_time_on_lighting1.set_minute(minute);
}

Time GrowBox::get_time_on_lighting1()
{
	return _time_on_lighting1;
}

void GrowBox::set_time_off_lighting1(char hour, char minute)
{
	_time_off_lighting1.set_hour(hour);
	_time_off_lighting1.set_minute(minute);
}

Time GrowBox::get_time_off_lighting1()
{
	return _time_off_lighting1;
}

void GrowBox::set_brightness_lighting1(char brightness)
{
	_brightness_lighting1 = brightness;
}

char GrowBox::get_brightness_lighting1()
{
	return _brightness_lighting1;
}
//  -- lighting2 --
void GrowBox::set_time_on_lighting2(char hour, char minute)
{
	_time_on_lighting2.set_hour(hour);
	_time_on_lighting2.set_minute(minute);
}

Time GrowBox::get_time_on_lighting2()
{
	return _time_on_lighting2;
}

void GrowBox::set_time_off_lighting2(char hour, char minute)
{
	_time_off_lighting2.set_hour(hour);
	_time_off_lighting2.set_minute(minute);
}

Time GrowBox::get_time_off_lighting2()
{
	return _time_off_lighting2;
}

void GrowBox::set_brightness_lighting2(char brightness)
{
	_brightness_lighting2 = brightness;
}

char GrowBox::get_brightness_lighting2()
{
	return _brightness_lighting2;
}

GrowBox::GrowBox()
{
#ifdef DEBUG_MODE 
	std::cout << "GrowBox DEBUG MODE" << std::endl;

#endif

	_system_time.set_hour(12);
	_system_time.set_minute(30);

	_time_on_lighting1.set_hour(13);
	_time_on_lighting1.set_minute(30);
	_time_off_lighting1.set_hour(13);
	_time_off_lighting1.set_minute(40);
	_brightness_lighting1 = 100;

	_time_on_lighting2.set_hour(14);
	_time_on_lighting2.set_minute(30);
	_time_off_lighting2.set_hour(14);
	_time_off_lighting2.set_minute(40);
	_brightness_lighting2 = 100;
}

void Time::set_hour(char hour)
{
	_hour = hour;
}

void Time::set_minute(char minute)
{
	_minute = minute;
}

char Time::get_hour()
{
	return _hour;
}


char Time::get_minute()
{
	return _minute;
}
