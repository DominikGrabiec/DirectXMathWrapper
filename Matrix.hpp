#pragma once
#ifndef __MATHS_MATRIX_HPP__
#define __MATHS_MATRIX_HPP__

#include "Vector3.hpp"
#include "Vector4.hpp"
#include "Quaternion.hpp"

namespace Math
{
	class Matrix : public DirectX::XMMATRIX
	{
	public:
		//--------------------------------------------------------------------------
		// Constructors
		//

		Matrix() : DirectX::XMMATRIX() 
		{
		}

		Matrix(DirectX::XMVECTOR _1, DirectX::XMVECTOR _2, DirectX::XMVECTOR _3, DirectX::XMVECTOR _4) : DirectX::XMMATRIX(_1, _2, _3, _4)
		{
		}

		Matrix(float _11, float _12, float _13, float _14,
			   float _21, float _22, float _23, float _24,
			   float _31, float _32, float _33, float _34,
			   float _41, float _42, float _43, float _44) : DirectX::XMMATRIX(_11, _12, _13, _14, _21, _22, _23, _24, _31, _32, _33, _34, _41, _42, _43, _44)
		{
		}

		explicit Matrix(const float* v) : DirectX::XMMATRIX(v) 
		{
		}

		explicit Matrix(DirectX::CXMMATRIX m) : DirectX::XMMATRIX(m) 
		{
		}

		Matrix(const Matrix& matrix) : DirectX::XMMATRIX(matrix)
		{
		}

		//--------------------------------------------------------------------------
		// Assignment
		//

		Matrix& operator = (DirectX::CXMMATRIX m)
		{
			if (&m != this)
			{
				*static_cast<DirectX::XMMATRIX*>(this) = m;
			}
			return *this;
		}

		Matrix& operator = (const Matrix& m)
		{
			if (&m != this)
			{
				*static_cast<DirectX::XMMATRIX*>(this) = m;
			}
			return *this;
		}

		//--------------------------------------------------------------------------
		// Accessors
		//

		float operator () (uint_t row, uint_t column) const;

		Vector4 row(uint_t i) const;

		Vector4 column(uint_t i) const;

		//--------------------------------------------------------------------------
		// Arithmetic Operators
		//

		Matrix operator * (const Matrix& m) const
		{
			return static_cast<Matrix>(DirectX::XMMatrixMultiply(*this, m));
		}

		Matrix operator *= (const Matrix& m)
		{
			*this = (DirectX::XMMatrixMultiply(*this, m));
			return *this;
		}

		//--------------------------------------------------------------------------
		// Computation
		//

		float determinant() const
		{
			return DirectX::XMVectorGetX(DirectX::XMMatrixDeterminant(*this));
		}

		bool decompose(Quaternion& rotation, Vector3& translation, Vector3& scale);

		void invert(float* determinant = nullptr)
		{
			DirectX::XMVECTOR det;
			*this = DirectX::XMMatrixInverse(&det, *this);
			if (determinant)
			{
				*determinant = DirectX::XMVectorGetX(det);
			}
		}

		Matrix inverse(float* determinant = nullptr) const
		{
			DirectX::XMVECTOR det;
			DirectX::XMMATRIX mat = DirectX::XMMatrixInverse(&det, *this);
			if (determinant)
			{
				*determinant = DirectX::XMVectorGetX(det);
			}
			return static_cast<Matrix>(mat);
		}

		void transpose()
		{
			*this = DirectX::XMMatrixTranspose(*this);
		}

		Matrix transpose() const
		{
			return static_cast<Matrix>(DirectX::XMMatrixTranspose(*this));
		}

		Vector3 transform(const Vector3& v) const
		{
			return Vector3(DirectX::XMVector3Transform(v, *this));
		}

		Vector4 transform(const Vector4& v) const
		{
			return Vector4(DirectX::XMVector4Transform(v, *this));
		}

		bool is_identity() const
		{
			return DirectX::XMMatrixIsIdentity(*this) == TRUE;
		}

		//--------------------------------------------------------------------------
		// Constants
		//

		static const Matrix IDENTITY;

		//--------------------------------------------------------------------------
		// Auxilliary Functions
		//

		static Matrix rotation_axis(const Vector3& axis, float angle)
		{
			return static_cast<Matrix>(DirectX::XMMatrixRotationAxis(axis, angle));
		}

		static Matrix rotation_roll_pitch_yaw(float pitch, float yaw, float roll)
		{
			return static_cast<Matrix>(DirectX::XMMatrixRotationRollPitchYaw(pitch, yaw, roll));
		}

		static Matrix rotation_quaternion(const Quaternion& q)
		{
			return static_cast<Matrix>(DirectX::XMMatrixRotationQuaternion(q));
		}

		static Matrix scaling(float x, float y, float z)
		{
			return static_cast<Matrix>(DirectX::XMMatrixScaling(x, y, z));
		}

		static Matrix scaling(const Vector3& v)
		{
			return static_cast<Matrix>(DirectX::XMMatrixScalingFromVector(v));
		}

		static Matrix translation(float x, float y, float z)
		{
			return static_cast<Matrix>(DirectX::XMMatrixTranslation(x, y, z));
		}

		static Matrix translation(const Vector3& v)
		{
			return static_cast<Matrix>(DirectX::XMMatrixTranslationFromVector(v));
		}

		static Matrix affine_transformation(const Vector3& translation, const Quaternion& rotation)
		{
			return static_cast<Matrix>(DirectX::XMMatrixAffineTransformation(DirectX::XMVectorSplatOne(), DirectX::XMVectorZero(), rotation, translation));
		}

		static Matrix affine_transformation(const Vector3& translation, const Quaternion& rotation, const Vector3& scale, const Vector3& rotation_centre = Vector3::ZERO)
		{
			return static_cast<Matrix>(DirectX::XMMatrixAffineTransformation(scale, rotation_centre, rotation, translation));
		}

		static Matrix look_at(const Vector3& position, const Vector3& target, const Vector3& up)
		{
			return static_cast<Matrix>(XMMatrixLookAtLH(position, target, up));
		}

		static Matrix orthographic(float width, float height, float nearZ, float farZ)
		{
			return static_cast<Matrix>(DirectX::XMMatrixOrthographicLH(width, height, nearZ, farZ));
		}

		static Matrix perspective(float width, float height, float nearZ, float farZ)
		{
			return static_cast<Matrix>(DirectX::XMMatrixPerspectiveLH(width, height, nearZ, farZ));
		}

		static Matrix perspective_fov(float fov, float aspect, float nearZ, float farZ)
		{
			return static_cast<Matrix>(DirectX::XMMatrixPerspectiveFovLH(fov, aspect, nearZ, farZ));
		}
	};

} // namespace Math

#endif // __MATHS_MATRIX_HPP__
