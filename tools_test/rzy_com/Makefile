objects=rzy_com.o #应该叫变量的声明更合适
all : $(objects) #rzycom 就是我们要生成的目标.
#main.o print.o是生成此目标的先决条件
	gcc -o rzycom $(objects) 
#shell命令，最前面的一定是一个tab键
rzycom.o : rzy_com.c rzy_com.h 
	gcc -c rzy_com.c

clean :
	rm rzycom $(objects) 

.PHONY : all clean 