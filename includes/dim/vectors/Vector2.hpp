#ifndef DIM_VECTOR2_HPP
#define DIM_VECTOR2_HPP

#include "dim/utils/libraries.hpp"

namespace dim
{
	class Vector3;
	class Vector4;
	class Vector2int;
	class Vector3int;
	class Vector4int;

	class Vector2
	{
	public:

		float					x;
		float					y;

		static const Vector2	null;
		static const Vector2	unit;

								Vector2();
								Vector2(const Vector2& other) = default;
								Vector2(float x, float y);
								Vector2(const Vector3& other);
								Vector2(const Vector4& other);
								Vector2(const Vector2int& other);
								Vector2(const Vector3int& other);
								Vector2(const Vector4int& other);
								Vector2(const std::array<float, 2>& other);
								Vector2(const std::array<float, 3>& other);
								Vector2(const std::array<float, 4>& other);
								Vector2(const std::array<int, 2>& other);
								Vector2(const std::array<int, 3>& other);
								Vector2(const std::array<int, 4>& other);
								Vector2(const glm::vec2& other);
								Vector2(const glm::vec3& other);
								Vector2(const glm::vec4& other);
								Vector2(const sf::Vector2f& other);
								Vector2(const sf::Vector3f& other);
								Vector2(const sf::Vector2i& other);
								Vector2(const sf::Vector3i& other);
								Vector2(const ImVec2& other);
								Vector2(const ImVec4& other);

		static Vector2			Cartesian(float x, float y);
		static Vector2			Polar(float norm, float angle);

		Vector2&				operator=(const Vector2& other) = default;
		Vector2&				operator=(const Vector3& other);
		Vector2&				operator=(const Vector4& other);
		Vector2&				operator=(const Vector2int& other);
		Vector2&				operator=(const Vector3int& other);
		Vector2&				operator=(const Vector4int& other);
		Vector2&				operator=(const std::array<float, 2>& other);
		Vector2&				operator=(const std::array<float, 3>& other);
		Vector2&				operator=(const std::array<float, 4>& other);
		Vector2&				operator=(const std::array<int, 2>& other);
		Vector2&				operator=(const std::array<int, 3>& other);
		Vector2&				operator=(const std::array<int, 4>& other);
		Vector2&				operator=(const glm::vec2& other);
		Vector2&				operator=(const glm::vec3& other);
		Vector2&				operator=(const glm::vec4& other);
		Vector2&				operator=(const sf::Vector2f& other);
		Vector2&				operator=(const sf::Vector3f& other);
		Vector2&				operator=(const sf::Vector2i& other);
		Vector2&				operator=(const sf::Vector3i& other);
		Vector2&				operator=(const ImVec2& other);
		Vector2&				operator=(const ImVec4& other);

		Vector2&				operator+=(const Vector2& other);
		Vector2&				operator-=(const Vector2& other);
		Vector2&				operator*=(const Vector2& other);
		Vector2&				operator*=(float number);
		Vector2&				operator*=(int number);
		Vector2&				operator*=(const glm::mat2& matrix);
		Vector2&				operator*=(const glm::mat3& matrix);
		Vector2&				operator/=(const Vector2& other);
		Vector2&				operator/=(float number);
		Vector2&				operator/=(int number);
		Vector2					operator+() const;
		Vector2					operator-() const;

		float					get_norm() const;
		float					get_norm_2() const;
		float					get_angle() const;
		const float*			get_ptr() const;

		void					set_norm(float norm);
		void					set_angle(float angle);
		void					normalize();
		void					clear();

		std::array<float, 2>	to_array_float() const;
		std::array<int, 2>		to_array_int() const;
		glm::vec2				to_glm() const;
		sf::Vector2f			to_sf_float() const;
		sf::Vector2i			to_sf_int() const;
		ImVec2					to_imgui() const;
	};

	Vector2			operator+(const Vector2& vector_1, const Vector2& vector_2);
	Vector2			operator-(const Vector2& vector_1, const Vector2& vector_2);
	Vector2			operator*(float number, const Vector2& vector);
	Vector2			operator*(const Vector2& vector, float number);
	Vector2			operator*(int number, const Vector2& vector);
	Vector2			operator*(const Vector2& vector, int number);
	Vector2			operator*(const Vector2& vector_1, const Vector2& vector_2);
	Vector2			operator*(const glm::mat2& matrix, const Vector2& vector);
	Vector2			operator*(const Vector2& vector, const glm::mat2& matrix);
	Vector2			operator*(const glm::mat3& matrix, const Vector2& vector);
	Vector2			operator*(const Vector2& vector, const glm::mat3& matrix);
	Vector2			operator/(float number, const Vector2& vector);
	Vector2			operator/(const Vector2& vector, float number);
	Vector2			operator/(int number, const Vector2& vector);
	Vector2			operator/(const Vector2& vector, int number);
	Vector2			operator/(const Vector2& vector_1, const Vector2& vector_2);
	float			dot(const Vector2& vector_1, const Vector2& vector_2);
	bool			operator==(const Vector2& vector_1, const Vector2& vector_2);
	bool			operator!=(const Vector2& vector_1, const Vector2& vector_2);
	std::ostream&	operator<<(std::ostream& os, const Vector2& vector);

	float			distance(const Vector2& point_1, const Vector2& point_2);
	float			distance_2(const Vector2& point_1, const Vector2& point_2);
	float			angle(const Vector2& point_1, const Vector2& point_2);
	Vector2			normalize(const Vector2& vector);
}

#endif
