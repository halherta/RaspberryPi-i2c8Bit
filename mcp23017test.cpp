/*********************************************************************
 * Main function that demos the use of the i2c8Bit class for use with
 * the MCP23017 chip
 * *******************************************************************/

#include "i2c8Bit.h"
#include <iostream>
using namespace std;

int main(void)
{
	int i = 0;
	unsigned char pinStatus = 0;
	unsigned char outToggleState = 0;
	i2c8Bit mcp23017(0b00100000,string("/dev/i2c-1"));
	//instantiate i2c8Bit object called mcp23017
	//specify a device address 0x20 and i2c device "/dev/i2c-1" 
	mcp23017.writeReg(0b00,0b11111110); 
        // write data value 0b11111110 into register 00 (IODIRA) 
        // makes GPA0 output, rest of the pins  (GPA1-7) inputs
	
	while(i < 20) // repeat the following 20 times and then exit;
	{
		mcp23017.readReg(0x12,pinStatus); 
		//read the GPIOA register
             
		if( (pinStatus & 0b10000000) == 0){ 
		// test to see if pin GPA7 is equal to zero
		// i.e. if pushbutton is pressed
			cout << "PushButton pressed..toggling LED" << endl;
			outToggleState ^= 1;
                        //update vatiable to cause LED to toggle
		}
		else
			cout << "Pushbutton not pressed...LED static" << endl;
			
		sleep(1);
		mcp23017.writeReg(0x14,outToggleState);
                //right the value of outToggleState to the OLATA register
                i++;
                cout << i << " LED state is: "<< (int)outToggleState << endl;
	}
	cout << "exiting" << endl;
//destructor called just before program exit
return 0;			
}
				
		
		
	
	
	
	
	

