#include "Precompiled.hpp"
#include "Vector3.hpp"

namespace Math
{
	const Vector3 Vector3::ZERO(0.0f, 0.0f, 0.0f);
	const Vector3 Vector3::UNIT_X(1.0f, 0.0f, 0.0f);
	const Vector3 Vector3::UNIT_Y(0.0f, 1.0f, 0.0f);
	const Vector3 Vector3::UNIT_Z(0.0f, 0.0f, 1.0f);


	float Vector3::length() const
	{
		return DirectX::XMVectorGetX(DirectX::XMVector3Length(*this));
	}

	float Vector3::length_squared() const
	{
		return DirectX::XMVectorGetX(DirectX::XMVector3LengthSq(*this));
	}

	void Vector3::normalise()
	{
		*this = DirectX::XMVector3Normalize(*this);
	}

	Vector3 Vector3::normalise() const
	{
		return Vector3(DirectX::XMVector3Normalize(*this));
	}

	float Vector3::dot(const Vector3& v) const
	{
		return DirectX::XMVectorGetX(DirectX::XMVector3Dot(*this, v));
	}

	Vector3 Vector3::cross(const Vector3& v) const
	{
		return Vector3(DirectX::XMVector3Cross(*this, v));
	}

	Vector3 Vector3::lerp(const Vector3& a, const Vector3& b, float t)
	{
		return Vector3(DirectX::XMVectorLerp(a, b, t));
	}

	Vector3 Vector3::minimise(const Vector3& a, const Vector3& b)
	{
		return Vector3(DirectX::XMVectorMin(a, b));
	}

	Vector3 Vector3::maximise(const Vector3& a, const Vector3& b)
	{
		return Vector3(DirectX::XMVectorMax(a, b));
	}

} // namespace Math
