#include <compare_teleplate.hpp>

template <class numtype>
Compare<numtype>::Compare(numtype a, numtype b)
	:
	x(a),
	y(b)
{

}

template <class numtype>
Compare<numtype>::~Compare()
{

}

template <class numtype>
numtype Compare<numtype>::CompareMax()
{
	return (x > y) ? x : y; 
}

template <class numtype>
numtype Compare<numtype>::CompareMin()
{
	return (x < y) ? x : y;
}

template <class numtype>
void Compare<numtype>::show()
{
	cout << "x=" << x << endl;
	cout << "y=" << y << endl;
	cout << "Max=" << CompareMax() << endl;
	cout << "Min=" << CompareMin() << endl;
}