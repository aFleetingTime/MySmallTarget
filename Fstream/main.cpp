#include "FileIO.h"
#include <sstream>

int main()
{
	std::ifstream input("F:/a.txt");
	if (!input)
		std::cerr << "�ļ�������" << std::endl;
	std::vector<std::string> svec;
	/*readline(input, svec);*/
	readword(input, svec);
	for (const std::string &str : svec)
		std::cout << str << std::endl;

	system("pause");
	return 0;
}