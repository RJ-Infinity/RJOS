#include "print.h"
#include "string.h"

struct Char {
	uint8_t character;
	uint8_t colour;
};


struct Char* buffer = (struct Char*) 0xb8000;

size_t col = 0;
size_t row = 0;
uint8_t colour = PRINT_COLOUR_WHITE | (PRINT_COLOUR_BLACK << 4);

void print_clear_row(size_t row){
	struct Char empty = (struct Char) {
		character: ' ',
		colour: colour
	};
	for (size_t col = 0; col < NUM_COLS; col++){
		buffer[(NUM_COLS*row)+col] = empty;
	}
}

void print_newline(){
	col = 0;
	if (row < NUM_ROWS -1){
		row++;
		return;
	}
	for (size_t row = 1; row < NUM_ROWS; row++){
		for(size_t col = 0; col < NUM_COLS; col++){
			struct Char character = buffer[(NUM_COLS*row)+col];
			buffer[(NUM_COLS*(row-1))+col] = character;
		}
	}
	print_clear_row(NUM_ROWS-1);
}

void print_clear(){
	for(size_t i = 0; i < NUM_ROWS; i++){
		print_clear_row(i);

	}
}

void print_char(char character){
	if(col > NUM_COLS){
		print_newline();
	}
	switch (character)
	{
		case '\n':{
			print_newline();
			return;
		}
		case '\t':{
			for(size_t i = (col%TAB_SIZE); i < 4; i++){
				print_char(' ');
			}
			return;
		}
		case '\r':{
			col = 0;
			break
		}
		case '\b':{
			if (col == 0){
				return;
			}
			col--;
			buffer[(NUM_COLS*row)+col] = (struct Char){
				character: ' ',
				colour:colour,
			};
			break;
		}
		default:{
			buffer[(NUM_COLS*row)+col] = (struct Char){
				character: (uint8_t) character,
				colour:colour,
			};
			col++;
			break;
		}
	}
	updateCursor(col,row);
}

void print_str(string str){
	for (size_t i = 0; 1; i++){
		char character = (uint8_t)str[i];
		if (character == '\0'){
			return;
		}
		print_char(character);
	}
}

void print_set_colour(uint8_t foreground_colour, uint8_t background_colour){
	colour = foreground_colour + (background_colour << 4);
}

void print_int_base(int i, int base){
	if (i>base-1){
		print_int_base(i/base,base);
	}
	i=i%base;
	if (i>9){
		i+=7;
	}
	print_char((char)(i+48));
}
void print_int(int i){
	print_int_base(i,10);
}
void set_print_location(size_t x,size_t y){
	col = x;
	row = y;
}
void updateCursor(size_t r, size_t c){
	size_t cursorPos = (NUM_COLS*r)+c;

	outportb(0x3D4, 14); // CRT Control Register: Select Cursor Location
	outportb(0x3D5, cursorPos >> 8); // Send the high byte across the bus
	outportb(0x3D4, 15); // CRT Control Register: Select Send Low byte
	outportb(0x3D5, cursorPos); // Send the Low byte of the cursor location
}