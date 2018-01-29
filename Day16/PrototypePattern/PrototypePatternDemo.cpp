#include <iostream>
#include <string>

using namespace std;

class Person
{
public:
	Person(string name, int age) : mName(name), mAge(age) {}
	virtual ~Person() {}
	virtual Person* clone() = 0;
	virtual void showInfo() = 0;

protected:
	int mAge;
	string mName;
};

class Student : public Person
{
public:
	Student() : Person(" ", 0), mNum(0) {}
	Student(string name, int age, int num, const char *test) : Person(name, age)
	{
		mNum = num;
		if (test != nullptr)
		{
			int len = strlen(test) + 1;
			mTest = new char[len];
			strcpy_s(mTest, len, test);
		}
	}
	virtual Person* clone()
	{
		Student *temp = new Student;
		*temp = *this;
		return temp;
		//return new Student(*this);
	}
	virtual void showInfo()
	{
		cout << "ÐÕÃû£º" << mName << endl;
		cout << "ÄêÁä£º" << mAge << endl;
		cout << "±àºÅ£º" << mNum << endl;
		cout << "Test:" << mTest << endl;
	}
	Student(const Student &stu) : Person(stu.mName, stu.mAge)
	{
		mNum = stu.mNum;
		if (stu.mTest != nullptr)
		{
			int len = strlen(stu.mTest) + 1;
			mTest = new char[len];
			strcpy_s(mTest, len, stu.mTest);
		}
	}
	~Student()
	{
		if (mTest != nullptr)
		{
			delete mTest;
			mTest = nullptr;
		}
	}
	Student* operator=(const Student &stu)
	{
		mName = stu.mName;
		mAge = stu.mAge;
		mNum = stu.mNum;
		if (mTest != nullptr)
		{
			delete mTest;
			mTest = nullptr;
		}
		if (stu.mTest != nullptr)
		{
			int len = strlen(stu.mTest) + 1;
			mTest = new char[len];
			strcpy_s(mTest, len, stu.mTest);
		}
		return this;
	}

private:
	int mNum;
	char *mTest = nullptr;
};

int main()
{
	Person *stu = new Student("test", 10, 100, "aaaaa");
	Person *newStu = stu->clone();

	stu->showInfo();
	newStu->showInfo();

	delete stu;
	delete newStu;

	system("pause");
	return 0;
}