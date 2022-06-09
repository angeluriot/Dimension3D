#include "dim/dimension3D.hpp"

namespace dim
{
	OrbitController::OrbitController(Window& parent_window, float sensitivity, float speed, const Vector3& center) : 
			Controller(parent_window, sensitivity, speed, true, true ), 
			center(center), 
			prev_mouse_pos(sf::Mouse::getPosition()), 
			prev_mouse_click(false), 
			rotation_forbidden(false), 
			center_changed(true)

	{
		prev_center = Vector3::null;
		//this->center = center;
		//center_changed = true;
		//this->sensitivity = std::max(sensitivity, 0.f);
		//this->speed = std::max(speed, 0.f);
		//look_active = true;
		move_active = true;
		//prev_mouse_pos = sf::Mouse::getPosition();
		//prev_mouse_click = false;
		//rotation_forbidden = false;
	}

	Controller* OrbitController::clone() const
	{
		return new OrbitController(*this);
	}

	Controller::Type OrbitController::get_type() const
	{
		return Type::Orbit;
	}

	void OrbitController::check_events(const sf::Event& sf_event, Camera& camera, bool in_bounds )
	{
		if (center_changed)
		{
			camera.position += center - prev_center;
			camera.view = glm::lookAt(
						camera.position.to_glm(), 
						(camera.position + normalize(center - camera.position)).to_glm(), 
						glm::vec3(0.f, 1.f, 0.f) 
					);
			center_changed = false;
		}

		if (move_active 
					&& sf_event.type == sf::Event::MouseWheelMoved 
					&& in_bounds == true 
				)
		{
			camera.position -= center;
			camera.position.set_norm(std::max(camera.position.get_norm() - static_cast<float>(sf_event.mouseWheel.delta) * speed, 0.01f));
			camera.position += center;

			if (camera.get_type() == Camera::Type::Orthographic)
				static_cast<OrthographicCamera&>(camera).zoom(1.f + static_cast<float>(sf_event.mouseWheel.delta) * speed * 0.5f);

			camera.view = glm::lookAt(
						camera.position.to_glm(), 
						(camera.position + normalize(center - camera.position)).to_glm(), 
						glm::vec3(0.f, 1.f, 0.f)
					);
		}
	}

	void OrbitController::check_events(const sf::Event& sf_event, Scene& scene, Camera& camera) {
			check_events(sf_event, camera, scene.is_in(sf::Mouse::getPosition(parent_window.get_window())));
	}

	void OrbitController::check_events(const sf::Event& sf_event, Camera& camera) {
			check_events(sf_event, camera, parent_window.is_in(sf::Mouse::getPosition(parent_window.get_window())));
	}

	void OrbitController::update_internal(Camera& camera)
	{
		if (center_changed)
		{
			camera.position += center - prev_center;
			camera.view = glm::lookAt(
						camera.position.to_glm(), 
						(camera.position + normalize(center - camera.position)).to_glm(), 
						glm::vec3(0.f, 1.f, 0.f)
					);
			center_changed = false;
		}
		auto pressed = sf::Mouse::isButtonPressed(sf::Mouse::Button::Left);
		//std::cout << "rotation_forbidden " << rotation_forbidden << "\nlook_active: " << look_active << "\npressed: " << pressed << "\n";
		if (look_active && !rotation_forbidden && pressed )
		{
			Vector2 move = Vector2(sf::Mouse::getPosition()) - prev_mouse_pos;
			//std::cout << "move: " << move << "\n";

			camera.position -= center;
			std::cout << center - camera.position << "\n";
			camera.position.set_theta(camera.position.get_theta() - move.x * sensitivity);
			camera.position.set_phi(std::min(std::max(camera.position.get_phi() - move.y * sensitivity, 0.01f), pi - 0.01f));
			camera.position += center;

			camera.view = glm::lookAt(
						camera.position.to_glm(), 
						(camera.position + normalize(center - camera.position)).to_glm(), 
						glm::vec3(0.f, 1.f, 0.f)
					);
		}

		prev_mouse_pos = sf::Mouse::getPosition();
		prev_mouse_click = sf::Mouse::isButtonPressed(sf::Mouse::Button::Left);
	}

	void OrbitController::update(Scene& scene, Camera& camera)
	{
		bool prev_mouse_click_status = !prev_mouse_click && sf::Mouse::isButtonPressed(sf::Mouse::Button::Left); 
		auto mouse_position = sf::Mouse::getPosition(parent_window.get_window());

		bool rotation_forbidden_condition = (
					(prev_mouse_click_status && ( !scene.is_in(mouse_position) || !scene.is_active() )) == true
					|| scene.is_moving() == true 
					|| !scene.is_active() == true 
				) 
					? true 
					: (!scene.is_moving() 
								&& !prev_mouse_click_status 
								&& scene.is_active() 
								&& scene.is_in(mouse_position))
							? false 
							: rotation_forbidden;
		update_internal(camera);
	}

	void OrbitController::update(Camera& camera)
	{
		bool prev_mouse_click_status = !prev_mouse_click && sf::Mouse::isButtonPressed(sf::Mouse::Button::Left); 
		auto mouse_position = sf::Mouse::getPosition(parent_window.get_window());

		rotation_forbidden = ( prev_mouse_click_status && !parent_window.is_in(mouse_position) )
					? true 
					: ( ( !prev_mouse_click_status ) ? false : true ); 
		update_internal(camera);
	}

	void OrbitController::set_center(float x, float y, float z)
	{
		set_center(Vector3(x, y, z));
	}

	void OrbitController::set_center(const Vector3& center)
	{
		prev_center = this->center;
		this->center  = center;
		center_changed = true;
	}

	Vector3 OrbitController::get_center() const
	{
		return center;
	}
}
