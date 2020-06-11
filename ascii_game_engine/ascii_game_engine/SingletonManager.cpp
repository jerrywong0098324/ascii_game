#include "SingletonManager.h"
#include "ISingleton.h"

std::vector<ISingleton*> SingletonManager::singletons;

SingletonManager::SingletonManager()
{

}

SingletonManager::~SingletonManager()
{

}

void SingletonManager::AddInstance(ISingleton *instance)
{
	SingletonManager::singletons.push_back(instance);
}

// free-ing all singleton instance's memory
void SingletonManager::FreeAll()
{
	for (int i = 0; i < SingletonManager::singletons.size(); ++i)		
		SingletonManager::singletons[i]->free_memory(); // frees the memory
}