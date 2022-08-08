#include "timer.h"

Timer::Timer()
{
	m_beginning = clock_type::now();
}

void Timer::reset()
{
	m_beginning = clock_type::now();
}

unsigned long long Timer::elapsed() const 
{
	return std::chrono::milliseconds((clock_type::now() - m_beginning).count()).count();
}