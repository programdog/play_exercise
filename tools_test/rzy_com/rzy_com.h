#ifndef RZY_COM_H_
#define RZY_COM_H_

#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <getopt.h>
#include <fcntl.h>
#include <termios.h>
#include "often_define.h"


int uart_complex_set(int uartFd, const char *port, uint32_t baudrate);
uint32_t switch_baudrate(uint32_t user_input);
int send_user_input(void);
int show_port_output(void);
int print_set_info(void);
int print_how_to_use(void);


#endif