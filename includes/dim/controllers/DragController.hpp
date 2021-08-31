#ifndef DIM_DRAGCONTROLLER_HPP
#define DIM_DRAGCONTROLLER_HPP

#include "dim/controllers/Controller.hpp"

namespace dim
{
	class DragController : public Controller
	{
	private:

		Vector2					prev_mouse_pos;
		bool					prev_mouse_click;
		bool					move_forbidden;

		Controller*				clone() const override;

	public:

		static constexpr float	default_sensitivity	= 1.f;
		static constexpr float	default_speed		= 0.2f;

								DragController(float sensitivity = default_sensitivity, float speed = default_speed);
								DragController(const DragController& other) = default;

		DragController&			operator=(const DragController& other) = default;

		Type					get_type() const override;
		void					check_events(const sf::Event& sf_event, Scene& scene, Camera& camera) override;
		void					check_events(const sf::Event& sf_event, Camera& camera) override;
		void					update(Scene& scene, Camera& camera) override;
		void					update(Camera& camera) override;
	};
}

#endif
