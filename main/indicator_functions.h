
#ifndef INDICATOR_FUNCTIONS
#define INDICATOR_FUNCTIONS

/**
 * sets the ith pin associated with 'it is' . Note that i rolls
 * over. For example:
 *   i = 0 : turn on 'i'
 *   i = 1 : turn on 't'
 *   i = 2 : turn on 'i'
 *   i = 3 : turn on 's'
 *   i = 4 : turn on 'i'
 *   i = 5 : turn on 's'
 *   i = 6 : turn on 'i'
 *   i = 7 : turn on 's'
 *   i = 8 : turn on 'i'
 *   ....
 *@param i the ith pin associated with this word.
 **/
void it_is(int i);

/**
 * sets the ith pin associated with 'past' Note that i rolls
 * over. For example:
 *   i = 0 : turn on 'p'
 *   i = 1 : turn on 'a'
 *   i = 2 : turn on 's'
 *   i = 3 : turn on 't'
 *   i = 4 : turn on 'p'
 *   i = 5 : turn on 'a'
 *   i = 6 : turn on 's'
 *   i = 7 : turn on 't'
 *   i = 8 : turn on 'p'
 *   ....
 *@param i the ith pin associated with this word.
 **/
void past(int i);


/**
 * sets the ith pin associated with 'to'  Note that i rolls
 * over. For example:
 *   i = 0 : turn on 't'
 *   i = 1 : turn on 'o'
 *   i = 2 : turn on 't'
 *   i = 3 : turn on 'o'
 *   i = 4 : turn on 't'
 *   i = 5 : turn on 'o'
 *   i = 6 : turn on 't'
 *   i = 7 : turn on 'o'
 *   i = 8 : turn on 't'
 *   ....
 *@param i the ith pin associated with this word.
 **/
void to(int i);


/**
 * sets the ith pin associated with 'oclock'.  Note that i rolls
 * over. For example:
 *   i = 0 : turn on 'o'
 *   i = 1 : turn on 'c'
 *   i = 2 : turn on 'l'
 *   i = 3 : turn on 'o'
 *   i = 4 : turn on 'c'
 *   i = 5 : turn on 'k'
 *   i = 6 : turn on 'o'
 *   i = 7 : turn on 'c'
 *   i = 8 : turn on 'l'
 *   ....
 *@param i the ith pin associated with this word.
 **/
void oclock(int i){

#endif