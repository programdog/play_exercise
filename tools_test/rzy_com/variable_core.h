#ifndef VARIABLE_CARE_H_
#define VARIABLE_CARE_H_

#define DEAUFLT_BAUDRATE 57600
#define RECEIVE_BUF 1000

typedef struct B_baudrate_table_t
{
	uint8_t index;
	uint32_t user_baudrate;
	uint32_t bin_baudrate;
} B_baudrate_table_t;

B_baudrate_table_t B_baudrate_table[] = 
{
	{0, 2400, 0000013},
	{1, 4800, 0000014},
	{2, 9600, 0000015},
	{3, 19200, 0000016},
	{4, 38400, 0000017},
	{5, 57600, 0010001},
	{6, 115200, 0010002},
	{7, 230400, 0010003}
};

#endif
