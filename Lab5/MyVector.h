#ifndef MyVector_h
#define MyVector_h

#include <iostream>
#include <initializer_list>

template<typename T> 
class MyVector
{
	class Invalid{};
	int sz;
	bool overw;
	int occupied;
	T *v;
public:
		explicit MyVector(int size = 0);
		MyVector(std::initializer_list<T> lst);
		MyVector(const MyVector& v2);
		MyVector(MyVector&& v2);
		int size() const;
		T& operator[](int i) const;
		MyVector& operator=(const MyVector& v2);
		MyVector& operator=(MyVector&& v2);
		T& at(int i) const;
		void safe_set(const T& el);
		void push_back(const T& el);
		T pop_back();
		void reserve(int size);
		T safe_get(int i) const;
		~MyVector() { delete[] v; v = nullptr; }
	private:
		bool is_overwritten() const { return overw; };
		void resize(int size);
};
#include "MyVector.hpp"
#endif