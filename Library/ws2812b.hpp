/// @file

#ifndef WS2812B_HPP
#define WS2812B_HPP

#include "hwlib.hpp"

class ws2812b {
private:
	hwlib::pin_out & ledstrip;
	std::array<std::array<uint8_t, 3>, 100> leds = {0};

public:
	/// \brief
	/// The constructor.
	/// \details
	/// This constructor requires the arduino pin the ledstrip is connected.
	ws2812b(hwlib::pin_out & ledstrip);
	
	/// \brief
	/// adds a led to the ledstrip
	/// \details
	/// This function adds a led to the array, requiring a rgb value, the index of the (starting) led and the amount of leds added.
	void addLed(uint8_t red, uint8_t blue, uint8_t green, int index, int amount = 1);
		
	void showLeds();
	
	void blink(int indexStart, int indexEnd, int interval, int iterations);
	
	void cycleRight(int indexStart, int indexEnd, int interval, int iterations);
	
	void cycleLeft(int indexStart, int indexEnd, int interval, int iterations);
};


#endif // WS2812B_HPP


