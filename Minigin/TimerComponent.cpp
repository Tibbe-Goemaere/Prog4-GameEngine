#include "TimerComponent.h"
#include <cmath>

dae::TimerComponent::TimerComponent(std::shared_ptr<GameObject> pOwner)
	:TextComponent{pOwner}
	, m_FpsShowInterval{ 1 }
	,m_TimePassed{1.f}
	,m_Ticks{0}
{	
}

void dae::TimerComponent::Update(const float dt)
{
	TextComponent::Update(dt);
	m_TimePassed += dt;
	++m_Ticks;
	if (m_TimePassed >= m_FpsShowInterval)
	{
		const float fps{ 1.f / (m_TimePassed/m_Ticks)};
		const int fpsRounded{ static_cast<int>(roundf(fps)) };
		std::string text{ "FPS " };
		text += std::to_string(fpsRounded);
		TextComponent::SetText(text);
		m_TimePassed = 0;
		m_Ticks = 0;
	}
	
}
