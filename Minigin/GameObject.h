#pragma once
#include <memory>
#include "Transform.h"
#include <vector>
#include <iostream>

namespace dae
{
	class Texture2D;
	class BaseComponent;
	
	class GameObject final 
	{
	public:
		virtual void Update(const float dt);
		virtual void Render() const;

		template<typename T> void AddComponent(std::shared_ptr<T> component);

		template<typename T> void RemoveComponent();

		template<typename T> std::shared_ptr<T> GetComponent() const;

		template<typename T> bool HasAddedComponent() const;

		GameObject() = default;
		virtual ~GameObject();
		GameObject(const GameObject& other) = delete;
		GameObject(GameObject&& other) = delete;
		GameObject& operator=(const GameObject& other) = delete;
		GameObject& operator=(GameObject&& other) = delete;

	private:
		std::vector<std::shared_ptr<BaseComponent>> m_pComponents;
	};

	template<typename T>
	inline void GameObject::AddComponent(std::shared_ptr<T> component)
	{
		for (auto comp : m_pComponents)
		{
			if (typeid(*comp) == typeid(*component))
			{
				return;
			}
		}
		m_pComponents.push_back(component);
	}

	template<typename T>
	inline void GameObject::RemoveComponent()
	{
		for (auto comp : m_pComponents)
		{
			if (typeid(*comp) == typeid(T))
			{
				m_pComponents.erase(std::remove(m_pComponents.begin(), m_pComponents.end(), comp));
				return;
			}
		}
	}

	template<typename T>
	inline std::shared_ptr<T> GameObject::GetComponent() const
	{
		for (auto comp : m_pComponents)
		{
			if (typeid(*comp) == typeid(T))
			{
				return comp;
			}
		}
		return nullptr;
	}

	template<typename T>
	inline bool GameObject::HasAddedComponent() const
	{
		for (auto comp : m_pComponents)
		{
			if (typeid(*comp) == typeid(T))
			{
				return true;
			}
		}
		return false;
	}
}
