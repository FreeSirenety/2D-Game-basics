#include "Player.h"
#include <iostream>
#include <math.h>
#include "DebugManager.h"

Player::Player() : Entity()
{
	m_bUpMovementPressed = false;
	m_bDownMovementPressed = false;
	m_bLeftMovementPressed = false;
	m_bRightMovementPressed = false;

	m_fSpeed = 250.f;

	m_bIsDashing = false;
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

	StartDashTimer();
}

void Player::DownButtonPressed()
{
	m_bDownMovementPressed = true;

	StartDashTimer();
}

void Player::LeftButtonPressed()
{
	m_bLeftMovementPressed = true;

	StartDashTimer();
}

void Player::RightButtonPressed()
{
	m_bRightMovementPressed = true;

	StartDashTimer();
}

void Player::UpButtonReleased()
{
	m_bUpMovementPressed = false;
}

void Player::DownButtonReleased()
{
	m_bDownMovementPressed = false;
}

void Player::LeftButtonReleased()
{
	m_bLeftMovementPressed = false;
}

void Player::RightButtonReleased()
{
	m_bRightMovementPressed = false;
}

void Player::StartDashTimer()
{
	if (m_bIsDashing)
	{
		Dash();

		return;
	}

	m_bIsDashing = true;

	AttachTimer("DashTimer", 0.5, std::bind(&Player::DashTimerStopped, this));
}

void Player::DashTimerStopped()
{
	m_bIsDashing = false;

	DebugManager::GetInstance().CreateDebugMessage("Dash timer stopped", DebugManager::LOG);
}

void Player::Dash()
{
	AttachTimer("DashFinishedTimer", 0.2, std::bind(&Player::DashFinished, this));

	m_fSpeed = 600.f;
}

void Player::DashFinished()
{
	m_fSpeed = 250.f;
}