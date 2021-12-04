#include "print.h"

const static size_t NUM_COLS = 80;
const static size_t NUM_ROWS = 25;
const static size_t TAB_SIZE = 4;

struct Char {
	uint8_t character;
	uint8_t colour;

};


struct Char* buffer = (struct Char*) 0xb8000;

size_t col = 0;
size_t row = 0;
uint8_t colour = PRINT_COLOUR_WHITE | (PRINT_COLOUR_BLACK << 4);

void clear_row(size_t row){
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
	clear_row(NUM_ROWS-1);
}

void print_clear(){
	for(size_t i = 0; i < NUM_ROWS; i++){
		clear_row(i);

	}
}

void print_char(char character){
	if (character == '\n'){
		print_newline();
		return;
	}
	if(col > NUM_COLS){
		print_newline();
	}
	if (character == '\t'){
		for(size_t i = (col%TAB_SIZE); i < 4; i++){
			print_char(' ');
		}
		return;
	}

	buffer[(NUM_COLS*row)+col] = (struct Char){
		character: (uint8_t) character,
		colour:colour,
	};
	col++;
}

void print_str(char* string){
	for (size_t i = 0; 1; i++){
		char character = (uint8_t)string[i];
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
