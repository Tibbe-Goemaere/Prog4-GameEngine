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
	class TextureComponent final : public BaseComponent
	{
	public:
		void Render() const override;
		void Update(const float dt) override;

		void SetTexture(const std::string& filename);
		void SetPosition(float x, float y);

		TextureComponent(std::shared_ptr<GameObject> pOwner);
		~TextureComponent() = default;
		TextureComponent(const TextureComponent& other) = delete;
		TextureComponent(TextureComponent&& other) = delete;
		TextureComponent& operator=(const TextureComponent& other) = delete;
		TextureComponent& operator=(TextureComponent&& other) = delete;
	private:
		Transform m_Transform{};
		std::shared_ptr<Texture2D> m_pTexture;
	};
}
