#include "FileIO.h"
#include <sstream>
#include <list>
#include <forward_list>
#include <deque>

int main()
{
	std::list<std::string> info;
	std::vector<int> a;
	std::vector<int> b = a.begin();
	for (std::string str; std::cin >> str; info.push_back(str));
	for (const auto s : info) std::cout << s << std::endl;

	//std::ifstream input("F:/a.txt");
	//if (!input)
	//	std::cerr << "文件不存在" << std::endl;
	//std::vector<std::string> svec;
	///*readline(input, svec);*/
	//readword(input, svec);
	//for (const std::string &str : svec)
	//	std::cout << str << std::endl;

	system("pause");
	return 0;
}