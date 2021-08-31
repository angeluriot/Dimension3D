#ifndef DIM_ORBITCONTROLLER_HPP
#define DIM_ORBITCONTROLLER_HPP

#include "dim/controllers/Controller.hpp"

namespace dim
{
	class OrbitController : public Controller
	{
	private:

		Vector3					prev_center;
		Vector3					center;
		Vector2					prev_mouse_pos;
		bool					prev_mouse_click;
		bool					rotation_forbidden;
		bool					center_changed;

		static constexpr float	default_sensitivity	= 0.005f;
		static constexpr float	default_speed		= 0.2f;

		Controller*				clone() const override;

	public:

								OrbitController(const Vector3& center = Vector3(0.f, 0.f, 0.f), float sensitivity = default_sensitivity, float speed = default_speed);
								OrbitController(const OrbitController& other) = default;

		OrbitController&		operator=(const OrbitController& other) = default;

		Type					get_type() const override;
		void					check_events(const sf::Event& sf_event, Scene& scene, Camera& camera) override;
		void					check_events(const sf::Event& sf_event, Camera& camera) override;
		void					update(Scene& scene, Camera& camera) override;
		void					update(Camera& camera) override;
		void					set_center(float x, float y, float z);
		void					set_center(const Vector3& center);
		Vector3					get_center() const;
	};
}

#endif
