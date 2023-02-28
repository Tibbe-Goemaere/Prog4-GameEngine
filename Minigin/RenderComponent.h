#pragma once
#include "BaseComponent.h"
namespace dae
{
	class RenderComponent : public BaseComponent
	{
	public:
		RenderComponent() = default;
		virtual ~RenderComponent() = default;

		virtual void Render() const = 0;
		virtual void Update() = 0;

		RenderComponent(const RenderComponent& other) = delete;
		RenderComponent(RenderComponent&& other) = delete;
		RenderComponent& operator=(const RenderComponent& other) = delete;
		RenderComponent& operator=(RenderComponent&& other) = delete;
	};
}


