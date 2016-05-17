#include <SDLMixer/SDL_mixer.h>

#include "ResourceManager.h"

namespace Artifact
{
	ResourceManager& ResourceManager::getInstance()
	{
		static ResourceManager instance;
		return instance;
	}

	GLTexture* ResourceManager::getTexture(const std::string& a_FilePath)
    {
        return m_TextureCache.getTexture(a_FilePath);
    }

    SpriteFont* ResourceManager::getFont(const std::string& a_FilePath)
    {
        const int FontResolution = 64;
        SpriteFont* fontHandle = nullptr;
        if(!m_FontCache.tryGetResource(a_FilePath, fontHandle))
        {
            fontHandle = m_FontCache.emplace(a_FilePath, std::make_unique<SpriteFont>(a_FilePath.c_str(),
                FontResolution));
        }
        return fontHandle;
    }

    Sound* ResourceManager::getSound(const std::string& a_FilePath)
    {
        Sound* soundHandle = nullptr;
        if(!m_SoundCache.tryGetResource(a_FilePath, soundHandle))
        {
            soundHandle = m_SoundCache.emplace(a_FilePath, std::make_unique<Sound>(a_FilePath));
        }
        return soundHandle;
    }
}