#pragma once
#ifndef __BOUNDINGBOX_HPP__
#define __BOUNDINGBOX_HPP__

#include "Vector3.hpp"

#include <type_traits>
#include <iterator>
#include <numeric>
#include <functional>
#include <array>

namespace Math
{

	class BoundingBox
	{
	public:
		enum BoxCorner
		{
			NEAR_BOTTOM_LEFT,
			NEAR_BOTTOM_RIGHT,
			NEAR_TOP_LEFT,
			NEAR_TOP_RIGHT,
			FAR_BOTTOM_LEFT,
			FAR_BOTTOM_RIGHT,
			FAR_TOP_LEFT,
			FAR_TOP_RIGHT
		};

		typedef std::array<Vector3, 8> CornerArray;

	private:
		Vector3 minimum_;
		Vector3 maximum_;

	public:
		//--------------------------------------------------------------------------
		// Constructors
		//

		BoundingBox();

		BoundingBox(const Vector3& minimum, const Vector3& maximum);

		BoundingBox(const BoundingBox& box) : minimum_(box.minimum_), maximum_(box.maximum_)
		{
		}

		//--------------------------------------------------------------------------
		// Assignment
		//

		BoundingBox& operator = (const BoundingBox& box)
		{
			minimum_ = box.minimum_;
			maximum_ = box.maximum_;
			return *this;
		}

		//--------------------------------------------------------------------------
		// Comparison
		//

		bool operator == (const BoundingBox& box) const
		{
			return minimum_ == box.minimum_ && maximum_ == box.maximum_;
		}

		bool operator != (const BoundingBox& box) const
		{
			return minimum_ != box.minimum_ || maximum_ != box.maximum_;
		}

		bool contains(const Vector3& point) const;

		bool is_empty() const
		{
			return minimum_ == maximum_;
		}

		//--------------------------------------------------------------------------
		// Accessors
		//

		void set(const Vector3& minimum, const Vector3& maximum);

		const Vector3& minimum_corner() const
		{
			return minimum_;
		}

		const Vector3& maximum_corner() const
		{
			return maximum_;
		}

		Vector3 get_corner(BoxCorner corner) const;

		CornerArray get_all_corners() const;

		//--------------------------------------------------------------------------
		// Computation
		//

		static BoundingBox compute_containing_box(const BoundingBox& a, const BoundingBox& b);

		template <class Iterator>
		typename std::enable_if<std::is_same<typename std::iterator_traits<Iterator>::value_type, BoundingBox>::value, BoundingBox>::type 
			static compute_containing_box(Iterator begin, Iterator end)
		{
			if (begin != end)
			{
				BoundingBox bounds = *begin++;
				return std::accumulate(begin, end, bounds, std::ptr_fun(&compute_containing_box));
			}

			return BoundingBox();
		}
	};

} // namespace Math


#endif // __BOUNDINGBOX_HPP__
