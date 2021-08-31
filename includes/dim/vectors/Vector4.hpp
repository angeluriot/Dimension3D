#ifndef DIM_VECTOR4_HPP
#define DIM_VECTOR4_HPP

#include "dim/utils/libraries.hpp"

namespace dim
{
	class Vector2;
	class Vector3;
	class Vector2int;
	class Vector3int;
	class Vector4int;
	class Color;

	class Vector4
	{
	public:

		float					x;
		float					y;
		float					z;
		float					w;

		static const Vector4	null;
		static const Vector4	unit;

								Vector4();
								Vector4(const Vector4& other) = default;
								Vector4(float x, float y, float z, float w);
								Vector4(const Vector2& other, float z, float w);
								Vector4(float x, const Vector2& other, float w);
								Vector4(float x, float y, const Vector2& other);
								Vector4(const Vector3& other, float w);
								Vector4(float x, const Vector3& other);
								Vector4(const Vector2int& other, float z, float w);
								Vector4(float x, const Vector2int& other, float w);
								Vector4(float x, float y, const Vector2int& other);
								Vector4(const Vector3int& other, float w);
								Vector4(float x, const Vector3int& other);
								Vector4(const Vector4int& other);
								Vector4(const std::array<float, 4>& other);
								Vector4(const std::array<int, 4>& other);
								Vector4(const glm::vec4& other);
								Vector4(const ImVec4& other);
								Vector4(const Color& color);

		Vector4&				operator=(const Vector4& other) = default;
		Vector4&				operator=(const Vector4int& other);
		Vector4&				operator=(const std::array<float, 4>& other);
		Vector4&				operator=(const std::array<int, 4>& other);
		Vector4&				operator=(const glm::vec4& other);
		Vector4&				operator=(const ImVec4& other);
		Vector4&				operator=(const Color& color);

		Vector4&				operator+=(const Vector4& other);
		Vector4&				operator-=(const Vector4& other);
		Vector4&				operator*=(const Vector4& other);
		Vector4&				operator*=(float number);
		Vector4&				operator*=(int number);
		Vector4&				operator*=(const glm::mat4& matrix);
		Vector4&				operator/=(const Vector4& other);
		Vector4&				operator/=(float number);
		Vector4&				operator/=(int number);
		Vector4					operator+() const;
		Vector4					operator-() const;

		float					get_norm() const;
		float					get_norm_2() const;
		const float*			get_ptr() const;

		void					set_norm(float norm);
		void					normalize();
		void					clear();

		std::array<float, 4>	to_array_float() const;
		std::array<int, 4>		to_array_int() const;
		glm::vec4				to_glm() const;
		ImVec4					to_imgui() const;
	};

	Vector4			operator+(const Vector4& vector_1, const Vector4& vector_2);
	Vector4			operator-(const Vector4& vector_1, const Vector4& vector_2);
	Vector4			operator*(float number, const Vector4& vector);
	Vector4			operator*(const Vector4& vector, float number);
	Vector4			operator*(int number, const Vector4& vector);
	Vector4			operator*(const Vector4& vector, int number);
	Vector4			operator*(const Vector4& vector_1, const Vector4& vector_2);
	Vector4			operator*(const glm::mat4& matrix, const Vector4& vector);
	Vector4			operator*(const Vector4& vector, const glm::mat4& matrix);
	Vector4			operator/(float number, const Vector4& vector);
	Vector4			operator/(const Vector4& vector, float number);
	Vector4			operator/(int number, const Vector4& vector);
	Vector4			operator/(const Vector4& vector, int number);
	Vector4			operator/(const Vector4& vector_1, const Vector4& vector_2);
	float			dot(const Vector4& vector_1, const Vector4& vector_2);
	bool			operator==(const Vector4& vector_1, const Vector4& vector_2);
	bool			operator!=(const Vector4& vector_1, const Vector4& vector_2);
	std::ostream&	operator<<(std::ostream& os, const Vector4& vector);

	float			distance(const Vector4& point_1, const Vector4& point_2);
	float			distance_2(const Vector4& point_1, const Vector4& point_2);
	Vector4			normalize(const Vector4& vector);
}

#endif
