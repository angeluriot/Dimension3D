#ifndef DIM_VECTOR4INT_HPP
#define DIM_VECTOR4INT_HPP

#include "dim/utils/libraries.hpp"

namespace dim
{
	class Vector2;
	class Vector3;
	class Vector4;
	class Vector2int;
	class Vector3int;

	class Vector4int
	{
	public:

		int						x;
		int						y;
		int						z;
		int						w;

		static const Vector4int	null;

								Vector4int();
								Vector4int(const Vector4int& other) = default;
								Vector4int(int x, int y, int z, int w);
								Vector4int(const Vector2& other, int z, int w);
								Vector4int(int x, const Vector2& other, int w);
								Vector4int(int x, int y, const Vector2& other);
								Vector4int(const Vector3& other, int w);
								Vector4int(int x, const Vector3& other);
								Vector4int(const Vector4& other);
								Vector4int(const Vector2int& other, int z, int w);
								Vector4int(int x, const Vector2int& other, int w);
								Vector4int(int x, int y, const Vector2int& other);
								Vector4int(const Vector3int& other, int w);
								Vector4int(int x, const Vector3int& other);
								Vector4int(const std::array<float, 4>& other);
								Vector4int(const std::array<int, 4>& other);
								Vector4int(const glm::vec4& other);
								Vector4int(const ImVec4& other);

		Vector4int&				operator=(const Vector4int& other) = default;
		Vector4int&				operator=(const Vector4& other);
		Vector4int&				operator=(const std::array<float, 4>& other);
		Vector4int&				operator=(const std::array<int, 4>& other);
		Vector4int&				operator=(const glm::vec4& other);
		Vector4int&				operator=(const ImVec4& other);

		Vector4int&				operator+=(const Vector4int& other);
		Vector4int&				operator-=(const Vector4int& other);
		Vector4int&				operator*=(const Vector4int& other);
		Vector4int&				operator*=(float number);
		Vector4int&				operator*=(int number);
		Vector4int&				operator/=(const Vector4int& other);
		Vector4int&				operator/=(float number);
		Vector4int&				operator/=(int number);
		Vector4int				operator+() const;
		Vector4int				operator-() const;

		float					get_norm() const;
		float					get_norm_2() const;
		const int*				get_ptr() const;

		void					clear();

		std::array<float, 4>	to_array_float() const;
		std::array<int, 4>		to_array_int() const;
		glm::vec4				to_glm() const;
		ImVec4					to_imgui() const;
	};

	Vector4int		operator+(const Vector4int& vector_1, const Vector4int& vector_2);
	Vector4int		operator-(const Vector4int& vector_1, const Vector4int& vector_2);
	Vector4int		operator*(float number, const Vector4int& vector);
	Vector4int		operator*(const Vector4int& vector, float number);
	Vector4int		operator*(int number, const Vector4int& vector);
	Vector4int		operator*(const Vector4int& vector, int number);
	Vector4int		operator*(const Vector4int& vector_1, const Vector4int& vector_2);
	Vector4int		operator/(float number, const Vector4int& vector);
	Vector4int		operator/(const Vector4int& vector, float number);
	Vector4int		operator/(int number, const Vector4int& vector);
	Vector4int		operator/(const Vector4int& vector, int number);
	Vector4int		operator/(const Vector4int& vector_1, const Vector4int& vector_2);
	bool			operator==(const Vector4int& vector_1, const Vector4int& vector_2);
	bool			operator!=(const Vector4int& vector_1, const Vector4int& vector_2);
	std::ostream&	operator<<(std::ostream& os, const Vector4int& vector);

	float			distance(const Vector4int& point_1, const Vector4int& point_2);
	float			distance_2(const Vector4int& point_1, const Vector4int& point_2);
}

#endif
