#include <SDL.h>

#if _DEBUG
// ReSharper disable once CppUnusedIncludeDirective
#if __has_include(<vld.h>)
#include <vld.h>
#endif
#endif

#include "Minigin.h"
#include "SceneManager.h"
#include "ResourceManager.h"
#include "TextComponent.h"
#include "TimerComponent.h"
#include "TextureComponent.h"
#include "Scene.h"

void load()
{
	auto& scene = dae::SceneManager::GetInstance().CreateScene("Demo");

	auto go = std::make_shared<dae::GameObject>();
	auto backgroundTextureComp = go->AddComponent<dae::TextureComponent>();
	backgroundTextureComp->SetTexture("background.tga");
	scene.Add(go);

	go = std::make_shared<dae::GameObject>();
	auto textureComponent = go->AddComponent<dae::TextureComponent>();
	textureComponent->SetTexture("logo.tga");
	textureComponent->SetPosition(216, 180);
	scene.Add(go);
	
	auto font = dae::ResourceManager::GetInstance().LoadFont("Lingua.otf", 36);
	auto textComponent = go->AddComponent<dae::TextComponent>();
	textComponent->SetFont(font);
	textComponent->SetText("Programming 4 Assignment");
	textComponent->SetPosition(80, 20);
	scene.Add(go);

	font = dae::ResourceManager::GetInstance().LoadFont("Lingua.otf", 20);
	auto timerComponent = go->AddComponent<dae::TimerComponent>();
	timerComponent->SetFont(font);
	timerComponent->SetText("FPS ");
	scene.Add(go);
}

int main(int, char*[]) {
	dae::Minigin engine("../Data/");
	engine.Run(load);
    return 0;
}