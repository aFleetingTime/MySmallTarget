#include <iostream>
#include <string>

template<class T>
class TemplateClassStatic
{
public:
	TemplateClassStatic()
	{
	}
	void show()
	{
		std::cout << a << std::endl;
	}
	
	static T a;
};

template<class T>
T TemplateClassStatic<T>::a = 0;