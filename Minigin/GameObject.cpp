#include <string>
#include "GameObject.h"
#include "ResourceManager.h"
#include "Renderer.h"
#include "RenderComponent.h"
#include "UpdateComponent.h"

dae::GameObject::~GameObject() = default;

void dae::GameObject::Update()
{
	for (const auto& updateComponent : m_pUpdateComponents)
	{
		updateComponent->Update();
	}
	for (const auto& renderComponent : m_pRenderComponents)
	{
		renderComponent->Update();
	}
}

void dae::GameObject::Render() const
{
	for (const auto& renderComponent : m_pRenderComponents)
	{
		renderComponent->Render();
	}
	//const auto& pos = m_transform.GetPosition();
	//Renderer::GetInstance().RenderTexture(*m_texture, pos.x, pos.y);
}

void dae::GameObject::SetTexture(const std::string& filename)
{
	m_texture = ResourceManager::GetInstance().LoadTexture(filename);
}

void dae::GameObject::SetPosition(float x, float y)
{
	m_transform.SetPosition(x, y, 0.0f);
}
