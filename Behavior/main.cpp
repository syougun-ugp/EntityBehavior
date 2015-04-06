#include "Hierarchy.h"
#include "Player.h"
#include "Enemy.h"

int main()
{
	std::unique_ptr<Hierarchy> hierarchy;
	hierarchy = std::make_unique<Hierarchy>();

	hierarchy->Register(std::make_shared<Enemy>());
	hierarchy->Register(std::make_shared<Player>());

	auto player = Hierarchy::Find("Player");
	player->Instantiate(std::make_shared<Player>("Player2"));

	hierarchy->Awake();
	hierarchy->Start();

	hierarchy->Update();
	hierarchy->Render();

	auto playerTagObject = Hierarchy::FindWithTag(Tags::Player);
	auto playerTagObjects = Hierarchy::FindGameObjectsWithTag(Tags::Player);
	

	return 0;
}