#pragma once
#include <string>

#include "TextureCache.h"
#include "ResourceCache.h"
#include "../Rendering/SpriteFont.h"
#include "../Audio/Sound.h"

namespace Artifact
{
    class ResourceManager
    {
    private:
        TextureCache m_TextureCache;
        ResourceCache<SpriteFont> m_FontCache;
        ResourceCache<Sound> m_SoundCache;

    private:
        ResourceManager() = default;

	public:
		static ResourceManager& getInstance();
        GLTexture* getTexture(const std::string& a_FilePath);
        SpriteFont* getFont(const std::string& a_FilePath);
        Sound* getSound(const std::string& a_FilePath);
    };
}