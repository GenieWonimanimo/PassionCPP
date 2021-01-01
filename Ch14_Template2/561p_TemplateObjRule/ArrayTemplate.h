#ifndef __ARRAY_TEMPLATE_H_
#define __ARRAY_TEMPLATE_H_

#include <iostream>
#include <cstdlib>
using namespace std;

template <typename T>
class BoundCheckArray
{
private:
	T* arr;
	int arrlen;
	BoundCheckArray(const BoundCheckArray& ref) { }
	BoundCheckArray& operator=(const BoundCheckArray& arr) { }
public:
	BoundCheckArray(int len);
	T& operator[] (int idx);
	T operator[] (int idx) const;
	int GetArrLen() const { return arrlen; }
	~BoundCheckArray() { delete[]arr; }
};

template <typename T>
BoundCheckArray<T>::BoundCheckArray(int len)
{
	arr = new T[len];
	arrlen = len;
}

template <typename T>
T& BoundCheckArray<T>::operator[] (int idx)
{
	if (idx < 0 || idx >= arrlen)
		exit(1);
	return arr[idx];
}
template <typename T>
T BoundCheckArray<T>::operator[] (int idx) const
{
	if (idx < 0 || idx >= arrlen)
		exit(1);
	return arr[idx];
}

#endif