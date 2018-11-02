#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>

#define UNIX_DOMAIN "/home/rzy/work/test_play/c_test/linux_socket/UNIX.domain"

int main(int argc, char *argv[])
{
	int socket_fd2;
	struct sockaddr_un srv_addr;
	int ret;
	char send_buf[30] = {0};

	socket_fd2 = socket(PF_UNIX, SOCK_STREAM, 0);
	if (socket_fd2 < 0)
	{
		printf("cannot creat socket_fd2\r\n");
		return -1;
	}

	srv_addr.sun_family = PF_UNIX;
	strcpy(srv_addr.sun_path, UNIX_DOMAIN);
	ret = connect(socket_fd2, (struct sockaddr*)&srv_addr, sizeof(srv_addr));
	if (ret < 0)
	{
		printf("connot connect server\r\n");
		close(socket_fd2);
		return -1;
	}

	strcpy(send_buf, "i'm rzy_client");

	while (1)
	{
		static unsigned char i = 0;
		ret = 0;
		i ++;
		if (i < 10)
		{
			ret = write(socket_fd2, send_buf, strlen(send_buf));
		}
		printf("i=%d, write_ret=%d, sizeof=%d\r\n", i, ret, (int)strlen(send_buf));
		sleep(2);
	}
	close(socket_fd2);
	return 0;
}