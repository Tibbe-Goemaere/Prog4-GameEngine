#pragma once
#include "GameObject.h"
namespace dae
{
	class Command
	{
	public:
		virtual ~Command() {}
		virtual void Execute(const GameObject& actor) = 0;
	};

	class MoveCommand : Command
	{
	public:
		void Execute(const GameObject& actor) override { Move(actor); }
	private:
		void Move(const GameObject& actor);
	};

}


