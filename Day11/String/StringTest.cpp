#include <iostream>
#include <string>
#include <algorithm>

using namespace std;


void string_find_test()
{
	string s = "abcadefga";
	cout << s.find('a') << endl;	//从头部开始查找指定字符或字符串
	cout << s.rfind('a') << endl;	//从尾部开始查找
	cout << s.max_size() << endl;	//返回字符串最大可容纳字符个数

	//逆向迭代器（reverse_iterator），从字符串尾部开始，直到字符串第一个元素的前一个元素结束，beg++代表后移
	for (reverse_iterator<string::iterator> beg = s.rbegin(), End = s.rend(); beg != End; beg++)
		cout << *beg << ' ';
	cout << endl;

	s.resize(10);					//重新设置字符串大小(新字符串大小如果比原大小要大，那么多余空间以空格填充。如果比原大小要小则从尾部开始逐个消除相差个数的字符)
	cout << (s += "?") << endl;

	s.replace(1, 5, "lala");		//字符串替换，从第一个参数位置开始，直到第二参数结束，将范围内字符替换为指定字符
	cout << s << endl;

	cout << s.substr(3, 5) << endl;	//截取子串，从第一个参数位置开始，截取第二个参数所指定的字符串（不传默认截取至尾部）
		
	s.insert(2, "Test");			//插入字符串，在第一个参数的位置后面插入指定字符串或字符
	cout << s << endl;

	s.erase(3, 3);					//删除字符串，在第一个参数位置开始，删除第二个参数指定个数的字符（调用空参删除全部字符。传入一个参数则从参数位置删除，直至字符串尾部）
	cout << s << endl;

	transform(s.begin(), s.end(), s.begin(), toupper);
	cout << s << endl;
}

void string_toupper(string &str, const char *s)
{
	size_t index = 0;
	string::iterator p;
	size_t len = strlen(s);
	while ((index = str.find(s, index)) != string::npos)
	{
		p = str.begin() + index;
		transform(p, p + len, p, toupper);
	}
}

int main()
{
	//string_find_test();
	string str("aaa bbbsssaaa aaa cccaaa");
	string_toupper(str, "aaa");
	cout << str << endl;

	system("pause");
	return 0;
}