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
	go->AddComponent<dae::TextureComponent>(go)->SetTexture("background.tga");
	scene.Add(go);

	//go = std::make_shared<dae::GameObject>();
	//go->AddComponent<dae::TextureComponent>();
	//scene.Add(go);
	//
	//auto font = dae::ResourceManager::GetInstance().LoadFont("Lingua.otf", 36);
	//go->AddComponent<dae::TextComponent>();
	//scene.Add(go);

	//font = dae::ResourceManager::GetInstance().LoadFont("Lingua.otf", 20);
	//go->AddComponent<dae::TimerComponent>();
	//scene.Add(go);
}

int main(int, char*[]) {
	dae::Minigin engine("../Data/");
	engine.Run(load);
    return 0;
}