#pragma once
#include "Transform.h"
namespace dae
{
	class BaseComponent
	{
	public:
		BaseComponent(std::weak_ptr<GameObject> pOwner) : m_pOwner(pOwner) {};
		
		virtual ~BaseComponent() = default;

		virtual void Update(const float dt) = 0;
		virtual void Render() const = 0;

		void SetOwner(std::weak_ptr<GameObject> pOwner) { m_pOwner = pOwner; };

		BaseComponent(const BaseComponent& other) = delete;
		BaseComponent(BaseComponent&& other) = delete;
		BaseComponent& operator=(const BaseComponent& other) = delete;
		BaseComponent& operator=(BaseComponent&& other) = delete;

	protected:
		std::weak_ptr<GameObject> GetOwner() const { return m_pOwner; }

	private:
		std::weak_ptr<GameObject> m_pOwner;
	};


}
