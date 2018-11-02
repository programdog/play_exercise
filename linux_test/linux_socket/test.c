#include <stdio.h>

int main(int argc, char *argv[])
{
	char cmd[200];
	snprintf(cmd, 200, "ps -ef | grep %s | grep -v grep | awk '{print $2}' | xargs kill -9", argv[1]);
	system(cmd);
	return 0;
}
