#include "Player.h"
#include <iostream>
#include <math.h>

Player::Player() : Entity()
{
	m_bUpMovementPressed = false;
	m_bDownMovementPressed = false;
	m_bLeftMovementPressed = false;
	m_bRightMovementPressed = false;

	m_fSpeed = 100.f;
}

void Player::UpdatePlayerVelocity()
{

	if (m_bUpMovementPressed)
	{
		m_xVelocity.y -= 1;
	}

	if (m_bDownMovementPressed)
	{
		m_xVelocity.y += 1;
	}

	if (m_bLeftMovementPressed)
	{
		m_xVelocity.x -= 1;
	}

	if (m_bRightMovementPressed)
	{
		m_xVelocity.x += 1;
	}
}

void Player::Update(float p_fDeltaTime)
{
	Entity::Update(p_fDeltaTime);

	UpdatePlayerVelocity();

	Move(p_fDeltaTime);

	m_xVelocity.x = 0;
	m_xVelocity.y = 0;
}

void Player::UpButtonPressed()
{
	m_bUpMovementPressed = true;

	std::cout << "Player up pressed" << std::endl;
}

void Player::DownButtonPressed()
{
	m_bDownMovementPressed = true;

	std::cout << "Player down pressed" << std::endl;
}

void Player::LeftButtonPressed()
{
	m_bLeftMovementPressed = true;

	std::cout << "Player left pressed" << std::endl;
}

void Player::RightButtonPressed()
{
	m_bRightMovementPressed = true;
	std::cout << "Player right pressed" << std::endl;
}

void Player::UpButtonReleased()
{
	m_bUpMovementPressed = false;

	std::cout << "Player up released" << std::endl;
}

void Player::DownButtonReleased()
{
	m_bDownMovementPressed = false;

	std::cout << "Player down released" << std::endl;
}

void Player::LeftButtonReleased()
{
	m_bLeftMovementPressed = false;

	std::cout << "Player left released" << std::endl;
}

void Player::RightButtonReleased()
{
	m_bRightMovementPressed = false;
	std::cout << "Player right released" << std::endl;
}
