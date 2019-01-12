/**
 * @Author   rzy
 * @DateTime 2019-01-07T18:40:51+0800
 * @Function :
 * @return   [com tool]
 */
#include "rzy_main.h"

extern char user_port_name[16];
extern uint32_t user_baudrate;
extern int user_fd;

int main(int argc, char **argv)
{
	int opt;

	if (2 == argc)
	{
		if (!strcmp(argv[1], "set"))
		{
			// uart_complex_set(-1, user_port_name, user_baudrate);
			print_set_info();
		}
		if ((!strcmp(argv[1], "help")) || (!strcmp(argv[1], "?")))
		{
			print_how_to_use();
		}
	}
	else
	{
		while ((opt = getopt(argc, argv, "s:p:")) != EOF)
		{
			switch (opt)
			{
				case 's':
					user_baudrate = (uint32_t)atoi(optarg);
				break;

				case 'p':
					snprintf(user_port_name, sizeof(user_port_name), "%s", optarg);
				break;

				default:
					printf("only support -p -s\n -p : select which port\n -s : select which baudrate\r\n");
					exit(0);
			}
		}
		user_fd = uart_complex_set(user_fd, user_port_name, switch_baudrate(user_baudrate));
		print_set_info();
		sleep(2);
		show_port_output();
	}
	return 0;
}

