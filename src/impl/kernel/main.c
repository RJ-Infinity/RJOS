//ENCODING cp437
#include "print.h"

void kernel_main(){
	print_set_colour(PRINT_COLOUR_BLACK, PRINT_COLOUR_BLUE);
	print_clear();
	set_print_location((NUM_COLS/2)-9,(NUM_ROWS/2)-2);
	print_set_colour(PRINT_COLOUR_BLACK, PRINT_COLOUR_LIGHT_GREY);
	// print_str("\xda\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xbf");
	print_str("���������������Ŀ");
	print_set_colour(PRINT_COLOUR_BLACK, PRINT_COLOUR_BLUE);
	print_char('�');
	print_set_colour(PRINT_COLOUR_BLACK, PRINT_COLOUR_LIGHT_GREY);
	// print_str("+---------------+");
	set_print_location((NUM_COLS/2)-9,(NUM_ROWS/2)-1);
	print_str("�Welcome to RJOS��");
	// print_str("|Welcome to RJOS|");
	set_print_location((NUM_COLS/2)-9,(NUM_ROWS/2));
	print_str("�  >Continue<   ��");
	// print_str("|  |Continue|   |");
	set_print_location((NUM_COLS/2)-9,(NUM_ROWS/2)+1);
	print_str("������������������");
	// print_str("+---------------+");
	set_print_location((NUM_COLS/2)-9,(NUM_ROWS/2)+2);
	print_set_colour(PRINT_COLOUR_BLACK, PRINT_COLOUR_BLUE);
	print_str(" �����������������");



	// for(int i = 0;i<256;i++){
	// 	if(i<16){
	// 		print_char('0');
	// 	}
	// 	print_int_base(i,16);
	// 	print_str(" ");
	// 	if (i==9){
	// 		print_char('9');
	// 	}else if (i==10){
	// 		print_char('A');
	// 	}else{
	// 		print_char((char)i);
	// 	}
	// 	print_str(" ");
	// 	if (i%16==15){
	// 		print_char('\n');
	// 	}
	// }
}