#ifndef DIM_CONTROLLER_HPP
#define DIM_CONTROLLER_HPP

#include "dim/utils/libraries.hpp"

namespace dim
{
	class Scene;
	class Camera;
	class Window;

	class Controller
	{
	protected:

		float			sensitivity;
		float			speed;
		bool			active;

		virtual			Controller* clone() const = 0;

	public:

		enum class Type { Orbit, Fly, Drag };

						Controller();
						Controller(const Controller& other) = default;

		Controller&		operator=(const Controller& other) = default;

		virtual Type	get_type() const = 0;
		float			get_sensitivity() const;
		void			set_sensitivity(float sensitivity);
		float			get_speed() const;
		void			set_speed(float speed);
		virtual void	check_events(const sf::Event& sf_event, Scene& scene, Camera& camera) = 0;
		virtual void	check_events(const sf::Event& sf_event, Camera& camera) = 0;
		virtual void	update(Scene& scene, Camera& camera) = 0;
		virtual void	update(Camera& camera) = 0;
		void			enable(bool enable);

		friend			Scene;
		friend			Window;
	};
}

#endif
