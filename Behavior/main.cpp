#include "Hierarchy.h"
#include "Player.h"

int main()
{
	std::unique_ptr<Hierarchy> hierarchy;
	hierarchy = std::make_unique<Hierarchy>();

	hierarchy->Register(std::make_shared<Player>());

	auto player = Hierarchy::Find("Player");
	player->Instantiate(std::make_shared<Player>("Player2"));

	hierarchy->Awake();
	hierarchy->Start();
	hierarchy->Update();
	hierarchy->Render();

	return 0;
}