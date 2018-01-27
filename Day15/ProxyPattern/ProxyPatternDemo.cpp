#include <iostream>
#include <string>

using namespace std;

class AbstractSystemInterface
{
public:
	virtual void run() = 0;
};

class System : public AbstractSystemInterface
{
public:
	virtual void run()
	{
		cout << "系统运行" << endl;
	}
};

class SystemProxy : public AbstractSystemInterface
{
public:
	SystemProxy(string username, string password)
	{
		mUsername = username;
		mPassword = password;
	}
	virtual void run()
	{
		if (check())
		{
			cout << "验证通过" << endl;
			system.run();
		}
		else
		{
			cout << "用户名或密码错误!" << endl;
		}
	}

private:
	bool check()
	{
		return !mUsername.compare("root") && !mPassword.compare("123456");
	}
	string mUsername;
	string mPassword;
	static System system;
};
System SystemProxy::system;

int main()
{
	SystemProxy sp1("a", "66");
	sp1.run();

	SystemProxy sp2("root", "123456");
	sp2.run();

	system("pause");
	return 0;
}