#变量在声明时需要给予初值，在使用时在变量名前加$，加上括号是为了安全地使用这个变量
#如果需要使用$符号，那么需要用$$来表示
# / <- 反斜杠（\）是换行符的意思
#makefile会找文件中的第一个目标文件，如下边的all
#shell命令，最前面的一定是一个tab键
CC=gcc
CFLAGS=-std=gnu99

objects=rzy_main.o rzy_com.o#应该叫变量的声明更合适
out=rcom

all : $(objects) # all是依赖文件(make选项)，：后是目标文件
	$(CC) -o $(out) $(objects)

rzy_main.o : rzy_main.c
	$(CC) $(CFLAGS) -c rzy_main.c

rzy_com.o : rzy_com.c
	$(CC) $(CFLAGS) -c rzy_com.c

clean :
	rm $(out) $(objects) 

.PHONY : all clean 