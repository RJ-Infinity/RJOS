#include "string.h"

uint16_t strlength(string ch)
{
	uint16_t i = 1;
	while(ch[i++]);  
	return --i;
}