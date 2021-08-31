#ifndef DIM_VECTOR3_HPP
#define DIM_VECTOR3_HPP

#include "dim/utils/libraries.hpp"

namespace dim
{
	class Vector2;
	class Vector4;
	class Vector2int;
	class Vector3int;
	class Vector4int;
	class Color;

	class Vector3
	{
	public:

		float					x;
		float					y;
		float					z;

		static const Vector3	null;
		static const Vector3	unit;

								Vector3();
								Vector3(const Vector3& other) = default;
								Vector3(float x, float y, float z);
								Vector3(const Vector2& other, float z);
								Vector3(float x, const Vector2& other);
								Vector3(const Vector4& other);
								Vector3(const Vector2int& other, float z);
								Vector3(float x, const Vector2int& other);
								Vector3(const Vector3int& other);
								Vector3(const Vector4int& other);
								Vector3(const std::array<float, 3>& other);
								Vector3(const std::array<float, 4>& other);
								Vector3(const std::array<int, 3>& other);
								Vector3(const std::array<int, 4>& other);
								Vector3(const glm::vec3& other);
								Vector3(const glm::vec4& other);
								Vector3(const sf::Vector3f& other);
								Vector3(const sf::Vector3i& other);
								Vector3(const ImVec4& other);
								Vector3(const sf::Color& color);

		static Vector3			Cartesian(float x, float y, float z);
		static Vector3			Spherical(float norm, float theta, float phi);

		Vector3&				operator=(const Vector3& other) = default;
		Vector3&				operator=(const Vector4& other);
		Vector3&				operator=(const Vector3int& other);
		Vector3&				operator=(const Vector4int& other);
		Vector3&				operator=(const std::array<float, 3>& other);
		Vector3&				operator=(const std::array<float, 4>& other);
		Vector3&				operator=(const std::array<int, 3>& other);
		Vector3&				operator=(const std::array<int, 4>& other);
		Vector3&				operator=(const glm::vec3& other);
		Vector3&				operator=(const glm::vec4& other);
		Vector3&				operator=(const sf::Vector3f& other);
		Vector3&				operator=(const sf::Vector3i& other);
		Vector3&				operator=(const ImVec4& other);
		Vector3&				operator=(const sf::Color& color);

		Vector3&				operator+=(const Vector3& other);
		Vector3&				operator-=(const Vector3& other);
		Vector3&				operator*=(const Vector3& other);
		Vector3&				operator*=(float number);
		Vector3&				operator*=(int number);
		Vector3&				operator*=(const glm::mat3& matrix);
		Vector3&				operator*=(const glm::mat4& matrix);
		Vector3&				operator/=(const Vector3& other);
		Vector3&				operator/=(float number);
		Vector3&				operator/=(int number);
		Vector3&				operator^=(const Vector3& other);
		Vector3					operator+() const;
		Vector3					operator-() const;

		float					get_norm() const;
		float					get_norm_2() const;
		float					get_theta() const;
		float					get_phi() const;
		const float*			get_ptr() const;

		void					set_norm(float norm);
		void					set_theta(float theta);
		void					set_phi(float phi);
		void					normalize();
		void					clear();

		std::array<float, 3>	to_array_float() const;
		std::array<int, 3>		to_array_int() const;
		glm::vec3				to_glm() const;
		sf::Vector3f			to_sf_float() const;
		sf::Vector3i			to_sf_int() const;
	};

	Vector3			operator+(const Vector3& vector_1, const Vector3& vector_2);
	Vector3			operator-(const Vector3& vector_1, const Vector3& vector_2);
	Vector3			operator*(float number, const Vector3& vector);
	Vector3			operator*(const Vector3& vector, float number);
	Vector3			operator*(int number, const Vector3& vector);
	Vector3			operator*(const Vector3& vector, int number);
	Vector3			operator*(const Vector3& vector_1, const Vector3& vector_2);
	Vector3			operator*(const glm::mat3& matrix, const Vector3& vector);
	Vector3			operator*(const Vector3& vector, const glm::mat3& matrix);
	Vector3			operator*(const glm::mat4& matrix, const Vector3& vector);
	Vector3			operator*(const Vector3& vector, const glm::mat4& matrix);
	Vector3			operator/(float number, const Vector3& vector);
	Vector3			operator/(const Vector3& vector, float number);
	Vector3			operator/(int number, const Vector3& vector);
	Vector3			operator/(const Vector3& vector, int number);
	Vector3			operator/(const Vector3& vector_1, const Vector3& vector_2);
	Vector3			operator^(const Vector3& vector_1, const Vector3& vector_2);
	float			dot(const Vector3& vector_1, const Vector3& vector_2);
	bool			operator==(const Vector3& vector_1, const Vector3& vector_2);
	bool			operator!=(const Vector3& vector_1, const Vector3& vector_2);
	std::ostream&	operator<<(std::ostream& os, const Vector3& vector);

	float			distance(const Vector3& point_1, const Vector3& point_2);
	float			distance_2(const Vector3& point_1, const Vector3& point_2);
	float			theta(const Vector3& point_1, const Vector3& point_2);
	float			phi(const Vector3& point_1, const Vector3& point_2);
	Vector3			normalize(const Vector3& vector);
}

#endif
