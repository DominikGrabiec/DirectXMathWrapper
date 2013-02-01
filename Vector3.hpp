#pragma once
#ifndef __MATHS_VECTOR3_HPP__
#define __MATHS_VECTOR3_HPP__

namespace Math
{
	class Vector3 : public DirectX::XMFLOAT3A
	{
	public:
		//--------------------------------------------------------------------------
		// Constructors
		//

		Vector3() : DirectX::XMFLOAT3A()
		{
		}

		Vector3(float x, float y, float z) : DirectX::XMFLOAT3A(x, y, z)
		{
		}

		explicit Vector3(const float* v) : DirectX::XMFLOAT3A(v)
		{
		}

		explicit Vector3(DirectX::FXMVECTOR v)
		{
			DirectX::XMStoreFloat3A(this, v);
		}

		Vector3(const Vector3& v) : DirectX::XMFLOAT3A(v)
		{
		}

		//--------------------------------------------------------------------------
		// Assignment
		//

		Vector3& operator = (DirectX::FXMVECTOR v)
		{
			DirectX::XMStoreFloat3A(this, v);
			return *this;
		}

		Vector3& operator = (const Vector3& v)
		{
			x = v.x;
			y = v.y;
			z = v.z;
			return *this;
		}

		//--------------------------------------------------------------------------
		// Conversion
		//

		operator DirectX::XMVECTOR () const
		{
			return DirectX::XMLoadFloat3A(this);
		}

		//--------------------------------------------------------------------------
		// Comparison
		//

		bool operator == (const Vector3& v) const
		{
			return x == v.x && y == v.y && z == v.z;
		}

		bool operator != (const Vector3& v) const
		{
			return x != v.x || y != v.y || z != v.z;
		}

		bool operator < (const Vector3& v) const
		{
			return x < v.x && y < v.y && z < v.z;
		}

		bool operator <= (const Vector3& v) const
		{
			return x <= v.x && y <= v.y && z <= v.z;
		}

		bool operator > (const Vector3& v) const
		{
			return x > v.x && y > v.y && z > v.z;
		}

		bool operator >= (const Vector3& v) const
		{
			return x >= v.x && y >= v.y && z >= v.z;
		}

		//--------------------------------------------------------------------------
		// Computation
		//

		float length() const;

		float length_squared() const;

		void normalise();

		Vector3 normalise() const;

		float dot(const Vector3& v) const;

		Vector3 cross(const Vector3& v) const;

		//--------------------------------------------------------------------------
		// Arithmetic Operators
		//

		Vector3 operator + (const Vector3& v) const
		{
			return Vector3(DirectX::XMVectorAdd(*this, v));
		}

		Vector3 operator - (const Vector3& v) const
		{
			return Vector3(DirectX::XMVectorSubtract(*this, v));
		}

		Vector3 operator * (const Vector3& v) const
		{
			return Vector3(DirectX::XMVectorMultiply(*this, v));
		}

		Vector3 operator / (const Vector3& v) const
		{
			return Vector3(DirectX::XMVectorDivide(*this, v));
		}

		Vector3 operator - () const
		{
			return Vector3(-x, -y, -z);
		}

		Vector3 operator * (const float n) const
		{
			return Vector3(DirectX::XMVectorMultiply(*this, DirectX::XMVectorReplicate(n)));
		}

		friend Vector3 operator * (const float n, const Vector3& v)
		{
			return Vector3(DirectX::XMVectorMultiply(DirectX::XMVectorReplicate(n), v));
		}

		Vector3 operator / (const float n) const
		{
			return Vector3(DirectX::XMVectorDivide(*this, DirectX::XMVectorReplicate(n)));
		}

		Vector3& operator += (const Vector3& v)
		{
			return *this = DirectX::XMVectorAdd(*this, v);
		}

		Vector3& operator -= (const Vector3& v)
		{
			return *this = DirectX::XMVectorSubtract(*this, v);
		}

		Vector3& operator *= (const Vector3& v)
		{
			return *this = DirectX::XMVectorMultiply(*this, v);
		}

		Vector3& operator /= (const Vector3& v)
		{
			return *this = DirectX::XMVectorDivide(*this, v);
		}

		Vector3& operator *= (const float n)
		{
			return *this = DirectX::XMVectorMultiply(*this, DirectX::XMVectorReplicate(n));
		}

		Vector3& operator /= (const float n)
		{
			return *this = DirectX::XMVectorDivide(*this, DirectX::XMVectorReplicate(n));
		}

		//--------------------------------------------------------------------------
		// Auxilliary Functions
		//

		static Vector3 lerp(const Vector3& a, const Vector3& b, float t);

		static Vector3 minimise(const Vector3& a, const Vector3& b);

		static Vector3 maximise(const Vector3& a, const Vector3& b);

		//--------------------------------------------------------------------------
		// Constants
		//

		static const Vector3 ZERO;
		static const Vector3 UNIT_X;
		static const Vector3 UNIT_Y;
		static const Vector3 UNIT_Z;
	};

} // namespace Math

#endif // __MATHS_VECTOR3_HPP__
