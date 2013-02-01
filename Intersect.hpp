#pragma once
#ifndef __MATHS_INTERSECT_HPP__
#define __MATHS_INTERSECT_HPP__

namespace Math
{
	class Vector3;
	class Line;
	class Ray;
	class Plane;
	class BoundingSphere;
	class BoundingBox;

	namespace Intersect
	{
		class LinearResult
		{
		private:
			float distance_;
			bool intersect_;

		public:
			LinearResult() : distance_(0.0f), intersect_(false)
			{
			}

			explicit LinearResult(float distance) : distance_(distance), intersect_(true)
			{
			}

			LinearResult(bool intersect, float distance) : distance_(distance), intersect_(intersect)
			{
			}

			LinearResult(const LinearResult& result) : distance_(result.distance_), intersect_(result.intersect_)
			{
			}

			LinearResult& operator = (const LinearResult& result)
			{
				distance_ = result.distance_;
				intersect_ = result.intersect_;
				return *this;
			}

			bool intersects() const
			{
				return intersect_;
			}

			float distance() const
			{
				return distance_;
			}
		};

		// Result is: (Intersects, Distance from Origin)
		LinearResult test(const Ray& ray, const Plane& plane);
		LinearResult test(const Ray& ray, const BoundingSphere& sphere);
		LinearResult test(const Ray& ray, const BoundingBox& box);

		// Result is: (Intersects, Distance along Line [0, 1])
		LinearResult test(const Line& line, const Plane& plane);
		LinearResult test(const Line& line, const BoundingSphere& sphere);
		LinearResult test(const Line& line, const BoundingBox& box);


		// Result is:
		// Disjoint => A and B are completely separate
		// Intersect => A and B touch or occupy the same space
		// Contains => A contains B
		// Contained => B contains A (A is contained by B)
		// Identical => A == B
		enum VolumeResult
		{
			VOLUME_DISJOINT,
			VOLUME_INTERSECT,
			VOLUME_CONTAINS,
			VOLUME_CONTAINED,
			VOLUME_IDENTICAL
		};

		VolumeResult test(const BoundingSphere& sphereA, const BoundingSphere& sphereB);
		VolumeResult test(const BoundingSphere& sphereA, const BoundingBox& boxB);
		VolumeResult test(const BoundingBox& boxA, const BoundingSphere& sphereB);
		VolumeResult test(const BoundingBox& boxA, const BoundingBox& boxB);


		// Result is: 
		//  < 0 => Outside negative plane side
		//  = 0 => Intersects plane
		//  > 0 => Outside positive plane side
		enum PlaneResult : sint_t
		{
			OUTSIDE_PLANE = -1,
			INTERSECTS_PLANE = 0,
			INSIDE_PLANE = 1
		};

		PlaneResult test(const Plane& plane, const Vector3& point);
		PlaneResult test(const Plane& plane, const BoundingSphere& sphere);
		PlaneResult test(const Plane& plane, const BoundingBox& box);

	} // namespace Intersect

} // namespace Math

#endif // __MATHS_INTERSECT_HPP__
