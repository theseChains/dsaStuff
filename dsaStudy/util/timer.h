#ifndef TIMER_CLASS_H
#define TIMER_CLASS_H

#include <chrono>

class Timer
{
private:
	using clock_type = std::chrono::steady_clock;

	std::chrono::time_point<clock_type> m_beginning{};

public:
	Timer();

	void reset();
	unsigned long long elapsed() const;
};

#endif