#pragma once
#include <memory>
#include "Transform.h"
#include <vector>
#include <iostream>

namespace dae
{
	class BaseComponent;
	
	class GameObject final : public std::enable_shared_from_this<GameObject>
	{
	public:
		void Update(const float dt);
		void Render() const;

		template<typename T>  std::shared_ptr<T> AddComponent();

		template<typename T> void RemoveComponent();

		template<typename T> std::shared_ptr<T> GetComponent() const;

		GameObject() = default;
		~GameObject();
		GameObject(const GameObject& other) = delete;
		GameObject(GameObject&& other) = delete;
		GameObject& operator=(const GameObject& other) = delete;
		GameObject& operator=(GameObject&& other) = delete;

		std::shared_ptr<GameObject> GetParent();
		void SetParent(std::shared_ptr<dae::GameObject> parent);
		int GetChildCount() const;

		std::shared_ptr<GameObject> GetChildAt(const int idx);
		void AddChild(std::shared_ptr<dae::GameObject> pChild);
		void RemoveChild(std::shared_ptr<dae::GameObject> pChild);

		const Transform& GetTransform() const;

	private:
		std::vector<std::shared_ptr<BaseComponent>> m_pComponents;

		std::shared_ptr<GameObject> m_pParent;
		std::vector<std::shared_ptr<GameObject>> m_pChildren;

		std::unique_ptr<Transform> m_pTransform;
	};

	template<typename T>
	std::shared_ptr<T> GameObject::AddComponent()
	{
		//check if we already have this component in the vector
		for (auto comp : m_pComponents)
		{
			auto componentOfTemplatedType = std::dynamic_pointer_cast<T>(comp);
			if (componentOfTemplatedType)
			{
				return componentOfTemplatedType;
			}
		}
		auto pComponent = std::make_shared<T>(weak_from_this());
		m_pComponents.push_back(pComponent);
		return pComponent;
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
		for (const auto& comp : m_pComponents)
		{
			if (typeid(*comp) == typeid(T))
			{
				return comp;
			}
		}
		return nullptr;
	}
}
