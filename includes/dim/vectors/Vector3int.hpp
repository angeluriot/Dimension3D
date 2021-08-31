#ifndef DIM_VECTOR3INT_HPP
#define DIM_VECTOR3INT_HPP

#include "dim/utils/libraries.hpp"

namespace dim
{
	class Vector2;
	class Vector3;
	class Vector4;
	class Vector2int;
	class Vector4int;

	class Vector3int
	{
	public:

		int						x;
		int						y;
		int						z;

		static const Vector3int	null;

								Vector3int();
								Vector3int(const Vector3int& other) = default;
								Vector3int(int x, int y, int z);
								Vector3int(const Vector2& other, int z);
								Vector3int(int x, const Vector2& other);
								Vector3int(const Vector3& other);
								Vector3int(const Vector4& other);
								Vector3int(const Vector2int& other, int z);
								Vector3int(int x, const Vector2int& other);
								Vector3int(const Vector4int& other);
								Vector3int(const std::array<float, 3>& other);
								Vector3int(const std::array<float, 4>& other);
								Vector3int(const std::array<int, 3>& other);
								Vector3int(const std::array<int, 4>& other);
								Vector3int(const glm::vec3& other);
								Vector3int(const glm::vec4& other);
								Vector3int(const sf::Vector3f& other);
								Vector3int(const sf::Vector3i& other);
								Vector3int(const ImVec4& other);

		Vector3int&				operator=(const Vector3int& other) = default;
		Vector3int&				operator=(const Vector3& other);
		Vector3int&				operator=(const Vector4& other);
		Vector3int&				operator=(const Vector4int& other);
		Vector3int&				operator=(const std::array<float, 3>& other);
		Vector3int&				operator=(const std::array<float, 4>& other);
		Vector3int&				operator=(const std::array<int, 3>& other);
		Vector3int&				operator=(const std::array<int, 4>& other);
		Vector3int&				operator=(const glm::vec3& other);
		Vector3int&				operator=(const glm::vec4& other);
		Vector3int&				operator=(const sf::Vector3f& other);
		Vector3int&				operator=(const sf::Vector3i& other);
		Vector3int&				operator=(const ImVec4& other);

		Vector3int&				operator+=(const Vector3int& other);
		Vector3int&				operator-=(const Vector3int& other);
		Vector3int&				operator*=(const Vector3int& other);
		Vector3int&				operator*=(float number);
		Vector3int&				operator*=(int number);
		Vector3int&				operator/=(const Vector3int& other);
		Vector3int&				operator/=(float number);
		Vector3int&				operator/=(int number);
		Vector3int				operator+() const;
		Vector3int				operator-() const;

		float					get_norm() const;
		float					get_norm_2() const;
		const int*				get_ptr() const;

		void					clear();

		std::array<float, 3>	to_array_float() const;
		std::array<int, 3>		to_array_int() const;
		glm::vec3				to_glm() const;
		sf::Vector3f			to_sf_float() const;
		sf::Vector3i			to_sf_int() const;
	};

	Vector3int		operator+(const Vector3int& vector_1, const Vector3int& vector_2);
	Vector3int		operator-(const Vector3int& vector_1, const Vector3int& vector_2);
	Vector3int		operator*(float number, const Vector3int& vector);
	Vector3int		operator*(const Vector3int& vector, float number);
	Vector3int		operator*(int number, const Vector3int& vector);
	Vector3int		operator*(const Vector3int& vector, int number);
	Vector3int		operator*(const Vector3int& vector_1, const Vector3int& vector_2);
	Vector3int		operator/(float number, const Vector3int& vector);
	Vector3int		operator/(const Vector3int& vector, float number);
	Vector3int		operator/(int number, const Vector3int& vector);
	Vector3int		operator/(const Vector3int& vector, int number);
	Vector3int		operator/(const Vector3int& vector_1, const Vector3int& vector_2);
	bool			operator==(const Vector3int& vector_1, const Vector3int& vector_2);
	bool			operator!=(const Vector3int& vector_1, const Vector3int& vector_2);
	std::ostream&	operator<<(std::ostream& os, const Vector3int& vector);

	float			distance(const Vector3int& point_1, const Vector3int& point_2);
	float			distance_2(const Vector3int& point_1, const Vector3int& point_2);
}

#endif
