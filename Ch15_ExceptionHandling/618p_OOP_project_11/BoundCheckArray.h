/*
 * 파일이름: BoundCheckArray.h
 * 작성자: 박지원
 * 업데이트 정보: [2020, 12, 6] 파일버전 0.12
 */
#ifndef __BOUND_CHECK_ARRAY_H__
#define __BOUND_CHECK_ARRAY_H__
#define _CRT_SECURE_NO_WARNINGS

template <typename T>
class BoundCheckArray
{
private:
	T* arr;
	int arrlen;
	BoundCheckArray(const BoundCheckArray& arr) { }
	BoundCheckArray& operator=(const BoundCheckArray& arr) { }
public:
	BoundCheckArray(int len = 100);
	T& operator[] (int idx);
	T operator[] (int idx) const;
	int GetArrLen() const { return arrlen; }
	~BoundCheckArray();
};

template <typename T>
BoundCheckArray<T>::BoundCheckArray(int len)
	: arrlen(len)
{
	arr = new T[len];
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

template <typename T>
BoundCheckArray<T>::~BoundCheckArray()
{
	delete[]arr;
}

#endif