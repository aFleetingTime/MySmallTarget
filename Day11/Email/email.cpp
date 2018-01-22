#include <iostream>
#include <string>
#include <stdexcept>
#include <cctype>

using namespace std;

class Email
{
public:
	void getEmail()
	{
		cout << "����������:" << endl << ">>";
		char buf[1024];
		cin.getline(buf, sizeof(buf) / sizeof(*buf));
		email.clear();
		email.append(buf);
	}
	bool verifyEmail()
	{
		unsigned int index = 0;
		string error;

		if (email.empty())
			error = "����Ϊ��!";
		for (string::iterator beg = email.begin(), End = email.end(); beg != End; ++beg)
		{
			if (*beg == '.' || *beg == '@')
				continue;
			else if (!isalnum(*beg))
				throw out_of_range("���ܰ��������ַ�!");
		}
		if ((index = email.find('@')) == string::npos)
			error = "���䲻��û��@����!";
		else if (email.find('@', index + 1) != string::npos)
			error = "����ֻ����һ��@����!";
		else if (email.at(index + 1) == '.' || (index = email.find('.', index + 2)) == string::npos)
			error = "ȱ��������.����!";
		else if (email.find('.') != index)
			error = "���ж��.����!";
		else if (!isalnum(email.at(0)))
			error = "ȱ���û���!";
		else if (email.length() == email.find('.') + 1)
			error = "ȱ�ٹ�������!";

		if (!error.empty())
			throw out_of_range(error);
		
		return true;
	}
	void showEmail()
	{
		cout << email << endl;
	}
private:
	string email;
};

int main()
{
	Email email;
	try
	{
		email.getEmail();
		email.verifyEmail();
		email.showEmail();
		cout << "ע��ɹ�!" << endl;
	}
	catch (exception &e)
	{
		cout << e.what() << endl;
	}

	system("pause");
	return 0;
}