#include "rzy_com.h"
#include "variable_core.h"

/*user data*/
char user_port_name[16] = {0};
uint32_t user_baudrate = DEAUFLT_BAUDRATE;
int user_fd = -1;


/**
 * @Author   rzy
 * @DateTime 2019-01-10T14:55:29+0800
 * @Function :
 * @param    uartFd                   [if you have fd, input that; if you don't have, input -1]
 * @param    port                     [which port you want open]
 * @param    baudrate                 [which baudrate you want select]
 * @return                            [return open fd]
 */
int uart_complex_set(int uartFd, const char *port, uint32_t baudrate)
{
	if (uartFd >= 0)
	{
		close(uartFd);
	}
	if (uartFd < 0)
	{
		uartFd = open(port, O_RDONLY | O_NOCTTY | O_NONBLOCK);
		if (uartFd < 0)
		{
			printf("open failed %s\r\n", port);
			return ERROR;
		}
	}

	struct termios uart_config;
	int termios_state;
	/* fill the struct for the new configuration */
	tcgetattr(uartFd, &uart_config);
	/* clear ONLCR flag (which appends a CR for every LF) */
	uart_config.c_oflag &= ~ONLCR;
	/* no parity, one stop bit */
	uart_config.c_cflag &= ~(CSTOPB | PARENB);
	/* set baud rate */
	if ((termios_state = cfsetispeed(&uart_config, baudrate)) < 0)
	{
		printf("ERR CFG: %d ISPD\n", termios_state);
	}
	if ((termios_state = cfsetospeed(&uart_config, baudrate)) < 0)
	{
		printf("ERR CFG: %d OSPD\n", termios_state);
	}
	if ((termios_state = tcsetattr(uartFd, TCSANOW, &uart_config)) < 0)
	{
		printf("ERR baud %d ATTR\n", termios_state);
	}

	return uartFd;
}

uint32_t switch_baudrate(uint32_t user_input)
{
	uint32_t B_baudrate = 0;

	for (uint8_t i = 0; i < sizeof(B_baudrate_table)/sizeof(B_baudrate_table_t); i++)
	{
		if (B_baudrate_table[i].user_baudrate == user_input)
		{
			B_baudrate = B_baudrate_table[i].bin_baudrate;
			break;
		}
	}
	return B_baudrate;
}

int send_user_input()
{
	printf("in--send_user_input\r\n");
	return 0;
}

int show_port_output()
{
	char read_buf[100] = {0};
	int read_num = 0;
	while (1)
	{
		usleep(100*1000);
		read_num = read(user_fd, read_buf, 100);
		for (uint8_t i = 0; i < read_num; i++)
		{
			printf("%02x ", (uint8_t)read_buf[i]);
		}
		if (read_num > 0)
		{
			printf("\r\n");
		}
	}
	return 0;
}

int print_set_info()
{
	printf("user_port_name=%s, user_baudrate=%d\r\n", 
		user_port_name, user_baudrate);
	return 0;
}

int print_how_to_use()
{
	printf("only support -p -s\n -p : select which port\n -s : select which baudrate\r\n");
	return 0;
}