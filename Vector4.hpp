#pragma once
#ifndef __MATHS_VECTOR4_HPP__
#define __MATHS_VECTOR4_HPP__

namespace Math
{
	class Vector4 : public DirectX::XMFLOAT4A
	{
	public:
		//--------------------------------------------------------------------------
		// Constructors
		//

		Vector4() : DirectX::XMFLOAT4A()
		{
		}

		Vector4(float x, float y, float z, float w) : DirectX::XMFLOAT4A(x, y, z, w)
		{
		}

		explicit Vector4(const float* v) : DirectX::XMFLOAT4A(v)
		{
		}

		explicit Vector4(DirectX::FXMVECTOR v)
		{
			DirectX::XMStoreFloat4A(this, v);
		}

		Vector4(const Vector4& v) : DirectX::XMFLOAT4A(v)
		{
		}

		//--------------------------------------------------------------------------
		// Assignment
		//

		Vector4& operator = (DirectX::FXMVECTOR v)
		{
			DirectX::XMStoreFloat4A(this, v);
			return *this;
		}

		Vector4& operator = (const Vector4& v)
		{
			x = v.x;
			y = v.y;
			z = v.z;
			w = v.w;
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

		bool operator == (const Vector4& v) const
		{
			return x == v.x && y == v.y && z == v.z && w == v.w;
		}

		bool operator != (const Vector4& v) const
		{
			return x != v.x || y != v.y || z != v.z || w != v.w;
		}

		bool operator < (const Vector4& v) const
		{
			return x < v.x && y < v.y && z < v.z && w < v.w;
		}

		bool operator <= (const Vector4& v) const
		{
			return x <= v.x && y <= v.y && z <= v.z && w <= v.w;
		}

		bool operator > (const Vector4& v) const
		{
			return x > v.x && y > v.y && z > v.z && w > v.w;
		}

		bool operator >= (const Vector4& v) const
		{
			return x >= v.x && y >= v.y && z >= v.z && w >= v.w;
		}

		//--------------------------------------------------------------------------
		// Computation
		//

		float length() const;

		float length_squared() const;

		void normalise();

		Vector4 normalise() const;

		float dot(const Vector4& v) const;

		Vector4 cross(const Vector4& a, const Vector4& b) const;

		//--------------------------------------------------------------------------
		// Arithmetic Operators
		//

		Vector4 operator + (const Vector4& v) const
		{
			return Vector4(DirectX::XMVectorAdd(*this, v));
		}

		Vector4 operator - (const Vector4& v) const
		{
			return Vector4(DirectX::XMVectorSubtract(*this, v));
		}

		Vector4 operator * (const Vector4& v) const
		{
			return Vector4(DirectX::XMVectorMultiply(*this, v));
		}

		Vector4 operator / (const Vector4& v) const
		{
			return Vector4(DirectX::XMVectorDivide(*this, v));
		}

		Vector4 operator - () const
		{
			return Vector4(-x, -y, -z, -w);
		}

		Vector4 operator * (const float n) const
		{
			return Vector4(DirectX::XMVectorMultiply(*this, DirectX::XMVectorReplicate(n)));
		}

		friend Vector4 operator * (const float n, const Vector4& v)
		{
			return Vector4(DirectX::XMVectorMultiply(DirectX::XMVectorReplicate(n), v));
		}

		Vector4 operator / (const float n) const
		{
			return Vector4(DirectX::XMVectorDivide(*this, DirectX::XMVectorReplicate(n)));
		}

		Vector4& operator += (const Vector4& v)
		{
			return *this = DirectX::XMVectorAdd(*this, v);
		}

		Vector4& operator -= (const Vector4& v)
		{
			return *this = DirectX::XMVectorSubtract(*this, v);
		}

		Vector4& operator *= (const Vector4& v)
		{
			return *this = DirectX::XMVectorMultiply(*this, v);
		}

		Vector4& operator /= (const Vector4& v)
		{
			return *this = DirectX::XMVectorDivide(*this, v);
		}

		Vector4& operator *= (const float n)
		{
			return *this = DirectX::XMVectorMultiply(*this, DirectX::XMVectorReplicate(n));
		}

		Vector4& operator /= (const float n)
		{
			return *this = DirectX::XMVectorDivide(*this, DirectX::XMVectorReplicate(n));
		}

		//--------------------------------------------------------------------------
		// Auxilliary Functions
		//

		static Vector4 lerp(const Vector4& a, const Vector4& b, float t);

		static Vector4 minimise(const Vector4& a, const Vector4& b);

		static Vector4 maximise(const Vector4& a, const Vector4& b);

		//--------------------------------------------------------------------------
		// Constants
		//

		static const Vector4 ZERO;
		static const Vector4 UNIT_X;
		static const Vector4 UNIT_Y;
		static const Vector4 UNIT_Z;
		static const Vector4 UNIT_W;
	};

} // namespace Math

#endif // __MATHS_VECTOR4_HPP__
