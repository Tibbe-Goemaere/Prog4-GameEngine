#pragma once
#include "BaseComponent.h"
namespace dae
{
	class UpdateComponent : public BaseComponent
	{
	public:
		UpdateComponent() = default;
		virtual ~UpdateComponent() = default;

		virtual void Update() = 0;

		UpdateComponent(const UpdateComponent& other) = delete;
		UpdateComponent(UpdateComponent&& other) = delete;
		UpdateComponent& operator=(const UpdateComponent& other) = delete;
		UpdateComponent& operator=(UpdateComponent&& other) = delete;
	};
}


