#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#define BOOK_NUMBER 2
using namespace std;

struct Sales_data
{
	string bookISBN;
	unsigned int sell = 0;
	double revenue = 0;
	unsigned price = 0;
};

int main(int argv, char *argc[])
{
	if (BOOK_NUMBER % 2 == 0)
		cerr << "Please enter an even number" << endl;

	Sales_data sales[BOOK_NUMBER];
	for (int i = 0; i < BOOK_NUMBER; i++)
	{
		cout << "Book" << i + 1 << ':' << "ISBN¡¢Sell¡¢price" << endl;
		cin >> sales[i].bookISBN >> sales[i].sell >> sales[i].price;
		sales[i].revenue = sales[i].sell * sales[i].price;
	}

	for (int i = 0; i < BOOK_NUMBER; i += 2)
	{
		if (sales[i].bookISBN == sales[i + 1].bookISBN)
		{
			unsigned int sum_sell = sales[i].sell + sales[i + 1].sell;
			double sum_revenue = sales[i].revenue + sales[i + 1].revenue;
			if (sum_sell != 0)
			{
				cout << sales[i].bookISBN << ',' << sum_sell << ',' << sales[i].price << ',' << sum_revenue << ',' << (sum_revenue / sum_sell) << endl;
			}
			else
			{
				cerr << "No sales records!" << endl;
			}
		}
		else
		{
			cerr << "Book ISBN Inconsistent!" << endl;
		}
	}

	system("pause");
	return 0;
}