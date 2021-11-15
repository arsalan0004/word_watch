
#ifndef HOUR_FUNCTIONS 

#define HOUR_FUNCTIONS
/**
 * set all output pins of the MCP23008 I/O expander to 0
 **/
void MCP23008_reset_all_pins();

/*
 * sets the MCP23008 pins specificed by the byte inputted.
 * Because this function 'touches' every bit in the GPIO register, you don't 
 * always need to manually set pins low.
 *
 * example: input byte: 00000001 sets pin 0, and clears pins 7-1.
 * input byte: 00000010 sets pin 0 low (along with pins 7-2) but sets pin 1
 * 
 *@param input = the bitmask representing which pins to set as input/output
*/
void MCP23008_set(uint8_t input)

/**
 *sets all hour pins to input (high impedence mode);
 **/
void set_HourPins_INPUT();


/**
 *sets the ith pin associated with 'one' on the board to 1. Note that i rolls
 *over. For example:
 *   i = 0 : turn on 'o'
 *   i = 1 : turn on 'n'
 *   i = 2 : turn on 'e'
 *   i = 3 : turn on 'o'
 *   ....
 *@param i the ith pin associated with this word.
 **/
void one_hour(int i);


/**
 *sets the ith pin associated with 'two' on the board to 1. Note that i rolls
 *over. For example:
 *  i = 0 : turn on 't'
 *  i = 1 : turn on 'w'
 *  i = 2 : turn on 'o'
 *  i = 3 : turn on 't'
 *  ....
 *@param i the ith pin associated with this word.
 **/
void two_hour(int i);

/**
 *sets the ith pin associated with 'three' on the board to 1. Note that i rolls
 *over. For example:
 *   i = 0 : turn on 't'
 *   i = 1 : turn on 'h'
 *   i = 2 : turn on 'r'
 *   i = 3 : turn on 'e'
 *   i = 4 : turn on 'e'
 *   i = 5 : turn on 't'
 *   ....
 *@param i the ith pin associated with this word.
 **/
void three_hour(int i);


/**
 *sets the ith pin associated with 'four' on the board to 1. Note that i rolls
 *over. For example:
 *   i = 0 : turn on 'f'
 *   i = 1 : turn on 'o'
 *   i = 2 : turn on 'u'
 *   i = 3 : turn on 'r'
 *   i = 4 : turn on 'f'
 *   ....
 *@param i the ith pin associated with this word.
 **/
void four_hour(int i);

/**
 *sets the ith pin associated with 'five' on the board to 1. Note that i rolls
 *over. For example:
 *   i = 0 : turn on 'f'
 *   i = 1 : turn on 'i'
 *   i = 2 : turn on 'v'
 *   i = 3 : turn on 'e'
 *   i = 4 : turn on 'f'
 *   ....
 *@param i the ith pin associated with this word.
 **/
void five_hour(int i);

/**
 *sets the ith pin associated with 'six' on the board to 1. Note that i rolls
 *over. For example:
 *   i = 0 : turn on 's'
 *   i = 1 : turn on 'i'
 *   i = 2 : turn on 'x'
 *   i = 3 : turn on 's'
 *   ....
 *@param i the ith pin associated with this word.
 **/
void six_hour(int i);

/**
 *sets the ith pin associated with 'seven' on the board to 1. Note that i rolls
 *over. For example:
 *   i = 0 : turn on 's'
 *   i = 1 : turn on 'e'
 *   i = 2 : turn on 'v'
 *   i = 3 : turn on 'e'
 *   ....
 *@param i the ith pin associated with this word.
 **/
void seven_hour(int i);

/**
 *sets the ith pin associated with 'eight' on the board to 1. Note that i rolls
 *over. For example:
 *   i = 0 : turn on 'e'
 *   i = 1 : turn on 'i'
 *   i = 2 : turn on 'g'
 *   i = 3 : turn on 'h'
 *   i = 4 : turn on 't'
 *   ....
 *@param i the ith pin associated with this word.
 **/
void eight_hour(int i);


/**
 *sets the ith pin associated with 'one' on the board to 1. Note that i rolls
 *over. For example:
 *   i = 0 : turn on 'e'
 *   i = 1 : turn on 'l'
 *   i = 2 : turn on 'e'
 *   i = 3 : turn on 'v'
 *   ....
 *@param i the ith pin associated with this word.
 **/
void eleven_hour(int i);

/**
 *sets the ith pin associated with 'one' on the board to 1. Note that i rolls
 *over. For example:
 *   i = 0 : turn on 't'
 *   i = 1 : turn on 'w'
 *   i = 2 : turn on 'e'
 *   i = 3 : turn on 'l'
 *   i = 4 : turn on 'v'
 *   i = 5 : turn on 'e'
 *   i = 6 : turn on 't'
 *   ....
 *@param i the ith pin associated with this word.
 **/
void twelve_hour(int i);

#endif