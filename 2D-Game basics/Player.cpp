#include "Player.h"
#include <iostream>

Player::Player()
{

}

void Player::Update(float p_fDeltaTime)
{

}

void Player::UpButtonPressed()
{
	std::cout << "Player up pressed" << std::endl;
}

void Player::DownButtonPressed()
{
	std::cout << "Player down pressed" << std::endl;
}

void Player::LeftButtonPressed()
{
	std::cout << "Player left pressed" << std::endl;
}

void Player::RightButtonPressed()
{
	std::cout << "Player right pressed" << std::endl;
}
