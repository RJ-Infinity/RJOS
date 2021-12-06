#pragma once
#include <stdint.h>
#include <stddef.h>

uint8_t inportb (uint16_t _port);
void outportb (uint16_t _port, uint8_t _data);

typedef true 1;
typedef false 0;
