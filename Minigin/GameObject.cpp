#include <string>
#include "GameObject.h"
#include "ResourceManager.h"
#include "Renderer.h"
#include "BaseComponent.h"

dae::GameObject::~GameObject() = default;

void dae::GameObject::Update(const float dt)
{
	for (const auto& component : m_pComponents)
	{
		component->Update(dt);
	}
}

void dae::GameObject::Render() const
{
	for (const auto& component : m_pComponents)
	{
		component->Render();
	}
}

std::shared_ptr<dae::GameObject> dae::GameObject::GetParent()
{
	return m_pParent;
}

void dae::GameObject::SetParent(std::shared_ptr<dae::GameObject> pParent)
{
	pParent->RemoveChild(shared_from_this());
	m_pParent = pParent;
	m_pParent->AddChild(shared_from_this());
	m_pTransform->SetPosition(pParent->GetTransform().GetPosition().x, pParent->GetTransform().GetPosition().y, pParent->GetTransform().GetPosition().z);
}

int dae::GameObject::GetChildCount() const
{
	return static_cast<int>(m_pChildren.size());
}

std::shared_ptr<dae::GameObject> dae::GameObject::GetChildAt(const int idx)
{
	return m_pChildren[idx];
}

void dae::GameObject::AddChild(std::shared_ptr<dae::GameObject> pChild)
{
	pChild->GetParent()->RemoveChild(pChild);
	pChild->SetParent(shared_from_this()); 
	m_pChildren.push_back(pChild);
}

void dae::GameObject::RemoveChild(std::shared_ptr<dae::GameObject> pChild)
{
	m_pChildren.erase(std::remove(m_pChildren.begin(), m_pChildren.end(), pChild));
	pChild->SetParent(nullptr);
}

const dae::Transform& dae::GameObject::GetTransform() const
{
	return *m_pTransform;
}

