#include "dim/dimension3D.hpp"

namespace dim
{
	Controller::Controller( Window& parent_window, float sensitivity, float speed, bool look_active, bool move_active ) : 
			parent_window( parent_window ), 
			sensitivity( sensitivity ), 
			speed( speed ), 
			look_active( look_active ), 
			move_active( move_active ) 
		{}

	float Controller::get_sensitivity() const
	{
		return sensitivity;
	}

	void Controller::set_sensitivity(float sensitivity)
	{
		if (sensitivity > 0.f)
			this->sensitivity = sensitivity;
	}

	float Controller::get_speed() const
	{
		return speed;
	}

	void Controller::set_speed(float speed)
	{
		if (speed > 0.f)
			this->speed = speed;
	}

	void Controller::enable(bool enable, Action action)
	{
		if (action == Action::Look || action == Action::All)
			look_active = enable;

		if (action == Action::Move || action == Action::All)
			move_active = enable;
	}
}
