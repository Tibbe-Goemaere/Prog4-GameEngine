#include <SDL.h>
#include "InputManager.h"
#include "ImGui/imgui_impl_sdl2.h"
#include <Windows.h>

bool dae::InputManager::ProcessInput()
{
	
	SDL_Event e;
	while (SDL_PollEvent(&e)) {
		if (e.type == SDL_QUIT) {
			return false;
		}
		
		ImGui_ImplSDL2_ProcessEvent(&e);
	}

	return true;
}
