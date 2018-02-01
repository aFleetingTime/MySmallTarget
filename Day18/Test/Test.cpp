#include <iostream>
#include <random>
#include <ctime>

using namespace std;

int main()
{
	
	clock_t s = clock();
	random_device random;
	cout << random() << endl;
	cout << clock() - s << endl;

	system("pause");
	return 0;
}