#include <iostream>
#include <initializer_list>

template<typename T> MyVector<T>::MyVector(int size): sz (size){
	overw = false;
	sz = size;
	occupied = size;
	v = new T[size];
	for (int i = 0; i < size; i++) v[i] = T();
	if (v == nullptr)
		throw Invalid();
}

template<typename T> MyVector<T>::MyVector(const MyVector<T>& v2){
	T *tmp = new T[v2.sz];
	std::copy(v2.v, v2.v+sz, tmp);
	delete[] v;
	v = tmp;
	sz = v2.sz;
	occupied = v2.occupied;
	overw = v2.overw;
}

template<typename T> MyVector<T>::MyVector(std::initializer_list<T> lst): sz{static_cast<int>(lst.size())}, v{new T[sz]} {
	std::copy(lst.begin(), lst.end(), v);
	occupied = sz;
}

template<typename T> MyVector<T>::MyVector(MyVector&& v2) : sz{v2.sz}, v{v2.v} {
	v2.sz = 0;
	v2.v = nullptr;
}

template<typename T> int MyVector<T>::size() const
{
	if(is_overwritten()) 
		return occupied;
	else
		return sz; 
}

template<typename T> void MyVector<T>::resize(int size){
	overw = true;
	T *tmp = new T[size];
	sz = size; 
	for (int i = 0; i < occupied; i++)
	{
		tmp[i] = v[i];
	}
	delete[] v;
	v = tmp;
}

template<typename T> T& MyVector<T>::operator[](int i) {
	return v[i];
}

template<typename T> T MyVector<T>::operator[](int i) const {
	return v[i];
}

template<typename T> MyVector<T>& MyVector<T>::operator=(const MyVector& v2) {
	T *tmp = new T[v2.sz];
	std::copy(v2.v, v2.v+sz, tmp);
	delete[] v;
	v = tmp;
	sz = v2.sz;
	occupied = v2.occupied;
	overw = v2.overw;
	return *this;
}

template<typename T> MyVector<T>& MyVector<T>::operator=(MyVector&& v2) {
	delete[] v;
	v = v2.v;
	sz = v2.sz;
	v2.v = nullptr;
	v2.sz = 0;
	return *this;
}

template<typename T> void MyVector<T>::push_back(const T& el) {
	if (sz == occupied)
	{
		resize(sz*2);
	}
	v[occupied++] = el;
}

template<typename T> void MyVector<T>::reserve(int size){
	if (size <= sz)
		return;
	
	resize(size);
};

template<typename T> T MyVector<T>::pop_back(){
	overw = 1;
	if (occupied == 0)
		throw Invalid();
	return v[--occupied];
};

template<typename T> void MyVector<T>::safe_set(const T& el){
	if (sz == occupied)
		throw Invalid();
	
	v[occupied++] = el;
}

template<typename T> T MyVector<T>::safe_get(int i) const
{
	if (i >= size())
		throw Invalid();
	
	return v[i];
}

template<typename T> T& MyVector<T>::at(int i) const {
	if (i >= occupied)
		throw Invalid();
	return v[i];
}