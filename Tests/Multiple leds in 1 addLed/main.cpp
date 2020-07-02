#include "ws2812b.hpp"
#include "hwlib.hpp"

int main(){
	
	auto leds = hwlib::target::pin_out( hwlib::target::pins::d7 );
	
	ws2812b ledstrip(leds);

	ledstrip.addLed(1, 0, 0, 0, 2);
	ledstrip.addLed(0, 1, 0, 2, 3);
	ledstrip.addLed(0, 0, 1, 5, 2);
	
	ledstrip.showLeds();
	
}
