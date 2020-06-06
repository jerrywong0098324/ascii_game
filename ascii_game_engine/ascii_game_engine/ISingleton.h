// Base singleton class for implementation
#ifndef ISINGLETON_H
#define ISINGLETON_H

#include "SingletonManager.h"

// abstract class, implementation for Singleton
class ISingleton
{
public:
	ISingleton(ISingleton const&) = delete;
	ISingleton& operator=(ISingleton const&) = delete;

	virtual void free_memory() = 0;

protected:
	ISingleton() { SingletonManager::AddInstance(this); };
	virtual ~ISingleton() = 0 {};
};

#endif 