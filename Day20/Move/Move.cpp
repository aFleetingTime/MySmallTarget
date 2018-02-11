#include <iostream>
#include <cstdlib>
//#include <wincon.h>
#include <string>
#include <sstream>
#include <Windows.h>
#include <fstream>
#include <vector>

using namespace std;

int getMaxLen(vector<string> &, int);

int main()
{
	////COORD coord{ 0,0 };
	////HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);

	////HANDLE console = CreateConsoleScreenBuffer(GENERIC_WRITE | GENERIC_READ, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
	////CONSOLE_CURSOR_INFO cci;
	////cci.bVisible = 0;
	////cci.dwSize = 1;

	////SetConsoleCursorInfo(console, &cci);
	////SetConsoleCursorInfo(output, &cci);

	////SetConsoleActiveScreenBuffer(console);
	//DWORD bytes = 0;

	////获取默认标准显示缓冲区句柄
	//HANDLE hOutput;
	//COORD coord = { 0,0 };
	//hOutput = GetStdHandle(STD_OUTPUT_HANDLE);

	////创建新的缓冲区
	//HANDLE hOutBuf = CreateConsoleScreenBuffer(
	//	GENERIC_READ | GENERIC_WRITE,
	//	FILE_SHARE_READ | FILE_SHARE_WRITE,
	//	NULL,
	//	CONSOLE_TEXTMODE_BUFFER,
	//	NULL
	//);

	////设置新的缓冲区为活动显示缓冲
	//SetConsoleActiveScreenBuffer(hOutBuf);

	////隐藏两个缓冲区的光标
	//CONSOLE_CURSOR_INFO cci;
	//cci.bVisible = 0;
	//cci.dwSize = 1;
	//SetConsoleCursorInfo(hOutput, &cci);
	//SetConsoleCursorInfo(hOutBuf, &cci);

	int line = 0;
	vector<string> train;
	ifstream ifs("./info.txt", ios::in);
	;
	for (char chBuf[1024]{}; ifs.getline(chBuf, 1024); train.push_back(chBuf), ++line);

 //   string train[line] = {
 //        {"    .---- -. -. .  .   ."},
 //        {"    \\_/      ;--:-          __--------------------__"},
 //        {"  __U__n_^_''__[.  ooo___  | |_!_||_!_||_!_||_!_| |]"},
 //        {"c(_ ..(_ ..(_ ..( /,,,,,,] | |___||___||___||___| |"},
 //        {",_\\___________'_|,L______],|______________________|"},
 //        {"/;_(@)(@)==(@)(@)   (o)(o)      (o)^(o)--(o)^(o)   "}
	//};

    stringstream buf;
	
    for (int i = 129, count = 1; i >= 0; --i, ++count)
    {
         system("cls");
         for (int j = 0; j < line; ++j)
         {
             int t = train[j].size();
             int len = t - count;
             if (len < 0)
                 len = 0;
             for (int y = 0; y < i; ++y)
                 buf << ' ';
             for (auto beg = train[j].begin(), End = train[j].end() - len; beg != End; ++beg)
                 buf << *beg;
             buf << endl;
         }
		 cout << buf.str().c_str() << endl;
		 buf.str("");
         buf.clear();
         Sleep(1);
    }

    size_t maxlen = getMaxLen(train, line);
	for (size_t i = 0; i < maxlen; ++i)
    {
       system("cls");
       for (int j = 0; j < line; ++j)
       {
           if (i > train[j].size())
                 goto CONTINUE;
           for (auto beg = train[j].begin() + i; beg != train[j].end(); ++beg)
                 buf << *beg;
 CONTINUE:
             buf << endl;
         }
         cout << buf.str().c_str() << endl;
         buf.str("");
         Sleep(1);
    }
    system("cls");
    return 0;
}

int getMaxLen(vector<string> &array, int len)
{
	    int maxIndex = 0;
	    for (int i = 0; i < len; ++i)
	    {
	        if (array[maxIndex].size() < array[i].size())
	             maxIndex = i;
	    }
	    return array[maxIndex].size();
}