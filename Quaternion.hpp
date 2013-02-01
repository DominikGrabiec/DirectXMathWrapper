#pragma once
#ifndef __MATHS_QUATERNION_HPP__
#define __MATHS_QUATERNION_HPP__

#include "Vector3.hpp"
#include "Vector4.hpp"

namespace Math
{

	class Quaternion : public DirectX::XMFLOAT4A
	{
	public:
		//--------------------------------------------------------------------------
		// Constructors
		//

		Quaternion()
		{
			DirectX::XMStoreFloat4A(this, DirectX::XMQuaternionIdentity());
		}

		Quaternion(float x, float y, float z, float w) : DirectX::XMFLOAT4A(z, y, z, w) 
		{
		}

		Quaternion(float yaw, float pitch, float roll)
		{
			DirectX::XMStoreFloat4A(this, DirectX::XMQuaternionRotationRollPitchYaw(pitch, yaw, roll));
		}

		Quaternion(const Vector3& axis, float angle)
		{
			DirectX::XMStoreFloat4A(this, DirectX::XMQuaternionRotationAxis(axis, angle));
		}

		explicit Quaternion(const float* values) : DirectX::XMFLOAT4A(values) 
		{
		}

		explicit Quaternion(DirectX::FXMVECTOR v) 
		{
			DirectX::XMStoreFloat4A(this, v);
		}

		Quaternion(const Quaternion& q) : DirectX::XMFLOAT4A(q) 
		{
		}

		//--------------------------------------------------------------------------
		// Assignment
		//

		Quaternion& operator = (DirectX::FXMVECTOR v)
		{
			DirectX::XMStoreFloat4A(this, v);
			return *this;
		}

		Quaternion& operator = (const Quaternion& q)
		{
			x = q.x;
			y = q.y;
			z = q.z;
			w = q.w;
			return *this;
		}

		//--------------------------------------------------------------------------
		// Conversion
		//

		operator DirectX::XMVECTOR () const
		{
			return DirectX::XMLoadFloat4A(this);
		}

		//--------------------------------------------------------------------------
		// Comparison
		//

		bool operator == (const Quaternion& q) const
		{
			return x == q.x && y == q.y && z == q.z && w == q.w;
		}

		bool operator != (const Quaternion& q) const
		{
			return x != q.x || y != q.y || z != q.z || w != q.w;
		}

		//--------------------------------------------------------------------------
		// Inspection
		//

		bool is_identity() const
		{
			return DirectX::XMQuaternionIsIdentity(*this);
		}

		//--------------------------------------------------------------------------
		// Computation
		//

		void from_axis_angle(const Vector3& axis, float angle)
		{
			DirectX::XMStoreFloat4A(this, DirectX::XMQuaternionRotationAxis(axis, angle));
		}

		void to_axis_angle(Vector3& axis, float& angle) const
		{
			DirectX::XMVECTOR a;
			DirectX::XMQuaternionToAxisAngle(&a, &angle, *this);
			axis = a;
		}

		float dot(const Quaternion& q) const
		{
			return DirectX::XMVectorGetX(DirectX::XMQuaternionDot(*this, q));
		}

		float length() const
		{
			return DirectX::XMVectorGetX(DirectX::XMQuaternionLength(*this));
		}

		float length_squared() const
		{
			return DirectX::XMVectorGetX(DirectX::XMQuaternionLengthSq(*this));
		}

		void normalise()
		{
			DirectX::XMStoreFloat4A(this, DirectX::XMQuaternionNormalize(*this));
		}

		Quaternion conjugate() const
		{
			return Quaternion(DirectX::XMQuaternionConjugate(*this));
		}

		Quaternion inverse() const
		{
			return Quaternion(DirectX::XMQuaternionInverse(*this));
		}

		Quaternion exp() const
		{
			return Quaternion(DirectX::XMQuaternionExp(*this));
		}

		Quaternion ln() const
		{
			return Quaternion(DirectX::XMQuaternionLn(*this));
		}

		Quaternion slerp(const Quaternion& q, float t) const
		{
			return Quaternion(DirectX::XMQuaternionSlerp(*this, q, t));
		}

		Vector3 transform(const Vector3& v) const;

		//--------------------------------------------------------------------------
		// Constants
		//

		static const Quaternion IDENTITY;
	};

} // namespace Math

#endif // __MATHS_QUATERNION_HPP__
