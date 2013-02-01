#include "Precompiled.hpp"
#include "Matrix.hpp"

namespace Math
{
	const Matrix Matrix::IDENTITY(1.0f, 0.0f, 0.0f, 0.0f,
								  0.0f, 1.0f, 0.0f, 0.0f,
								  0.0f, 0.0f, 1.0f, 0.0f,
								  0.0f, 0.0f, 0.0f, 1.0f);

	bool Matrix::decompose(Quaternion& rotation, Vector3& translation, Vector3& scale)
	{
		DirectX::XMVECTOR s;
		DirectX::XMVECTOR r;
		DirectX::XMVECTOR t;
		const bool result = DirectX::XMMatrixDecompose(&s, &r, &t, *this) == TRUE;
		rotation = r;
		translation = t;
		scale = s;
		return result;
	}

	float Matrix::operator () (uint_t row, uint_t column) const
	{
		// ASSERT(row < 4)
		// ASSERT(column < 4)
		return DirectX::XMVectorGetByIndex(r[row], column);
	}

	Vector4 Matrix::row(uint_t i) const
	{
		// ASSERT(i < 4);
		return Vector4(r[i]);
	}

	Vector4 Matrix::column(uint_t i) const
	{
		// ASSERT(i < 4);
		return Vector4(DirectX::XMVectorGetByIndex(r[0], i), DirectX::XMVectorGetByIndex(r[1], i), DirectX::XMVectorGetByIndex(r[2], i), DirectX::XMVectorGetByIndex(r[3], i));
	}
}
