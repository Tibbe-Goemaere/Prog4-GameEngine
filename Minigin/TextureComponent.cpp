#include <stdexcept>
#include <SDL_ttf.h>
#include "TextureComponent.h"
#include "Renderer.h"
#include "Font.h"
#include "Texture2D.h"
#include "ResourceManager.h"

dae::TextureComponent::TextureComponent(std::shared_ptr<GameObject>pOwner)
	:BaseComponent(pOwner)
{ 
}


void dae::TextureComponent::Render() const
{
	if (m_pTexture != nullptr)
	{
		const auto& pos = m_Transform.GetPosition();
		Renderer::GetInstance().RenderTexture(*m_pTexture, pos.x, pos.y);
	}
}

void dae::TextureComponent::Update(const float)
{
}

void dae::TextureComponent::SetTexture(const std::string& filename)
{
	m_pTexture = ResourceManager::GetInstance().LoadTexture(filename);
}

void dae::TextureComponent::SetPosition(float x, float y)
{
	m_Transform.SetPosition(x, y, 0.0f);
}