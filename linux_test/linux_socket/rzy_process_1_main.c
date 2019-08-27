#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <fcntl.h>

#define UNIX_DOMAIN "/home/rzy/work/test_play/c_test/linux_socket/UNIX.domain"

int main(int argc, char *argv[])
{
	int socket_fd1;
	struct sockaddr_un clt_addr;
	struct sockaddr_un srv_addr;
	int ret;
	int len;
	int num;
	int com_fd;
	char rec_from_client[100] = {0};

	socket_fd1 = socket(AF_UNIX, SOCK_STREAM, 0);
	if (socket_fd1 < 0)
	{
		printf("cannot creat socket_fd1\r\n");
		return -1;
	}

	srv_addr.sun_family = AF_UNIX;
	strncpy(srv_addr.sun_path, UNIX_DOMAIN, sizeof(srv_addr.sun_path)); // ?
	unlink(UNIX_DOMAIN);
	ret = bind(socket_fd1, (struct sockaddr*)&srv_addr, sizeof(srv_addr));
	if (ret < 0)
	{
		printf("cannot bling socket_fd1");
		close(socket_fd1);
		unlink(UNIX_DOMAIN);
		return -1;
	}

	ret = listen(socket_fd1, 1);
	if (ret < 0)
	{
		printf("cannot listen socket_fd1\r\n");
		close(socket_fd1);
		unlink(UNIX_DOMAIN);
		return -1;
	}

	len = sizeof(clt_addr);
	com_fd = accept(socket_fd1, (struct sockaddr*)&clt_addr, &len);
	if (com_fd < 0)
	{
		printf("cannot accept request\r\n");
		close(socket_fd1);
		unlink(UNIX_DOMAIN);
		return -1;
	}

	int flags = fcntl(com_fd, F_GETFL, 0);
	fcntl(com_fd, F_SETFL, flags | O_NONBLOCK);

	while (1)
	{
		num = read(com_fd, rec_from_client, sizeof(rec_from_client));
		if (num < 0)
		{
			printf("no data from client\r\n");
		}
		else
		{
			printf("msg from client : %d, %s\r\n", num, rec_from_client);
		}
		printf("server run\r\n");
		sleep(1);
	}
	close(com_fd);
	close(socket_fd1);
	unlink(UNIX_DOMAIN);
	return 0;
}