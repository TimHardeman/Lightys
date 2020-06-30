/// @file

#ifndef WS2812B_HPP
#define WS2812B_HPP

#include "hwlib.hpp"

class ws2812b {
private:
	hwlib::pin_out & ledstrip;
	std::array<std::array<u_int8_t, 3>, 100> leds = {0};

public:
	/// \brief
	/// The constructor.
	/// \details
	/// This constructor requires the arduino pin the ledstrip is connected.
	ws2812b(hwlib::pin_out & ledstrip);
	
	/// \brief
	/// adds a led to the ledstrip
	/// \details
	/// 
	void addLed(u_int8_t red, u_int8_t blue, u_int8_t green, int index, int amount = 1);
		
	void showLeds();
	
	void blink(int indexStart, int indexEnd, int interval, int iterations);
	
	void cycleRight(int indexStart, int indexEnd, int interval, int iterations);
		
		

};


#endif // WS2812B_HPP


