#include "Timer.h"

Timer::Timer(float p_fMaxDuration)
{
	m_fMaxDuration = p_fMaxDuration;

	m_fCurrentDuration = 0;

	m_bHasFunction = false;

	m_bIsFinished = false;

	m_bHasStarted = false;
}

Timer::Timer(float p_fMaxDuration, std::function<void()> p_fFunctionAtEndOfTimer)
{
	m_fMaxDuration = p_fMaxDuration;

	m_fCurrentDuration = 0;

	m_bHasFunction = true;

	m_fFunctionAtEndOfTimer = p_fFunctionAtEndOfTimer;

	m_bIsFinished = false;

	m_bHasStarted = false;
}

void Timer::Update(float DeltaTime)
{
	if (m_bIsFinished)
	{
		return;
	}

	if (m_bHasStarted)
	{
		m_fCurrentDuration += DeltaTime;
	}

	if (m_fCurrentDuration > m_fMaxDuration && m_bIsFinished == false)
	{
		m_bIsFinished = true;

		if (m_bHasFunction)
		{
			m_fFunctionAtEndOfTimer();
		}
	}
}

void Timer::Reset()
{
	m_fCurrentDuration = 0;
}

float Timer::GetTimeLeft()
{
	return m_fMaxDuration - m_fCurrentDuration;
}

float Timer::GetMaxTimer()
{
	return m_fMaxDuration;
}

float Timer::GetCurrentTimer()
{
	return m_fCurrentDuration;
}

void Timer::SetNewMax(float p_fNewMax)
{
	m_fMaxDuration = p_fNewMax;
}

void Timer::AppendExtraTime(float p_fTimeToAppend)
{
	m_fMaxDuration += p_fTimeToAppend;
}

void Timer::Start()
{
	m_bHasStarted = true;
}

void Timer::Pause()
{
	m_bHasStarted = false;
}

bool Timer::GetIsFinished()
{
	return m_bIsFinished;
}