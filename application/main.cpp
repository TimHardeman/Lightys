#include "ws2812b.hpp"
#include "hwlib.hpp"

int main(){
	
	auto leds = hwlib::target::pin_out( hwlib::target::pins::d7 );
	
	ws2812b ledstrip(leds);

	ledstrip.addLed(1, 0, 0, 0, 1);
	ledstrip.addLed(0, 1, 0, 1, 1);
	ledstrip.addLed(1, 1, 0, 2, 1);
	ledstrip.addLed(0, 0, 1, 3, 1);
	ledstrip.addLed(1, 0, 1, 4, 1);
	ledstrip.addLed(0, 1, 1, 5, 1);
	ledstrip.addLed(1, 1, 1, 6, 1);
	
	for(;;){
		ledstrip.cycleLeft(0, 6, 350, 7);
                ledstrip.cycleRight(0, 6, 350, 7);
                ledstrip.cycleLeft(0, 2, 350, 3);
                ledstrip.cycleRight(4, 6, 350, 3);
                ledstrip.kittLeft(0, 2, 100, 3);
                ledstrip.kittRight(4, 6, 100, 3);
                ledstrip.kittLeft(0, 6, 100, 7);
                ledstrip.kittRight(0, 6, 100, 7);
                ledstrip.blink(0, 2, 350, 3);
                ledstrip.blink(4, 6, 350, 3);
                ledstrip.blink(0, 7, 350, 7);		
	}
}
