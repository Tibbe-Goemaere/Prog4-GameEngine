#pragma once
#include "TextComponent.h"
namespace dae
{
	class TimerComponent final : public TextComponent
	{
	public:
		void Update(const float dt) override;

		TimerComponent(std::weak_ptr<GameObject>);
		TimerComponent() = default;
		~TimerComponent() = default;
		TimerComponent(const TimerComponent& other) = delete;
		TimerComponent(TimerComponent&& other) = delete;
		TimerComponent& operator=(const TimerComponent& other) = delete;
		TimerComponent& operator=(TimerComponent&& other) = delete;
	private:
		float m_TimePassed;
		const float m_FpsShowInterval;
		int m_Ticks;
	};
}


