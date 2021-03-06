#include "ws2812b.hpp"

ws2812b::ws2812b(hwlib::pin_out & ledstrip):
	ledstrip( ledstrip )
	{}

void ws2812b::addLed(uint8_t red, uint8_t green, uint8_t blue, int index, int amount){
	
	hwlib::wait_us(10);
	
	for(int i = index; i < (index + amount); i++){
		leds[i][0] = {green};
		leds[i][1] = {red};
		leds[i][2] = {blue};
	}
	
}

void ws2812b::showLeds(){
		
        hwlib::wait_us(10);
		
        for(int i = 0; i < 100; i++){
			
			for(int j = 0; j < 3; j++){
				
				for(int k = 7; k >= 0;k--){
					
					ledstrip.write(1);
					
					if(leds[i][j] & (0x01 << k)){for( volatile int l = 0; l < 1; l++){};}

					ledstrip.write(0);

					for( volatile int n = 0; n < 1; n++){};
			
				}
			}
		}
}

void ws2812b::blink(int indexStart, int indexEnd, int interval, int iterations){
	
	std::array<std::array<uint8_t, 3>, 1000> ledsCopy = leds;
	
	for(int i = 0; i < iterations; i++){
		
		hwlib::wait_ms( interval );
		
		for(int j = indexStart; j <= indexEnd; j++){
			leds[j][0] = 0;
			leds[j][1] = 0;
			leds[j][2] = 0;
		}
		showLeds();
		
		hwlib::wait_ms( interval );
		
		for(int k = indexStart; k <= indexEnd; k++){
			leds[k][0] = ledsCopy[k][0];
			leds[k][1] = ledsCopy[k][1];
			leds[k][2] = ledsCopy[k][2];
		}
		showLeds();
	}
}

void ws2812b::cycleRight(int indexStart, int indexEnd, int interval, int iterations){
	
	std::array<std::array<uint8_t, 3>, 1000> ledsCopy = leds;
	
	for(int i = 0; i < iterations; i++){
		
		hwlib::wait_ms( interval );
		
		for(int j = indexStart; j <= indexEnd; j++){

			if(j == indexStart){
				leds[indexStart][0] = ledsCopy[indexEnd][0];
				leds[indexStart][1] = ledsCopy[indexEnd][1];
				leds[indexStart][2] = ledsCopy[indexEnd][2];
			}
			else{
				leds[j][0] = ledsCopy[j - 1][0];
				leds[j][1] = ledsCopy[j - 1][1];
				leds[j][2] = ledsCopy[j - 1][2];
			}
		}
		showLeds();
		ledsCopy = leds;
	}
}

void ws2812b::cycleLeft(int indexStart, int indexEnd, int interval, int iterations){
	
	std::array<std::array<uint8_t, 3>, 1000> ledsCopy = leds;
	
	for(int i = 0; i < iterations; i++){
		
		hwlib::wait_ms( interval );
		
		for(int j = indexEnd; j >= indexStart; j--){

			if(j == indexEnd){
				leds[indexEnd][0] = ledsCopy[indexStart][0];
				leds[indexEnd][1] = ledsCopy[indexStart][1];
				leds[indexEnd][2] = ledsCopy[indexStart][2];
			}
			else{
				leds[j][0] = ledsCopy[j + 1][0];
				leds[j][1] = ledsCopy[j + 1][1];
				leds[j][2] = ledsCopy[j + 1][2];
			}
		}
		showLeds();
		ledsCopy = leds;
	}
}

void ws2812b::kittRight(int indexStart, int indexEnd, int interval, int iterations){
	
	std::array<std::array<uint8_t, 3>, 1000> ledsCopy = leds;
	
	for(int i = 0; i < iterations; i++){
		for(int j = indexStart; j <= indexEnd; j++){
			
			hwlib::wait_ms( interval );
			
			for(int k = indexStart; k <= indexEnd; k++){
			
				if(j == k){
					leds[k][0] = ledsCopy[k][0];
					leds[k][1] = ledsCopy[k][1];
					leds[k][2] = ledsCopy[k][2];
				}
				else{
					leds[k][0] = 0;
					leds[k][1] = 0;
					leds[k][2] = 0;
				}
			}
		showLeds();
		}
	}
	leds = ledsCopy;
	
	hwlib::wait_us( 10 );
	
	showLeds();
}

void ws2812b::kittLeft(int indexStart, int indexEnd, int interval, int iterations){
	
	std::array<std::array<uint8_t, 3>, 1000> ledsCopy = leds;
	
	for(int i = 0; i < iterations; i++){
		for(int j = indexEnd; j >= indexStart; j--){
			
			hwlib::wait_ms( interval );
			
			for(int k = indexStart; k <= indexEnd; k++){
			
				if(j == k){
					leds[k][0] = ledsCopy[k][0];
					leds[k][1] = ledsCopy[k][1];
					leds[k][2] = ledsCopy[k][2];
				}
				else{
					leds[k][0] = 0;
					leds[k][1] = 0;
					leds[k][2] = 0;
				}
			}
		showLeds();
		}
	}
	leds = ledsCopy;
	
	hwlib::wait_us( 10 );
	
	showLeds();
}
