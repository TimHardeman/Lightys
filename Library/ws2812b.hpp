/// @file

#ifndef WS2812B_HPP
#define WS2812B_HPP

#include "hwlib.hpp"

class ws2812b {
private:
	hwlib::target::pins pin;
	std::array<std::array<int, 3>, 5000> leds = {0};

public:
	/// \brief
	/// The constructor.
	/// \details
	/// This constructor requires the arduino pin the ledstrip is connected.
	ws2812b(hwlib::target::pins pin);
	
	/// \brief
	/// adds a led to the ledstrip
	/// \details
	/// 
	void addLed(int red, int blue, int green, int index, int amount = 1);
		
	void showLeds();
	
	void cycleRight(int indexStart, int indexEnd, int interval, int iterations);
		
		

};


#endif // WS2812B_HPP


