#include "Player.h"
#include "PlayerMover.h"

Player::Player():
EntityHierarchy("Player")
{
	AddComponent(std::make_shared<PlayerMover>(*this));
}

void Player::Awake()
{
	ComponentsAwake();

}

void Player::Start()
{
	ComponentsStart();

}


void Player::Update()
{
	ComponentsUpdate();

}

void Player::Render()
{
	
}
