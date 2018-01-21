#pragma once
#include <iterator>
#include <cstdlib>

template<class T> class MyArray;
template<class T> std::ostream& operator<<(std::ostream &out, MyArray<T> &myArray);

template<class T>
class MyArray
{
public:
	MyArray(const unsigned int length)
	{
		this->length = length;
		this->array = new T[this->length];
	}
	MyArray(const MyArray<T> &arrayT)
	{
		this->length = arrayT.length;
		this->array = new T[this->length];
		for (unsigned int i = 0; i < this->length; i++)
		{
			array[i] = arrayT.array[i];
		}
	}
	~MyArray()
	{
		if (array != nullptr)
		{
			delete[] array;
		}
	}
	int getLength()
	{
		return this->length;
	}
	MyArray<T>& operator=(const MyArray<T> &ArrayT)
	{
		if (this->array != nullptr)
		{
			delete[] this->array;
			this->array = nullptr;
		}
		this->length = ArrayT.length;
		this->array = new T[this->length];
		for (unsigned int i = 0; i < this->length; i++)
		{
			this->array[i] = ArrayT.array[i];
		}
		return *this;
	}
	T& operator[](const unsigned int index)
	{
		if (array != nullptr && index < length)
			return array[index];
		return *array;
	}
	T& operator*()
	{
		if (array != nullptr)
			return *array;
		else
			return nullptr;
	}
	T* operator-(const unsigned int index)
	{
		if (array != nullptr)
			return array - index;
	}
	T* operator+(const unsigned int index)
	{
		if (array != nullptr)
			return array + index;
		else
			return nullptr;
	}
	friend std::ostream& operator<<<T>(std::ostream &out, MyArray<T> &myArray);

private:
	unsigned int length;
	T *array;
};

template<class T>
std::ostream& operator<<(std::ostream &out, MyArray<T> &myArray)
{
	int len = myArray.length;
	for (int i = 0; i < len; i++)
	{
		out << myArray[i] << " ";
	}
	return out;
}