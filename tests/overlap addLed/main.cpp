#include "ws2812b.hpp"
#include "hwlib.hpp"

int main(){
	
	auto leds = hwlib::target::pin_out( hwlib::target::pins::d7 );
	
	ws2812b ledstrip(leds);

	ledstrip.addLed(5, 0, 0, 0);
	ledstrip.addLed(0, 5, 0, 0);
	
	ledstrip.showLeds();
	
}
