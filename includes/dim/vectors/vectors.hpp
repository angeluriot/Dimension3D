#ifndef VECTORS_HPP
#define VECTORS_HPP

#include "dim/utils/libraries.hpp"

namespace dim
{
	Vector2	operator+(const Vector2& vector_1, const Vector2int& vector_2);
	Vector2	operator+(const Vector2int& vector_1, const Vector2& vector_2);
	Vector2	operator-(const Vector2& vector_1, const Vector2int& vector_2);
	Vector2	operator-(const Vector2int& vector_1, const Vector2& vector_2);
	Vector2	operator*(const Vector2& vector_1, const Vector2int& vector_2);
	Vector2	operator*(const Vector2int& vector_1, const Vector2& vector_2);
	Vector2	operator/(const Vector2& vector_1, const Vector2int& vector_2);
	Vector2	operator/(const Vector2int& vector_1, const Vector2& vector_2);

	Vector3	operator+(const Vector3& vector_1, const Vector3int& vector_2);
	Vector3	operator+(const Vector3int& vector_1, const Vector3& vector_2);
	Vector3	operator-(const Vector3& vector_1, const Vector3int& vector_2);
	Vector3	operator-(const Vector3int& vector_1, const Vector3& vector_2);
	Vector3	operator*(const Vector3& vector_1, const Vector3int& vector_2);
	Vector3	operator*(const Vector3int& vector_1, const Vector3& vector_2);
	Vector3	operator/(const Vector3& vector_1, const Vector3int& vector_2);
	Vector3	operator/(const Vector3int& vector_1, const Vector3& vector_2);

	Vector4	operator+(const Vector4& vector_1, const Vector4int& vector_2);
	Vector4	operator+(const Vector4int& vector_1, const Vector4& vector_2);
	Vector4	operator-(const Vector4& vector_1, const Vector4int& vector_2);
	Vector4	operator-(const Vector4int& vector_1, const Vector4& vector_2);
	Vector4	operator*(const Vector4& vector_1, const Vector4int& vector_2);
	Vector4	operator*(const Vector4int& vector_1, const Vector4& vector_2);
	Vector4	operator/(const Vector4& vector_1, const Vector4int& vector_2);
	Vector4	operator/(const Vector4int& vector_1, const Vector4& vector_2);
}

#endif
