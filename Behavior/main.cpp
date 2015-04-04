#include "Hierarchy.h"
#include "Player.h"

int main()
{
	std::unique_ptr<Hierarchy> hierarchy;
	hierarchy = std::make_unique<Hierarchy>();

	hierarchy->Register(std::make_shared<Player>());

	hierarchy->Awake();
	
	hierarchy->Start();
	
	hierarchy->Update();

	hierarchy->Render();

	return 0;
}