#include <iostream>

using namespace std;

class BaseClass
{
public:
	BaseClass()
	:
	m_Value(0)
	{

	}
	/*virtual*/~BaseClass()
	{
		cout << "in BaseClass deconstruction" << endl;
	}

	/*virtual*/ void ImInfo()
	{
		cout << "Im BaseClass" << endl;
	}

private:
	int m_Value;
};

class SubClass_1 : public BaseClass
{
public:
	SubClass_1()
	:
	BaseClass(),
	m_Value(0)
	{

	}
	/*virtual*/~SubClass_1()
	{
		cout << "in SubClass_1 deconstruction" << endl;
	}

	/*virtual*/ void ImInfo()
	{
		cout << "Im SubClass_1" << endl;
	}

private:
	int m_Value;
};

class SubClass_2 : public BaseClass
{
public:
	SubClass_2()
	:
	BaseClass(),
	m_Value(0)
	{

	}
	/*virtual*/~SubClass_2()
	{
		cout << "in SubClass_2 deconstruction" << endl;
	}

	/*virtual*/ void ImInfo()
	{
		cout << "Im SubClass_2" << endl;
	}

private:
	int m_Value;
};


int main(int argc, char *argv[])
{
	cout << "为什么父类析构函数要加virtual" << endl;
	BaseClass *pBase = new SubClass_1();
	// pBase -> ImInfo();
	delete pBase;

	cout << "多态（子类指针）" << endl;
	SubClass_1 s1;
	SubClass_2 s2;

	SubClass_1 *b1 = &s1;
	b1 -> ImInfo();
	b1 -> BaseClass::ImInfo();

	cout << "多态（父类指针）" << endl;

	BaseClass *b2 = &s2;
	b2 -> ImInfo();
	b2 -> BaseClass::ImInfo();

	cout << "测试结束" << endl;

	return 0;
}