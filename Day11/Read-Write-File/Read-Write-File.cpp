#include <iostream>
#include <fstream>
#include <stdexcept>

using namespace std;
class MyReadWriteFile
{
public:
	MyReadWriteFile(const char *source, const char *target)
	{
		sourcePath = source;
		targetPath = target;
	}
	void copyFile()
	{
		if (sourcePath == nullptr)
			throw invalid_argument("源文件路径为空!");
		else if (targetPath == nullptr)
			throw invalid_argument("目标文件路径为空!");

		ifstream ifs(sourcePath, ios::in);
		ofstream ofs(targetPath, ios::out);

		char buf[1024] = {};
		int len = sizeof(buf) / sizeof(*buf);
		streamsize size;

		while (ifs >> buf)
		{
			ofs << buf;
			if (!ifs.eof())
				ofs << endl;
		}

		ifs.close();
		ofs.close();
	}
	void setSource(const char *source)
	{
		sourcePath = source;
	}
	void setTarget(const char *target)
	{
		targetPath = target;
	}
private:
	const char *sourcePath;
	const char *targetPath;
};

int main()
{
	MyReadWriteFile rwf("F:\\MyC++\\MySmallTarget\\Day11\\Read-Write-File\\TestFile\\source.txt", "F:\\MyC++\\MySmallTarget\\Day11\\Read-Write-File\\TestFile\\target.txt");
	try
	{
		rwf.copyFile();
	}
	catch (invalid_argument &e)
	{
		cout << e.what() << endl;
	}

	system("pause");
	return 0;
}