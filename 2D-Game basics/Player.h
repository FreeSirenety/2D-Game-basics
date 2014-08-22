#pragma once

#include "Entity.h"

class Player : public Entity
{

public:
	Player();

	virtual void Update(float p_fDeltaTime);

	void UpButtonPressed();
	void DownButtonPressed();
	void LeftButtonPressed();
	void RightButtonPressed();

private:
};