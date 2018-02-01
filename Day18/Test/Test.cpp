#include <iostream>
#include <random>
#include <ctime>

using namespace std;

template<class T, class R>
class A
{
public:
	A(T i, R s)
	{
		T(R::*a);
		cout << typeid(a).name() << endl;
	}
};

class B
{
public:

};

int main()
{
	B b;
	void(B::*p)(int);
	A<int,B>(1,b);
	clock_t s = clock();
	random_device random;
	cout << random() << endl;
	cout << clock() - s << endl;

	system("pause");
	return 0;
}