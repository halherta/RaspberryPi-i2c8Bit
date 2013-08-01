RaspberryPi-i2c8Bit
===================

Author: Hussam Al-Hertani

Description: The i2c8Bit  C++ class enables the Raspberry Pi to communicate with the MCP23017 I2C GPIO expander via i2c-dev. The class can be used to communicate with other I2C devices with minimum modifications.

========================================================================================================

For more information please visit: http://hertaville.com/2013/04/01/interfacing-an-i2c-gpio-expander-mcp23017-to-the-raspberry-pi-using-c/

========================================================================================================

To build the example natively on the Raspberry Pi:

g++ -fpermissive -Wall i2c8Bit.cpp mcp23017test.cpp -o outBin1

Make sure that the i2c8Bit.h header file is in the work directory.
