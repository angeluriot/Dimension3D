#ifndef DIM_VECTOR2INT_HPP
#define DIM_VECTOR2INT_HPP

#include "dim/utils/libraries.hpp"

namespace dim
{
	class Vector2;
	class Vector3;
	class Vector4;
	class Vector3int;
	class Vector4int;

	class Vector2int
	{
	public:

		int						x;
		int						y;

		static const Vector2int	null;

								Vector2int();
								Vector2int(const Vector2int& other) = default;
								Vector2int(int x, int y);
								Vector2int(const Vector2& other);
								Vector2int(const Vector3& other);
								Vector2int(const Vector4& other);
								Vector2int(const Vector3int& other);
								Vector2int(const Vector4int& other);
								Vector2int(const std::array<float, 2>& other);
								Vector2int(const std::array<float, 3>& other);
								Vector2int(const std::array<float, 4>& other);
								Vector2int(const std::array<int, 2>& other);
								Vector2int(const std::array<int, 3>& other);
								Vector2int(const std::array<int, 4>& other);
								Vector2int(const glm::vec2& other);
								Vector2int(const glm::vec3& other);
								Vector2int(const glm::vec4& other);
								Vector2int(const sf::Vector2f& other);
								Vector2int(const sf::Vector3f& other);
								Vector2int(const sf::Vector2i& other);
								Vector2int(const sf::Vector3i& other);
								Vector2int(const ImVec2& other);
								Vector2int(const ImVec4& other);

		Vector2int&				operator=(const Vector2int& other) = default;
		Vector2int&				operator=(const Vector2& other);
		Vector2int&				operator=(const Vector3& other);
		Vector2int&				operator=(const Vector4& other);
		Vector2int&				operator=(const Vector3int& other);
		Vector2int&				operator=(const Vector4int& other);
		Vector2int&				operator=(const std::array<float, 2>& other);
		Vector2int&				operator=(const std::array<float, 3>& other);
		Vector2int&				operator=(const std::array<float, 4>& other);
		Vector2int&				operator=(const std::array<int, 2>& other);
		Vector2int&				operator=(const std::array<int, 3>& other);
		Vector2int&				operator=(const std::array<int, 4>& other);
		Vector2int&				operator=(const glm::vec2& other);
		Vector2int&				operator=(const glm::vec3& other);
		Vector2int&				operator=(const glm::vec4& other);
		Vector2int&				operator=(const sf::Vector2f& other);
		Vector2int&				operator=(const sf::Vector3f& other);
		Vector2int&				operator=(const sf::Vector2i& other);
		Vector2int&				operator=(const sf::Vector3i& other);
		Vector2int&				operator=(const ImVec2& other);
		Vector2int&				operator=(const ImVec4& other);

		Vector2int&				operator+=(const Vector2int& other);
		Vector2int&				operator-=(const Vector2int& other);
		Vector2int&				operator*=(const Vector2int& other);
		Vector2int&				operator*=(float number);
		Vector2int&				operator*=(int number);
		Vector2int&				operator/=(const Vector2int& other);
		Vector2int&				operator/=(float number);
		Vector2int&				operator/=(int number);
		Vector2int				operator+() const;
		Vector2int				operator-() const;

		float					get_norm() const;
		float					get_norm_2() const;
		const int*				get_ptr() const;

		void					clear();

		std::array<float, 2>	to_array_float() const;
		std::array<int, 2>		to_array_int() const;
		glm::vec2				to_glm() const;
		sf::Vector2f			to_sf_float() const;
		sf::Vector2i			to_sf_int() const;
		ImVec2					to_imgui() const;
	};

	Vector2int		operator+(const Vector2int& vector_1, const Vector2int& vector_2);
	Vector2int		operator-(const Vector2int& vector_1, const Vector2int& vector_2);
	Vector2int		operator*(float number, const Vector2int& vector);
	Vector2int		operator*(const Vector2int& vector, float number);
	Vector2int		operator*(int number, const Vector2int& vector);
	Vector2int		operator*(const Vector2int& vector, int number);
	Vector2int		operator*(const Vector2int& vector_1, const Vector2int& vector_2);
	Vector2int		operator/(float number, const Vector2int& vector);
	Vector2int		operator/(const Vector2int& vector, float number);
	Vector2int		operator/(int number, const Vector2int& vector);
	Vector2int		operator/(const Vector2int& vector, int number);
	Vector2int		operator/(const Vector2int& vector_1, const Vector2int& vector_2);
	bool			operator==(const Vector2int& vector_1, const Vector2int& vector_2);
	bool			operator!=(const Vector2int& vector_1, const Vector2int& vector_2);
	std::ostream&	operator<<(std::ostream& os, const Vector2int& vector);

	float			distance(const Vector2int& point_1, const Vector2int& point_2);
	float			distance_2(const Vector2int& point_1, const Vector2int& point_2);
}

#endif
