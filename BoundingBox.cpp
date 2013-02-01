#include "Precompiled.hpp"
#include "BoundingBox.hpp"

#include <algorithm>

namespace
{
	Math::BoundingBox::BoxCorner operator ++ (Math::BoundingBox::BoxCorner& corner, int)
	{
		Math::BoundingBox::BoxCorner old_corner = corner;
		corner = static_cast<Math::BoundingBox::BoxCorner>(corner + 1); 
		return old_corner;
	}
}

namespace Math
{
	BoundingBox::BoundingBox()
	{
	}

	BoundingBox::BoundingBox(const Vector3& minimum, const Vector3& maximum) :
		minimum_(Vector3::minimise(minimum, maximum)),
		maximum_(Vector3::maximise(minimum, maximum))
	{
	}

	bool BoundingBox::contains(const Vector3& point) const
	{
		return
			(minimum_.x <= point.x && point.x <= maximum_.x) && 
			(minimum_.y <= point.y && point.y <= maximum_.y) &&
			(minimum_.z <= point.z && point.z <= maximum_.z);
	}

	void BoundingBox::set(const Vector3& minimum, const Vector3& maximum)
	{
		minimum_ = Vector3::minimise(minimum, maximum);
		maximum_ = Vector3::maximise(minimum, maximum);
	}

	Vector3 BoundingBox::get_corner(BoxCorner corner) const
	{
		const float x = (corner & 1) ? maximum_.x : minimum_.x;
		const float y = (corner & 2) ? maximum_.y : minimum_.y;
		const float z = (corner & 4) ? maximum_.z : minimum_.z;
		return Vector3(x, y, z);
	}

	BoundingBox::CornerArray BoundingBox::get_all_corners() const
	{
		CornerArray result;
		BoxCorner corner = NEAR_BOTTOM_LEFT;

		std::generate_n(std::begin(result), result.size(), [this, &corner]() { return get_corner(corner++); });

		return result;
	}

	BoundingBox BoundingBox::compute_containing_box(const BoundingBox& a, const BoundingBox& b)
	{
		return BoundingBox(Vector3::minimise(a.minimum_corner(), b.minimum_corner()), Vector3::maximise(a.maximum_corner(), b.maximum_corner()));
	}
}
