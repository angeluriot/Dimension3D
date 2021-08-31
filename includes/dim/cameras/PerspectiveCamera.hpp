#ifndef DIM_PERSPECTIVECAMERA_HPP
#define DIM_PERSPECTIVECAMERA_HPP

#include "dim/cameras/Camera.hpp"

namespace dim
{
	class PerspectiveCamera : public Camera
	{
	private:

		float					fov;

		Camera*					clone() const override;

	public:

		static constexpr float	default_fov = 45.f;

								PerspectiveCamera(const PerspectiveCamera& other) = default;
								PerspectiveCamera(float fov = default_fov, float near = default_near, float far = default_far);

		Type					get_type() const override;
		float					get_fov() const;
		void					set_resolution(unsigned int width, unsigned int height) override;
		void					set_resolution(const Vector2int& resolution) override;
	};
}

#endif
