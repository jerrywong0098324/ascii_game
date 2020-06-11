// Base singleton class for implementation
#ifndef ISINGLETON_H
#define ISINGLETON_H

#include "SingletonManager.h"

// abstract class, implementation for Singleton
class ISingleton
{
protected:
	// Making SingletonManager a friend so that no one else can call free_memory
	friend class SingletonManager;
	ISingleton() { SingletonManager::AddInstance(this); };
	virtual ~ISingleton() = 0 {};

	// Copy Constructor
	ISingleton(ISingleton const&) = delete;
	// lvalue assignment
	ISingleton& operator=(ISingleton const&) = delete;
	// Move Constructor
	ISingleton(ISingleton&&) = delete;
	// rvalue assignment
	ISingleton& operator=(ISingleton&&) = delete;

	virtual void alloc_memory() = 0 {};
	virtual void free_memory() = 0 {};
};

#endif 