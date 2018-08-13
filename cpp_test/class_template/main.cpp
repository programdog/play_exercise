#include <stdio.h>
#include <compare_teleplate.hpp>

int main(int argc, char *argv[])
{
	Compare <int> cmp_int(1, 5);//类模板名 <实际类型名> 对象名(参数列表)
	Compare <float> cmp_float(1.3, 5.3);
	cmp_int.show();
	cmp_float.show();
}