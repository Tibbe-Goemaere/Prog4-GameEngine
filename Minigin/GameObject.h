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

		void SetTexture(const std::string& filename);
		void SetPosition(float x, float y);

		void AddComponent(std::shared_ptr<BaseComponent> component);

		GameObject() = default;
		virtual ~GameObject();
		GameObject(const GameObject& other) = delete;
		GameObject(GameObject&& other) = delete;
		GameObject& operator=(const GameObject& other) = delete;
		GameObject& operator=(GameObject&& other) = delete;

	private:
		std::vector<std::shared_ptr<BaseComponent>> m_pComponents;
		
		Transform m_transform{};
		std::shared_ptr<Texture2D> m_texture{};
	};

	
	inline void GameObject::AddComponent(std::shared_ptr<BaseComponent> component)
	{
		m_pComponents.push_back(component);
	}
}
