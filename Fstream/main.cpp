#include "FileIO.h"

int main()
{
	std::vector<std::string> svec;
	std::ifstream input("F:/a.txt");
	if (!input)
		std::cerr << "�ļ�������" << std::endl;
	/*readline(input, svec);*/
	readword(input, svec);
	for (const std::string &str : svec)
		std::cout << str << std::endl;

	system("pause");
	return 0;
}