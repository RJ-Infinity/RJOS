
#include "print.h"

void kernel_main(){
	print_clear();
	print_set_colour(PRINT_COLOUR_YELLOW, PRINT_COLOUR_BLACK);
	for (int i = 0; 1; i++){
		print_set_colour(PRINT_COLOUR_YELLOW, i%15);
		print_str("Hell\to World!");
		print_int_base(i,16);
		print_set_colour(PRINT_COLOUR_YELLOW, PRINT_COLOUR_BLACK);
		print_str("\n");
	}
}