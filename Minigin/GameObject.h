#pragma once
#include <memory>
#include "Transform.h"
#include <vector>
#include <iostream>

namespace dae
{
	class Texture2D;
	class BaseComponent;
	class RenderComponent;
	class UpdateComponent;
	
	class GameObject final 
	{
	public:
		virtual void Update();
		virtual void Render() const;

		void SetTexture(const std::string& filename);
		void SetPosition(float x, float y);

		template<typename T> T* AddComponent();
		template<typename T> T* GetComponent() const;
		template<typename T> void RemoveComponent();

		GameObject() = default;
		virtual ~GameObject();
		GameObject(const GameObject& other) = delete;
		GameObject(GameObject&& other) = delete;
		GameObject& operator=(const GameObject& other) = delete;
		GameObject& operator=(GameObject&& other) = delete;

	private:
		std::vector<std::shared_ptr<UpdateComponent>> m_pUpdateComponents;
		std::vector<std::shared_ptr<RenderComponent>> m_pRenderComponents;
		
		Transform m_transform{};
		std::shared_ptr<Texture2D> m_texture{};
	};

	template<typename T>
	inline T* GameObject::AddComponent()
	{
		auto pComponent = std::make_shared<T>();
		if (std::is_base_of(UpdateComponent,T))
		{
			m_pUpdateComponents.push_back(pComponent);
		}
		else if (std::is_base_of(RenderComponent, T))
		{
			m_pRenderComponents.push_back(pComponent);
		}
		else
		{
			std::cout << "added not a component, wrong type";
		}
		return pComponent;
	}
	template<typename T>
	inline T* GameObject::GetComponent() const
	{
		return nullptr;
	}
	template<typename T>
	inline void GameObject::RemoveComponent()
	{
	}
}
