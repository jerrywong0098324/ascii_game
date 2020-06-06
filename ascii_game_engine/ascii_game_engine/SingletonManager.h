// Manager for all Singleton instances
#ifndef SINGLETON_MANAGER_H
#define SINGLETON_MANAGER_H

#include <vector>

// static class to call all singleton instance's free_memory (to clear up the memory)
class ISingleton;
class SingletonManager
{
public:
	SingletonManager();
	~SingletonManager();

	static void AddInstance(ISingleton *instance);
	// free-ing all singleton instance's memory
	static void FreeAll();

private:
	static std::vector<ISingleton*> singletons;
};

#endif 