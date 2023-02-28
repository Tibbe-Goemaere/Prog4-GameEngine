#include "TimerComponent.h"
#include <cmath>

dae::TimerComponent::TimerComponent( std::shared_ptr<Font> font)
	:TextComponent{"FPS 0000",font,0,0}
	,m_TimePassed{0}
{	
}

void dae::TimerComponent::Update(const float dt)
{
	TextComponent::Update(dt);
	m_TimePassed += dt;
	if (m_TimePassed >= 0.5)
	{
		const float fps{ 1.f / dt };
		const int fpsRounded{ static_cast<int>(roundf(fps)) };
		std::string text{ "FPS " };
		text += std::to_string(fpsRounded);
		TextComponent::SetText(text);
		m_TimePassed = 0;
	}
	
}
