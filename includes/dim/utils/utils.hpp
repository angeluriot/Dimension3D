#ifndef DIM_UTILS_HPP
#define DIM_UTILS_HPP

#include "dim/utils/libraries.hpp"

namespace dim
{
	constexpr float			pi = 3.14159265359f;

	template <typename T>
	T clamp(const T& number, const T& min, const T& max)
	{
		return std::min(std::max(number, min), max);
	}

	int		random_int(int min, int max);
	float	random_float(float min, float max);
	bool	random_probability(float probability);
	bool	sleep_every(unsigned int milliseconds);
}

#endif
