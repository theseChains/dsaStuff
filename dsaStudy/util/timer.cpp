#include "timer.h"

Timer::Timer()
{
	m_beginning = ClockType::now();
}

void Timer::reset()
{
	m_beginning = ClockType::now();
}

unsigned long long Timer::elapsed() const
{
	return std::chrono::milliseconds((ClockType::now() - m_beginning).count()).count();
}
