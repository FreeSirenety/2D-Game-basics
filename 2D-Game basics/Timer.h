#pragma once

#include <functional>

class Timer
{

public:
	Timer(float p_fMaxDuration);

	Timer(float p_fMaxDuration, std::function<void()> p_fFunctionAtEndOfTimer);

	void Update(float DeltaTime);

	void Reset();

	float GetTimeLeft();

	float GetMaxTimer();

	float GetCurrentTimer();

	void SetNewMax(float p_fNewMax);

	void AppendExtraTime(float p_fTimeToAppend);

	void Start();

	void Pause();

	bool GetIsFinished();

private:
	bool m_bIsFinished;
	float m_fMaxDuration;
	float m_fCurrentDuration;

	bool m_bHasFunction;
	std::function<void()> m_fFunctionAtEndOfTimer;

	bool m_bHasStarted;
};