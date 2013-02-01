#pragma once
#ifndef __MATHS_BOUNDINGSPHERE_HPP__
#define __MATHS_BOUNDINGSPHERE_HPP__

#include "Vector3.hpp"

#include <type_traits>
#include <iterator>
#include <algorithm>
#include <functional>
#include <numeric>

namespace Math
{

	class BoundingSphere
	{
	private:
		Vector3 center_;
		float radius_;

	public:
		//--------------------------------------------------------------------------
		// Constructors
		//

		BoundingSphere() : radius_(0.0f)
		{
		}

		BoundingSphere(const Vector3& center, float radius) : center_(center), radius_(std::abs(radius))
		{
		}

		BoundingSphere(const BoundingSphere& sphere) : center_(sphere.center_), radius_(sphere.radius_)
		{
		}

		//--------------------------------------------------------------------------
		// Assignment
		//

		BoundingSphere& operator = (const BoundingSphere& sphere)
		{
			center_ = sphere.center_;
			radius_ = sphere.radius_;
			return *this;
		}

		//--------------------------------------------------------------------------
		// Comparison
		//

		bool operator == (const BoundingSphere& sphere) const
		{
			return center_ == sphere.center_ && radius_ == sphere.radius_;
		}

		bool operator != (const BoundingSphere& sphere) const
		{
			return center_ != sphere.center_ || radius_ != sphere.radius_;
		}

		bool contains(const Vector3& point) const
		{
			return Vector3(center_ - point).length_squared() <= radius_ * radius_;
		}

		bool is_empty()
		{
			return radius_ <= FLT_EPSILON;
		}

		//--------------------------------------------------------------------------
		// Accessors
		//

		void set(const Vector3& center, float radius)
		{
			center_ = center;
			radius_ = std::abs(radius);
		}

		void center(const Vector3& center)
		{
			center_ = center;
		}

		const Vector3& center() const
		{
			return center_;
		}

		void radius(float radius)
		{
			radius_ = std::abs(radius);
		}

		float radius() const
		{
			return radius_;
		}

		static BoundingSphere compute_containing_sphere(const BoundingSphere& a, const BoundingSphere& b);

		template <class Iterator>
		typename std::enable_if<std::is_same<typename std::iterator_traits<Iterator>::value_type, BoundingSphere>::value, BoundingSphere>::type 
			static compute_containing_sphere(Iterator begin, Iterator end)
		{
			if (begin != end)
			{
				BoundingSphere bounds = *begin++;
				return std::accumulate(begin, end, bounds, std::ptr_fun(&compute_containing_sphere));
			}

			return BoundingSphere();
		}
	};

} // namespace Math

#endif // __MATHS_BOUNDINGSPHERE_H__
