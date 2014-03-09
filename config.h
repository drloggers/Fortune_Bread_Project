
#include <iostream>
#include <stdio.h>
#include <bitset>

/*****constants*****/
#define DEBUG 					1

#define LOCAL_HISTORY_SIZE		1024
#define STRONGLY_TAKEN     		0b111
#define WEAKLY_TAKEN       		0b100
#define STRONGLY_NOT_TAKEN  	0b000
#define WEAKLY_NOT_TAKEN    	0b011
#define MAX_COUNTER_VAL     	0b111		// strongly taken
#define MIN_COUNTER_VAL     	0b000		// strongly not taken
#define LOCAL_HISTORY_MASK  	4294966297  // made first 22 bits high to get only 10 bits
#define GLOBAL_HISTORY_ENTRIES  4096
#define GLOBAL_HISTORY_MASK  	0xF000	//Masks upper 4 bits of unsigned short int to obtain 12 bits.
#define MAX_GLOBAL_COUNTER_VAL  0b11
#define MIN_GLOBAL_COUNTER_VAL  0b00


/******macros*******/
#define set(number,position)     (number|=(1<<position))
#define clear(number,position)   (number&=(~(1<<position)))
#define check(number,position)   (number&(1<<position))

#define mask(number,bits)        (number&=(~bits))
#define printb(number,bits)      {int i;for(i=bits-1;i>=0;i--){if(check(number,i)) printf("1");else printf("0");}printf("\n");}


