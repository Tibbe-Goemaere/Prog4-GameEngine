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
	std::shared_ptr<dae::BaseComponent> backgroundComponent = std::make_shared<dae::TextureComponent>("background.tga",0.f,0.f);
	go->AddComponent(backgroundComponent);
	scene.Add(go);

	go = std::make_shared<dae::GameObject>();
	std::shared_ptr<dae::BaseComponent> logoComponent = std::make_shared<dae::TextureComponent>("logo.tga",216.f,180.f);
	go->AddComponent(logoComponent);
	go->SetPosition(216, 180);
	scene.Add(go);

	auto font = dae::ResourceManager::GetInstance().LoadFont("Lingua.otf", 36);
	std::shared_ptr<dae::BaseComponent> titleComponent = std::make_shared<dae::TextComponent>("Programming 4 Assignment",font,80.f,20.f);
	go->AddComponent(titleComponent);
	scene.Add(go);

	font = dae::ResourceManager::GetInstance().LoadFont("Lingua.otf", 20);
	std::shared_ptr<dae::BaseComponent> fpsComponent = std::make_shared<dae::TimerComponent>(font);
	go->AddComponent(fpsComponent);
	scene.Add(go);
}

int main(int, char*[]) {
	dae::Minigin engine("../Data/");
	engine.Run(load);
    return 0;
}