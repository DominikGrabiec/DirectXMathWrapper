#include "Precompiled.hpp"
#include "Vector4.hpp"

namespace Math
{
	const Vector4 Vector4::ZERO(0.0f, 0.0f, 0.0f, 0.0f);
	const Vector4 Vector4::UNIT_X(1.0f, 0.0f, 0.0f, 0.0f);
	const Vector4 Vector4::UNIT_Y(0.0f, 1.0f, 0.0f, 0.0f);
	const Vector4 Vector4::UNIT_Z(0.0f, 0.0f, 1.0f, 0.0f);
	const Vector4 Vector4::UNIT_W(0.0f, 0.0f, 0.0f, 1.0f);


	float Vector4::length() const
	{
		return DirectX::XMVectorGetX(XMVector4Length(*this));
	}

	float Vector4::length_squared() const
	{
		return DirectX::XMVectorGetX(XMVector4LengthSq(*this));
	}

	void Vector4::normalise()
	{
		*this = DirectX::XMVector4Normalize(*this);
	}

	Vector4 Vector4::normalise() const
	{
		return Vector4(DirectX::XMVector4Normalize(*this));
	}

	float Vector4::dot(const Vector4& v) const
	{
		return DirectX::XMVectorGetX(DirectX::XMVector4Dot(*this, v));
	}

	Vector4 Vector4::cross(const Vector4& a, const Vector4& b) const
	{
		return Vector4(DirectX::XMVector4Cross(*this, a, b));
	}

	Vector4 Vector4::lerp(const Vector4& a, const Vector4& b, float t)
	{
		return Vector4(DirectX::XMVectorLerp(a, b, t));
	}

	Vector4 Vector4::minimise(const Vector4& a, const Vector4& b)
	{
		return Vector4(DirectX::XMVectorMin(a, b));
	}

	Vector4 Vector4::maximise(const Vector4& a, const Vector4& b)
	{
		return Vector4(DirectX::XMVectorMax(a, b));
	}

} // namespace Math
