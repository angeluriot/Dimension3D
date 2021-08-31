#ifndef DIM_COLOR_HPP
#define DIM_COLOR_HPP

#include "dim/utils/libraries.hpp"

namespace dim
{
	class Vector4;

	class Color
	{
	public:

		float				r;
		float				g;
		float				b;
		float				a;

		static const Color	transparent;
		static const Color	black;
		static const Color	white;
		static const Color	red;
		static const Color	green;
		static const Color	blue;
		static const Color	yellow;
		static const Color	pink;
		static const Color	cyan;
		static const Color	orange;
		static const Color	purple;
		static const Color	grey;

							Color();
							Color(const Color& other) = default;
							Color(const Vector4& vector);
							Color(const sf::Color& color);
							Color(float red, float green, float blue, float alpha = 1.f);

		Color&				operator=(const Color& other) = default;
		Color&				operator=(const Vector4& vector);
		Color&				operator=(const sf::Color& color);

		Color&				operator+=(const Color& other);
		Color&				operator-=(const Color& other);
		Color&				operator*=(const Color& other);
		Color&				operator*=(float number);
		Color&				operator*=(int number);
		Color&				operator/=(const Color& other);
		Color&				operator/=(float number);
		Color&				operator/=(int number);

		sf::Color			to_sf() const;
		ImVec4				to_im() const;
	};

	Color operator+(const Color& color_1, const Color& color_2);
	Color operator-(const Color& color_1, const Color& color_2);
	Color operator*(const Color& color_1, const Color& color_2);
	Color operator*(float number, const Color& color);
	Color operator*(const Color& color, float number);
	Color operator*(int number, const Color& color);
	Color operator*(const Color& color, int number);
	Color operator/(const Color& color_1, const Color& color_2);
	Color operator/(float number, const Color& color);
	Color operator/(const Color& color, float number);
	Color operator/(int number, const Color& color);
	Color operator/(const Color& color, int number);
}

#endif
