/*
 ============================================================================
 Name        : CCodingExample.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
static unsigned int  insertInteger(unsigned int originalInt, unsigned int insertInt, unsigned int start_index, unsigned int end_index);

int main(void)
{

	/*
	 * Example:
     * Input:   N = 100000000000, M = 10011, i = 2, j = 7
     * Output: N = 100001001100
	 */
	unsigned int orig = 0B100000000000;
	unsigned int insert = 0B10011;
	unsigned int i = 2;
	unsigned int  j = 7;
	unsigned int result = insertInteger(orig, insert, i, j);
	return EXIT_SUCCESS;
}



static unsigned int  insertInteger(unsigned int originalInt, unsigned int insertInt, unsigned int start_index, unsigned int end_index)
{
	unsigned int mask = 0;

	//Generate the mask
	int ii = 0;
	for (ii = start_index; ii < end_index; ii++)
	{
	     mask |= (1u << ii) ;
	}

	unsigned int shifted_insertInt = (insertInt << start_index);
	originalInt |= mask;
	unsigned int andedOrig = 0;
	andedOrig = originalInt | shifted_insertInt;

	return andedOrig;
}
