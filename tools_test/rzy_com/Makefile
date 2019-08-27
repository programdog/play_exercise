#变量在声明时需要给予初值，在使用时在变量名前加$，加上括号是为了安全地使用这个变量
#如果需要使用$符号，那么需要用$$来表示
# \ <- 反斜杠（\）是换行符的意思
#makefile会找文件中的第一个目标文件，如下边的all
#shell命令，最前面的一定是一个tab键
# $@--目标文件，$^--所有的依赖文件，$<--第一个依赖文件
# @-表示不打印当前命令

CC=gcc
CFLAGS=-std=gnu99

objects=com_main.o com_function.o#应该叫变量的声明更合适
out=rcom

all : $(objects) # all是依赖文件(make选项)，：后是目标文件
	$(CC) -o $(out) $(objects)

com_main.o : com_main.c
	@ $(CC) $(CFLAGS) -c com_main.c

com_function.o : com_function.c
	@ $(CC) $(CFLAGS) -c com_function.c

test:
	@ $(call hello_function, 5, 6, 7)

clean :
	rm $(out) $(objects) 

.PHONY : all clean


define hello_function
@ echo 123
@ echo $(0)
@ echo $(1)
endef