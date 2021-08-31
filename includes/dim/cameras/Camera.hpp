#ifndef DIM_CAMERA_HPP
#define DIM_CAMERA_HPP

#include "dim/utils/libraries.hpp"
#include "dim/utils/utils.hpp"
#include "dim/windows/Window.hpp"

namespace dim
{
	class Scene;
	class Controller;
	class OrbitController;
	class FlyController;
	class DragController;
	class Window;

	class Camera
	{
	protected:

		Vector3					position;
		glm::mat4				view;
		glm::mat4				projection;
		Vector3					direction;
		float					yaw;
		float					pitch;
		float					near;
		float					far;

		virtual Camera*			clone() const = 0;

	public:

		enum class Type { Perspective, Orthographic };

		static constexpr float	default_near	= 0.1f;
		static constexpr float	default_far		= 100.f;

								Camera();
								Camera(const Camera& other) = default;

		Camera&					operator=(const Camera& other) = default;

		virtual Type			get_type() const = 0;
		glm::mat4				get_matrix() const;
		Vector3					get_position() const;
		void					set_position(const Vector3& position);
		void					set_position(float x, float y, float z);
		Vector3					get_direction() const;
		void					set_direction(const Vector3& direction);
		void					set_direction(float yaw, float pitch);
		float					get_yaw() const;
		void					set_yaw(float yaw);
		float					get_pitch() const;
		void					set_pitch(float pitch);
		float					get_near() const;
		float					get_far() const;
		virtual void			set_resolution(unsigned int width, unsigned int height) = 0;
		virtual void			set_resolution(const Vector2int& resolution) = 0;

		friend					Controller;
		friend					OrbitController;
		friend					FlyController;
		friend					DragController;
		friend					Scene;
		friend					Window;
	};
}

#endif
