// Manager class that manage creating Print 'maps' to use has render
#ifndef RENDERER_MANAGER_H
#define RENDERER_MANAGER_H

#include "Singleton.h"
#include <vector>

class RendererManager : public Singleton<RendererManager>
{
public:
	char** GetPrint();
	// Called when end or change of level
	void Exit();

	virtual void free_memory();

private:
	// Singleton definition
	friend class Singleton<RendererManager>;
	RendererManager();
	~RendererManager();

	void DeletePrints();
	std::vector<char**> prints; // used to free memory
};

#endif