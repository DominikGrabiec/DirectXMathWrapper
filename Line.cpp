#include "Precompiled.hpp"
#include "Line.hpp"

namespace Math
{
	float Line::length() const
	{
		return DirectX::XMVectorGetX(DirectX::XMVector3Length(DirectX::XMVectorSubtract(end_point, start_point)));
	}

	float Line::length_squared() const
	{
		return DirectX::XMVectorGetX(DirectX::XMVector3LengthSq(DirectX::XMVectorSubtract(end_point, start_point)));
	}

	Vector3 Line::direction() const
	{
		return Vector3(DirectX::XMVector3Normalize(DirectX::XMVectorSubtract(end_point, start_point)));
	}

	Vector3 Line::mid_point() const
	{
		static const float HALF = 0.5f;
		return Vector3(DirectX::XMVectorMultiply(XMVectorSubtract(end_point, start_point), DirectX::XMVectorReplicate(HALF)));
	}

	void Line::extend(float start_amount, float end_amount)
	{
		DirectX::XMVECTOR start = start_point;
		DirectX::XMVECTOR end = end_point;
		DirectX::XMVECTOR dir = DirectX::XMVector3Normalize(DirectX::XMVectorSubtract(end, start));
		start_point = DirectX::XMVectorSubtract(start, DirectX::XMVectorMultiply(dir, DirectX::XMVectorReplicate(start_amount)));
		end_point = DirectX::XMVectorAdd(end, DirectX::XMVectorMultiply(dir, DirectX::XMVectorReplicate(end_amount)));
	}
}
