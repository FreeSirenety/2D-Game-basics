#pragma once

#include <string>
#include <functional>
#include <map>

#include "SFML/Graphics.hpp"

class Timer;

class Object
{
public:
	Object();

	virtual void Update(float p_fDeltaTime);

	void SetTag(std::string p_sTag);
	std::string GetTag();

	void UpdateTimers(float p_fDeltaTime);

	void AttachTimer(std::string p_sID, float p_fDuration);
	void AttachTimer(std::string p_sID, float p_fDuration, std::function<void()> p_fFunction);

protected:
	std::string m_sTag;

	std::map<std::string, Timer*> m_mTimers;
};