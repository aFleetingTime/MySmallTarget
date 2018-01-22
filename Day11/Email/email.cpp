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
		cout << "请输入邮箱:" << endl << ">>";
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
			error = "邮箱为空!";
		for (string::iterator beg = email.begin(), End = email.end(); beg != End; ++beg)
		{
			if (*beg == '.' || *beg == '@')
				continue;
			else if (!isalnum(*beg))
				throw out_of_range("不能包含敏感字符!");
		}
		if ((index = email.find('@')) == string::npos)
			error = "邮箱不能没有@符号!";
		else if (email.find('@', index + 1) != string::npos)
			error = "邮箱只能有一个@符号!";
		else if (email.at(index + 1) == '.' || (index = email.find('.', index + 2)) == string::npos)
			error = "缺少域名或.符号!";
		else if (email.find('.') != index)
			error = "含有多个.符号!";
		else if (!isalnum(email.at(0)))
			error = "缺少用户名!";
		else if (email.length() == email.find('.') + 1)
			error = "缺少国际域名!";

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
		cout << "注册成功!" << endl;
	}
	catch (exception &e)
	{
		cout << e.what() << endl;
	}

	system("pause");
	return 0;
}