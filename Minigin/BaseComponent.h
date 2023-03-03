#pragma once
#include "Transform.h"
namespace dae
{
	class BaseComponent
	{
		GameObject* m_pOwner;
	public:
		BaseComponent(GameObject* pOwner) : m_pOwner(pOwner) {};
		virtual ~BaseComponent() = default;

		virtual void Update(const float dt) = 0;
		virtual void Render() const = 0;

		void SetOwner(GameObject* pOwner) { m_pOwner = pOwner; };

		BaseComponent(const BaseComponent& other) = delete;
		BaseComponent(BaseComponent&& other) = delete;
		BaseComponent& operator=(const BaseComponent& other) = delete;
		BaseComponent& operator=(BaseComponent&& other) = delete;

	protected:
		GameObject* GetOwner() const { return m_pOwner; }
	};


}
