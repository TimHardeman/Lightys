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
		
	/// \brief
	/// Shows the currently added leds on the ledstrip.
	/// \details
	/// This function takes the rgb values added to the ledstrip and writes it to the ledstrip.
	void showLeds();
	
	/// \brief
	/// The selected leds blink between the selected rgb value and off.
	/// \details
	/// This function takes the selected leds, alternating them between the selected rgb value and off.
	/// Interval controls the delay between blinks in ms, iterations controls how many times the blink is performed.
	void blink(int indexStart, int indexEnd, int interval, int iterations);
	
	/// \brief
	/// The selected leds cycle to the right.
	/// \details
	/// This function takes the selected leds, cycling them to the right.
	/// Interval controls the delay between cycles, and iterations control the amount of cycles.
	void cycleRight(int indexStart, int indexEnd, int interval, int iterations);
	
	/// \brief
	/// The selected leds cycle to the left.
	/// \details
	/// This function takes the selected leds, cycling them to the left.
	/// Interval controls the delay between cycles, and iterations control the amount of cycles.
	void cycleLeft(int indexStart, int indexEnd, int interval, int iterations);
	
	/// \brief
	/// The selected leds kitt from left to right.
	/// \details
	/// This function takes the selected leds, kitting them from left to right.
	/// Interval controls the delay between the kitts, and iterations controls the amount of kitts.
	void kittRight(int indexStart, int indexEnd, int interval, int iterations);
	
	/// \brief
	/// The selected leds kitt from right to left.
	/// \details
	/// This function takes the selected leds, kitting them from right to left.
	/// Interval controls the delay between the kitts, and iterations controls the amount of kitts.
	void kittLeft(int indexStart, int indexEnd, int interval, int iterations);
};


#endif // WS2812B_HPP


