#include "ws2812b.hpp"

ws2812b::ws2812b(hwlib::target::pins pin):
	pin( pin )
	{}

void ws2812b::addLed(int red, int blue, int green, int index, int amount){
	
	for(int i = index; i < (index + amount); i++){
		leds[i][0] = {green};
		leds[i][1] = {red};
		leds[i][2] = {blue};
	}
	
}

void ws2812b::showLeds(){
		
        auto ledstrip = hwlib::target::pin_out( pin );

        hwlib::wait_us(10);
		
        for(int i = 0; i < 100; i++){
			for(int j = 0; j < 3; j++){
				for(int k = 7; k >= 0;k--){

					ledstrip.write(1);

					if(leds[i][j] & (0x01 << k)){
							for( volatile int l = 0; l < 3; l++){};
					}
					else{
							for( volatile int m = 0; m < 1; m++){};
					}


					ledstrip.write(0);

					for( volatile int n = 0; n < 1; n++){};
			
				}
			}
		}
		
}

void ws2812b::blink(int indexStart, int indexEnd, int interval, int iterations){
	//std::array<std::array<int, 3>, 5000> ledsCopy = leds;
	
	for(int i = 0; i < iterations; i++){
		for(int j = indexStart; j <= indexEnd; j++){
			
			hwlib::wait_ms( interval );
			
			leds[j][0] = 0;
			leds[j][0] = 0;
			leds[j][0] = 0;
			showLeds();
			
			hwlib::wait_ms( interval );
		}
	}
}

void ws2812b::cycleRight(int indexStart, int indexEnd, int interval, int iterations){
	
	hwlib::cout << '1' << '\n';
	showLeds();
	
	//std::array<std::array<int, 3>, 5000> ledsCopy = leds;
	
	for(int i = 0; i < iterations; i++){
		for(int j = indexStart; j <= indexEnd; j++){
			hwlib::wait_ms( interval );
			
			hwlib::cout << j << '\n';
			
			if(j == indexStart){
			//	addLed(leds[indexEnd[0]], leds[indexEnd[1], leds[indexEnd[2], j);
				leds[indexStart][0] = leds[indexEnd][0];
				leds[indexStart][1] = leds[indexEnd][1];
				leds[indexStart][2] = leds[indexEnd][2];
			}
			else{
			//	addLed(leds[j-1[0]], leds[j-1[1], leds[j-1[2], j);
				leds[j][0] = leds[j - 1][0];
				leds[j][1] = leds[j - 1][1];
				leds[j][2] = leds[j - 1][2];
			}
			
			showLeds();
		}
	}
	
	//leds = ledsCopy;
	
}
