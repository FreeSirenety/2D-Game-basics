#pragma once

#include "Entity.h"
#include "SFML/Graphics.hpp"

class Player : public Entity
{

public:
	Player();

	virtual void Update(float p_fDeltaTime);

	void UpButtonPressed();
	void DownButtonPressed();
	void LeftButtonPressed();
	void RightButtonPressed();

	void UpButtonReleased();
	void DownButtonReleased();
	void LeftButtonReleased();
	void RightButtonReleased();

	void UpdatePlayerVelocity();

	void StartDashTimer();

	void DashTimerStopped();

	void Dash();

	void DashFinished();

private:
	bool m_bUpMovementPressed;
	bool m_bDownMovementPressed;
	bool m_bLeftMovementPressed;
	bool m_bRightMovementPressed;

	bool m_bIsDashing;
};