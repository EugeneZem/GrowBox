#pragma once

#include <iostream>

struct Time
{
	char _hour;
	char _minute;
public:
	void set_hour(char hour);
	void set_minute(char minute);
	char get_hour();
	char get_minute();
};

class GrowBox
{
	Time _system_time;

	Time _time_on_lighting1;
	Time _time_off_lighting1;
	char _brightness_lighting1;

	Time _time_on_lighting2;
	Time _time_off_lighting2;
	char _brightness_lighting2;

public:
	GrowBox();
	void set_system_time(char hour, char minute);
	Time get_system_time();

	void set_time_on_lighting1(char hour, char minute);
	Time get_time_on_lighting1();
	void set_time_off_lighting1(char hour, char minute);
	Time get_time_off_lighting1();
	void set_brightness_lighting1(char brightness);
	char get_brightness_lighting1();

	void set_time_on_lighting2(char hour, char minute);
	Time get_time_on_lighting2();
	void set_time_off_lighting2(char hour, char minute);
	Time get_time_off_lighting2();
	void set_brightness_lighting2(char brightness);
	char get_brightness_lighting2();
};

