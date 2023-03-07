#pragma once
#include <string>
#include <memory>
#include "GameObject.h"
#include "Transform.h"
#include "BaseComponent.h"

namespace dae
{
	class Font;
	class Texture2D;
	class TextComponent : public BaseComponent
	{
	public:
		virtual void Update(const float dt);
		void Render() const override;
		
		void SetText(const std::string& text);
		void SetFont(const std::shared_ptr<Font> font);
		void SetPosition(float x, float y);

		TextComponent(std::shared_ptr<GameObject> pOwner);
		TextComponent() = default;
		~TextComponent() = default;
		TextComponent(const TextComponent& other) = delete;
		TextComponent(TextComponent&& other) = delete;
		TextComponent& operator=(const TextComponent& other) = delete;
		TextComponent& operator=(TextComponent&& other) = delete;
	private:
		bool m_needsUpdate{true};
		std::string m_text{"BaseText"};
		Transform m_transform{};
		std::shared_ptr<Font> m_font;
		std::shared_ptr<Texture2D> m_textTexture;
	};
}
