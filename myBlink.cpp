// This program takes one of the following mode commands: on, off, flash, status, or blink
// If blink, pass the number of LED you want to flash, and the number of times to flash it.
//
// Example invocation:
//
// ./myBlink blink 3 2
// blinks LED 3 twice

#include "derek_LED.h"
#include <iostream>
using namespace std;

int main(int argc, char* argv[]){
   if(argc!=2 & argc!=4){
        cout << "Usage is makeLEDs <command>" << endl;
        cout << "   command is one of: on, off, flash or status" << endl;
        cout << " e.g. myBlink flash" << endl;
	cout << " or" << endl;
        cout << " myBlink blink 3 2" << endl;
   }
   
   cout << "Starting the makeLEDs program" << endl;
   string cmd(argv[1]);
   LED leds[4] = { LED(0), LED(1), LED(2), LED(3) };

   if(cmd=="blink"){
	cout << "Blinking LED " << argv[2] << " " << argv[3] << " times." << endl;
	int led = stoi(argv[2]);
	leds[led].blink(stoi(argv[3]));
   }
   else{
	for(int i=0; i<=3; i++){
	   if(cmd=="on")leds[i].turnOn();
	   else if(cmd=="off")leds[i].turnOff();
	   else if(cmd=="flash")leds[i].flash("100"); //default is "50"
	   else if(cmd=="status")leds[i].outputState();
	   else{ cout << "Invalid command!" << endl; }
   	}
   }
   cout << "Finished the makeLEDs program" << endl;
   return 0;
}
