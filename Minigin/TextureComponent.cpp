#include <stdexcept>
#include <SDL_ttf.h>
#include "TextureComponent.h"
#include "Renderer.h"
#include "Font.h"
#include "Texture2D.h"
#include "ResourceManager.h"

dae::TextureComponent::TextureComponent(const std::string filename, float xPos, float yPos)
	:m_pTexture{ ResourceManager::GetInstance().LoadTexture(filename) }
{ 
	m_transform.SetPosition(xPos,yPos,0.0f);
}


void dae::TextureComponent::Render() const
{
	if (m_pTexture != nullptr)
	{
		const auto& pos = m_transform.GetPosition();
		Renderer::GetInstance().RenderTexture(*m_pTexture, pos.x, pos.y);
	}
}

void dae::TextureComponent::Update([[maybe_unused]] const float dt)
{
}


