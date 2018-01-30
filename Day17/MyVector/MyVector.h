#pragma once

using sizeType = unsigned int;

template<class TYPE>
class MyVector
{
public:
	class iterator
	{
	public:
		friend class MyVector<TYPE>;
		TYPE& operator*()
		{
			return *mPtr;
		}
		TYPE& operator[](sizeType pos)
		{
			return *(mPtr + pos);
		}
		TYPE* operator->()
		{
			return mPtr;
		}
		typename MyVector<TYPE>::iterator operator++(int)
		{
			return mPtr++;
		}
		typename MyVector<TYPE>::iterator& operator++()
		{
			++mPtr;
			return *this;
		}
		typename MyVector<TYPE>::iterator operator--(int)
		{
			return mPtr--;
		}
		typename MyVector<TYPE>::iterator& operator--()
		{
			--mPtr;
			return *this;
		}
		typename MyVector<TYPE>::iterator operator+(sizeType pos)
		{
			TYPE *p = mPtr + pos;
			return  + p;
		}
		typename MyVector<TYPE>::iterator operator-(sizeType pos)
		{
			
			return mPtr - pos;
		}
		int operator-(typename MyVector<TYPE>::iterator it)
		{
			return mPtr - it.mPtr;
		}
		bool operator!=(typename MyVector<TYPE>::iterator it)
		{
			return mPtr != it.mPtr;
		}
		bool operator==(typename MyVector<TYPE>::iterator it)
		{
			return mPtr == it.mPtr;
		}
		iterator(const typename MyVector<TYPE>::iterator &it)
		{
			this->mPtr = it.mPtr;
		}
		void operator=(const typename MyVector<TYPE>::iterator &it)
		{
			this->mPtr = it.mPtr;
		}

	private:
		iterator(TYPE *ptr)
		{
			this->mPtr = ptr;
		}
		TYPE* ptr()
		{
			return mPtr;
		}
		TYPE * mPtr;
	};
	MyVector() : mArray(new TYPE[10])
	{
		mCapacity = 10;
		mSize = 0;
		
	}

	MyVector(sizeType size, TYPE value) : mArray(new TYPE[size])
	{
		mCapacity = size;
		mSize = size;
		for (typename MyVector<TYPE>::iterator beg = this->begin(), END = this->end(); beg != END; ++beg)
		{
			*beg = value;
		}
	}

	~MyVector()
	{
		delete mArray.ptr();
		mCapacity = 0;
		mSize = 0;
	}

	//β�����Ԫ��
	void push_back(const TYPE &value)
	{
		isUpCapacity();
		mArray[mSize++] = value;
	}

	//β��ɾ��Ԫ��
	void pop_back()
	{
		--mSize;
	}

	//����Ԫ��
	void insert(typename MyVector<TYPE>::iterator loc, const TYPE value)
	{
		sizeType beg = loc - mArray, End = mSize;
		if (mSize == mCapacity)
		{
			mCapacity *= 2;
			typename MyVector<TYPE>::iterator temp(new TYPE[mCapacity]);
			for (sizeType i = 0; i < mSize; ++i)
			{
				temp[i] = mArray[i];
			}
			while (beg != End)
			{
				temp[End] = temp[End - 1];
				--End;
			}
			delete mArray.ptr();
			mArray = temp;
		}
		else
		{
			while (beg != End)
			{
				mArray[End] = mArray[End - 1];
				--End;
			}
		}
		mArray[End] = value;
		++mSize;
	}

	//���
	void clear()
	{
		mSize = 0;
	}

	//��������
	sizeType capacity()
	{
		return mCapacity;
	}

	//���ش�С
	sizeType size()
	{
		return mSize;
	}

	//����ĩ��Ԫ��
	TYPE back()
	{
		if (mSize == 0)
			throw exception("Ԫ��Ϊ��!");
		return *(mArray + (mSize - 1));
	}

	//������Ԫ��
	TYPE front()
	{
		if (mSize == 0)
			throw exception("Ԫ��Ϊ��!");
		return *mArray;
	}

	//��ȡָ��λ��Ԫ��
	TYPE at(sizeType loc)
	{
		if (loc >= mSize)
			throw exception("�Ƿ�����Ԫ��!");
		return *(mArray + loc);
	}

	//�ж��Ƿ�Ϊ��
	bool empty()
	{
		return mSize == 0;
	}

	//ɾ��ָ��λ��Ԫ��
	typename MyVector<TYPE>::iterator erase(typename MyVector<TYPE>::iterator loc)
	{
		typename MyVector<TYPE>::iterator END = this->end() - 1;
		while (loc - 1 != END)
		{
			*loc = *(loc + 1);
			++loc;
		}
		--mSize;
		return loc;
	}

	//������Ԫ�ص�����
	typename MyVector<TYPE>::iterator begin()
	{
		return mArray + 0;
	}

	//����ĩ����һ��λ�õĵ�����
	typename MyVector<TYPE>::iterator end()
	{
		return mArray + 0 + mSize;
	}

	//��ӡԪ��
	void printArray()
	{
		for (sizeType i = 0; i < mSize; ++i)
		{
			cout << mArray[i] << ' ';
		}
		cout << endl;
		cout << "size:" << mSize << endl;
		cout << "capacity:" << mCapacity << endl;
	}

private:
	void isUpCapacity()
	{
		if (mSize == mCapacity)
		{
			mCapacity *= 2;
			typename MyVector<TYPE>::iterator temp(new TYPE[mCapacity]);
			for (sizeType i = 0; i < mSize; ++i)
			{
				temp[i] = mArray[i];
			}
			delete mArray.ptr();
			mArray = temp;
		}
	}
	typename MyVector<TYPE>::iterator mArray;
	sizeType mCapacity;
	sizeType mSize;
};

