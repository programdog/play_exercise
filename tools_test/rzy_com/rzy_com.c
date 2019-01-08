/**
 * @Author   rzy
 * @DateTime 2019-01-07T18:40:51+0800
 * @Function :
 * @return   [com tool]
 */
#include "rzy_com.h"

int main(int argc, char **argv)
{
	int opt;
	char user_port_name[16] = {0};
	uint32_t user_baudrate = DEAUFLT_BAUDRATE;

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
	printf("user_port_name=%s, user_baudrate=%d\r\n", user_port_name, user_baudrate);
	return 0;
}

