#ifndef SINGLETON_H
#define SINGLETON_H

#include "ISingleton.h"

// template class for any singleton design pattern
template <typename T>
class Singleton : public ISingleton
{
public:
	static T *GetInstance()
	{
		if (!Singleton<T>::instance)
			Singleton<T>::instance = new T;
		return Singleton<T>::instance;
	}

	Singleton(Singleton const&) = delete;
	Singleton& operator=(Singleton const&) = delete;

	// function to be overloaded if necessary (to clear any additional pointers in the singleton class)
	virtual void free_memory();

protected:
	Singleton() {};
	~Singleton() {};

	static T *instance;
};

template<typename T>
T* Singleton<T>::instance = nullptr;

template <typename T>
void Singleton<T>::free_memory() // base function to delete instance from heap
{
	if (Singleton<T>::instance)
	{
		delete Singleton<T>::instance;
		Singleton<T>::instance = nullptr;
	}
}

#endif