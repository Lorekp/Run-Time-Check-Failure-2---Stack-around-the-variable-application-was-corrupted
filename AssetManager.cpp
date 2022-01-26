#include "AssetManager.h"
#include <assert.h>

AssetManager* AssetManager::sInstance = nullptr;

AssetManager::AssetManager()
{
	//Only allow one AssetManager to exist otherwise throw an exception
	assert(sInstance == nullptr);
	sInstance = this;
}