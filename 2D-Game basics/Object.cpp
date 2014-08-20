#include "Object.h"
#include "Timer.h"
#include <iostream>

Object::Object()
{
	m_sTag = "none";
}

void Object::Update(float p_fDeltaTime)
{
	UpdateTimers(p_fDeltaTime);
}

void Object::SetTag(std::string p_sTag)
{
	m_sTag = p_sTag;
}

std::string Object::GetTag()
{
	return m_sTag;
}

void Object::UpdateTimers(float p_fDeltaTime)
{
	std::vector<std::string> vFinishedIDs;

	for (auto timerPair : m_mTimers)
	{
		timerPair.second->Update(p_fDeltaTime);

		if (timerPair.second->GetIsFinished())
		{
			vFinishedIDs.push_back(timerPair.first);
		}
	}

	for (auto timerID : vFinishedIDs)
	{
		if (m_mTimers.find(timerID) != m_mTimers.end())
		{
			auto timerToErase = m_mTimers.find(timerID)¨;

			delete timerToErase->second;

			m_mTimers.erase(timerToErase);
		}
	}

	vFinishedIDs.empty();
}

void Object::AttachTimer(std::string p_sID, float p_fDuration)
{
	if (m_mTimers.find(p_sID) == m_mTimers.end())
	{
		std::pair<std::string, Timer*> timerPair(p_sID, new Timer(p_fDuration));

		m_mTimers.insert(timerPair);
	}
	else
	{
		std::cout << "Timer ID already exists" << std::endl;
	}
}

void Object::AttachTimer(std::string p_sID, float p_fDuration, std::function<void()> p_fFunction)
{
	if (m_mTimers.find(p_sID) == m_mTimers.end())
	{
		std::pair<std::string, Timer*> timerPair(p_sID, new Timer(p_fDuration, p_fFunction));

		m_mTimers.insert(timerPair);
	}
	else
	{
		std::cout << "Timer ID already exists" << std::endl;
	}
}