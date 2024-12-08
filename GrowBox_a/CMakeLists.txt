add_executable (GrowBox_a	# Quasi Arduino
							"main.cpp"
							"QuasiArduino/QuasiArduino.h" "QuasiArduino/QuasiArduino.cpp"  
							# IO Devices
							"IODevices/QuasiLCD.cpp" "IODevices/QuasiLCD.h"
							"IODevices/QuasyEncoder.h"
							# Скетч
							"sketch.ino.h"
							"GrowBox.h" "GrowBox.cpp"
							"Menu/Menu.h" "Menu/Menu.cpp"
							# Конфигурация 
							"Menu/Config.h")

							

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET GrowBox_a PROPERTY CXX_STANDARD 20)
endif()