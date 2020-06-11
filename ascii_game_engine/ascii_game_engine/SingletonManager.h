// Manager for all Singleton instances
#ifndef SINGLETON_MANAGER_H
#define SINGLETON_MANAGER_H

#include <vector>

// static class to call all singleton instance's free_memory (to clear up the memory)
class ISingleton;
class SingletonManager
{
public:
	static void AddInstance(ISingleton *instance);
	// free-ing all singleton instance's memory
	static void FreeAll();

private:
	SingletonManager();
	~SingletonManager();

	SingletonManager(SingletonManager const&) = delete;
	SingletonManager& operator=(SingletonManager const&) = delete;
	SingletonManager(SingletonManager&&) = delete;
	SingletonManager& operator=(SingletonManager&&) = delete;

	static std::vector<ISingleton*> singletons;
};

#endif 