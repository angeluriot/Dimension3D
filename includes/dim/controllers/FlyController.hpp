#ifndef DIM_FLYCONTROLLER_HPP
#define DIM_FLYCONTROLLER_HPP

#include "dim/controllers/Controller.hpp"

namespace dim
{
	class FlyController : public Controller
	{
	private:

		bool								moving;
		sf::Keyboard::Key					forward;
		sf::Keyboard::Key					left;
		sf::Keyboard::Key					right;
		sf::Keyboard::Key					backward;
		sf::Keyboard::Key					up;
		sf::Keyboard::Key					down;

		static constexpr float				default_sensitivity	= 0.2f;
		static constexpr float				default_speed		= 2.f;
		static constexpr sf::Keyboard::Key	default_forward		= sf::Keyboard::Key::Z;
		static constexpr sf::Keyboard::Key	default_left		= sf::Keyboard::Key::Q;
		static constexpr sf::Keyboard::Key	default_right		= sf::Keyboard::Key::D;
		static constexpr sf::Keyboard::Key	default_backward	= sf::Keyboard::Key::S;
		static constexpr sf::Keyboard::Key	default_up			= sf::Keyboard::Key::Space;
		static constexpr sf::Keyboard::Key	default_down		= sf::Keyboard::Key::LControl;

		Controller*							clone() const override;
		void								move(Camera& camera) const;
		void								look(Scene& scene, Camera& camera) const;
		void								look(Camera& camera) const;

	public:

											FlyController(float sensitivity = default_sensitivity, float speed = default_speed);
											FlyController(const FlyController& other) = default;

		FlyController&						operator=(const FlyController& other) = default;

		Type								get_type() const override;
		void								check_events(const sf::Event& sf_event, Scene& scene, Camera& camera) override;
		void								check_events(const sf::Event& sf_event, Camera& camera) override;
		void								update(Scene& scene, Camera& camera) override;
		void								update(Camera& camera) override;
		void								set_controls(sf::Keyboard::Key forward, sf::Keyboard::Key left, sf::Keyboard::Key right, sf::Keyboard::Key backward, sf::Keyboard::Key up, sf::Keyboard::Key down);
	};
}

#endif
