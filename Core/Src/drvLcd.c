/*
 * drvLcd.c
 *
 *  Created on: 18 нояб. 2019 г.
 *      Author: S1ckret
 */

#include "drvLcd.h"
#include "main.h"

#define LINE_COUNT 2
#define COLUMN_COUNT 16

// Low level function. Reset pin in ODR via BSSR
// BSSR 32 bit register
// 0-15 bits: if '1' then write '1' in ODR
void set_high(uint16_t Pin);

// Low level function. Reset pin in ODR via BSSR
// 16-31 bits: if '1' then write '0' in ODR
void set_low(uint16_t Pin);

void delay_ms(uint32_t ms);

void enable_command_mode();
void enable_data_mode();

uint16_t shift_lower_4bit_to_data_bus(uint16_t data);
uint16_t shift_upper_4bit_to_data_bus(uint16_t data);

void clean_data_bus();
void send_lower_4bit(uint8_t data);
void send_upper_4bit(uint8_t data);

void send_command(uint8_t data);

void drvLcd_Init()
{
	send_command(0b0011);

	send_command(0b0011);

	send_command(0b0011);

	send_command(0b0010);

	send_command(0b0010);
	send_command(0b1000);

	send_command(0b0000);
	send_command(0b1000);

	send_command(0b0000);
	send_command(0b0001);

	send_command(0b0000);
	send_command(0b0110);

	send_command(0b0000);
	send_command(0b1111);
}

// LCD updates when signal goes HI->LOW
void drvLcd_Pulse()
{
	set_high(DISP_ENA_Pin);
	delay_ms(1);
	set_low(DISP_ENA_Pin);
	delay_ms(1);
}

void drvLcd_SendChar(uint8_t byte)
{
	enable_data_mode();
	send_upper_4bit(byte);
	send_lower_4bit(byte);
}

void drvLcd_SendString(uint8_t* str)
{
	uint8_t i = 0;
	while (str[i] != '\n')
	{
		drvLcd_SendChar(str[i]);
		i++;
		delay_ms(50);
		if (!(i % COLUMN_COUNT))
		{
			drvLcd_SetCursor((i / COLUMN_COUNT) % 2, 0);
		}
	}
}

void drvLcd_SetCursor(uint8_t line, uint8_t column)
{
	if (line < LINE_COUNT && column < COLUMN_COUNT)
	{
		send_command(0b1000 | (line << 2));
		send_command(0b0000 | column);
	}
}

void set_high(uint16_t Pin)
{
	GPIOE->BSRR |= Pin;
}

// Low level function. Reset pin in ODR via BSSR
// 16-31 bits: if '1' then write '0' in ODR
void set_low(uint16_t Pin)
{
	// Shifting by 16 bits to 16-31 position.
	GPIOE->BSRR |= Pin << 16;
}

void delay_ms(uint32_t ms)
{
	HAL_Delay(ms);
}

void enable_command_mode()
{
	set_low(DISP_RS_Pin);
}

void enable_data_mode()
{
	set_high(DISP_RS_Pin);
}

uint16_t shift_lower_4bit_to_data_bus(uint16_t data)
{
	return ((data & 0b00001111) << 12);
}

uint16_t shift_upper_4bit_to_data_bus(uint16_t data)
{
	return ((data & 0b11110000) << 8);
}

void clean_data_bus()
{
	set_low(shift_lower_4bit_to_data_bus(0b1111));
	delay_ms(1);
}

void send_lower_4bit(uint8_t data)
{
	set_high( shift_lower_4bit_to_data_bus(data) );
	delay_ms(1);
	drvLcd_Pulse();
	clean_data_bus();
}

void send_upper_4bit(uint8_t data)
{
	set_high( shift_upper_4bit_to_data_bus(data) );
	delay_ms(1);
	drvLcd_Pulse();
	clean_data_bus();
}

void send_command(uint8_t data)
{
	enable_command_mode();
	send_lower_4bit(data);
}
