#pragma once
#ifndef __MATHS_RAY_HPP__
#define __MATHS_RAY_HPP__

#include "Vector3.hpp"

namespace Math
{

	class Ray
	{
	private:
		// The values are private because we want to keep the direction vector normalised
		Vector3 origin_;
		Vector3 direction_;

	public:
		Ray() :	direction_(Vector3::UNIT_Z)
		{
		}

		Ray(const Vector3& origin, const Vector3& direction) : 
			origin_(origin),
			direction_(direction)
		{
			direction_.normalise();
		}

		Ray(const Ray& ray) :
			origin_(ray.origin_),
			direction_(ray.direction_)
		{
		}

		
		Ray& operator = (const Ray& ray)
		{
			origin_ = ray.origin_;
			direction_ = ray.direction_;
			return *this;
		}


		bool operator == (const Ray& ray) const
		{
			return origin_ == ray.origin_ && direction_ == ray.direction_;
		}

		bool operator != (const Ray& ray) const
		{
			return origin_ != ray.origin_ || direction_ != ray.direction_;
		}


		Vector3 point_at(float t) const
		{
			return origin_ + direction_ * t;
		}

		Vector3 operator * (float t) const
		{
			return origin_ + direction_ * t;
		}

		friend Vector3 operator * (float t, const Ray& ray)
		{
			return ray.origin_ + ray.direction_ * t;
		}


		void origin(const Vector3& o)
		{
			origin_ = o;
		}

		const Vector3& origin() const
		{
			return origin_;
		}


		void direction(const Vector3& d)
		{
			direction_ = d;
			direction_.normalise();
		}

		const Vector3& direction() const
		{
			return direction_;
		}
	};

} // namespace Math

#endif // __MATHS_RAY_HPP__
