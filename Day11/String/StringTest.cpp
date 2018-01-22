#include <iostream>
#include <string>
#include <algorithm>

using namespace std;


void string_find_test()
{
	string s = "abcadefga";
	cout << s.find('a') << endl;	//��ͷ����ʼ����ָ���ַ����ַ���
	cout << s.rfind('a') << endl;	//��β����ʼ����
	cout << s.max_size() << endl;	//�����ַ������������ַ�����

	//�����������reverse_iterator�������ַ���β����ʼ��ֱ���ַ�����һ��Ԫ�ص�ǰһ��Ԫ�ؽ�����beg++�������
	for (reverse_iterator<string::iterator> beg = s.rbegin(), End = s.rend(); beg != End; beg++)
		cout << *beg << ' ';
	cout << endl;

	s.resize(10);					//���������ַ�����С(���ַ�����С�����ԭ��СҪ����ô����ռ��Կո���䡣�����ԭ��СҪС���β����ʼ����������������ַ�)
	cout << (s += "?") << endl;

	s.replace(1, 5, "lala");		//�ַ����滻���ӵ�һ������λ�ÿ�ʼ��ֱ���ڶ���������������Χ���ַ��滻Ϊָ���ַ�
	cout << s << endl;

	cout << s.substr(3, 5) << endl;	//��ȡ�Ӵ����ӵ�һ������λ�ÿ�ʼ����ȡ�ڶ���������ָ�����ַ���������Ĭ�Ͻ�ȡ��β����
		
	s.insert(2, "Test");			//�����ַ������ڵ�һ��������λ�ú������ָ���ַ������ַ�
	cout << s << endl;

	s.erase(3, 3);					//ɾ���ַ������ڵ�һ������λ�ÿ�ʼ��ɾ���ڶ�������ָ���������ַ������ÿղ�ɾ��ȫ���ַ�������һ��������Ӳ���λ��ɾ����ֱ���ַ���β����
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