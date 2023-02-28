#pragma once
#include "TextComponent.h"
namespace dae
{
	class TimerComponent final : public TextComponent
	{
	public:
		void Update(const float dt) override;

		TimerComponent( std::shared_ptr<Font> font);
		TimerComponent() = default;
		virtual ~TimerComponent() = default;
		TimerComponent(const TimerComponent& other) = delete;
		TimerComponent(TimerComponent&& other) = delete;
		TimerComponent& operator=(const TimerComponent& other) = delete;
		TimerComponent& operator=(TimerComponent&& other) = delete;
	private:
		float m_TimePassed;
	};
}


