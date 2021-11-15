
#ifndef MINUTE_FUNCTIONS
#define MINUTE_FUNCTIONS
/**
 * set all pins associated with the minutes charliplexed network to input
 * (high impedence state)
*/
void set_MinPins_INPUT();


/**
 * sets the ith pin associated with 'five' on the board to 1 associated with 
 * minutes . Note that i rolls
 * over. For example:
 *   i = 0 : turn on 'f'
 *   i = 1 : turn on 'i'
 *   i = 2 : turn on 'v'
 *   i = 3 : turn on 'e'
 *   ....
 *@param i the ith pin associated with this word.
 **/
void five_minutes(int i);


/**
 * sets the ith pin associated with 'ten' on the board to 1 associated with 
 * minutes . Note that i rolls
 * over. For example:
 *   i = 0 : turn on 't'
 *   i = 1 : turn on 'e'
 *   i = 2 : turn on 'n'
 *   i = 3 : turn on 't'
 *   ....
 *@param i the ith pin associated with this word.
 **/
void ten_minutes(int i);

/**
 * sets the ith pin associated with 'quarter' on the board to 1 associated with 
 * minutes . Note that i rolls
 * over. For example:
 *   i = 0 : turn on 'q'
 *   i = 1 : turn on 'u'
 *   i = 2 : turn on 'a'
 *   i = 3 : turn on 'r'
 *   i = 4 : turn on 't'
 *   i = 5 : turn on 'e'
 *   i = 6 : turn on 'r'
 *   i = 7 : turn on 'q'
 *   i = 8 : turn on 'u'
 *   ....
 *@param i the ith pin associated with this word.
 **/
void fifteen_minutes(int i);

/**
 * sets the ith pin associated with 'twenty' on the board to 1 associated with 
 * minutes . Note that i rolls
 * over. For example:
 *   i = 0 : turn on 't'
 *   i = 1 : turn on 'w'
 *   i = 2 : turn on 'e'
 *   i = 3 : turn on 'n'
 *   i = 4 : turn on 't'
 *   i = 5 : turn on 'y'
 *   i = 6 : turn on 't'
 *   i = 7 : turn on 'w'
 *   i = 8 : turn on 'e'
 *   ....
 *@param i the ith pin associated with this word.
 **/
void twenty_minutes(int i);

/**
 * sets the ith pin associated with 'twentyfive' on the board to 1 associated 
 * with minutes . Note that i rolls
 * over. For example:
 *   i = 0 : turn on 't'
 *   i = 1 : turn on 'w'
 *   i = 2 : turn on 'e'
 *   i = 3 : turn on 'n'
 *   i = 4 : turn on 't'
 *   i = 5 : turn on 'y'
 *   i = 6 : turn on 'f'
 *   i = 7 : turn on 'i'
 *   i = 8 : turn on 'v'
 *   ....
 *@param i the ith pin associated with this word.
 **/
void twentyfive_minutes(int i);

/**
 * sets the ith pin associated with 'half' on the board to 1 associated with 
 * minutes . Note that i rolls
 * over. For example:
 *   i = 0 : turn on 'h'
 *   i = 1 : turn on 'a'
 *   i = 2 : turn on 'l'
 *   i = 3 : turn on 'f'
 *   i = 4 : turn on 'h'
 *   i = 5 : turn on 'a'
 *   i = 6 : turn on 'l'
 *   i = 7 : turn on 'f'
 *   i = 8 : turn on 'h'
 *   ....
 *@param i the ith pin associated with this word.
 **/
void thirty_minutes(int i);

#endif
