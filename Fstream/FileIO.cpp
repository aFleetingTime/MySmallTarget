#include "FileIO.h"

std::istream &readline(std::istream &is, std::vector<std::string> &svec)
{
	std::string buf;
	while (getline(is, buf))
		svec.push_back(buf);
	return is;
}

std::istream &readword(std::istream &is, std::vector<std::string> &svec)
{
	std::string buf;
	while (is >> buf)
		svec.push_back(buf);
	return is;
}