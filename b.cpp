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

		if ((!prev_mouse_click && sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) 
					&& (!scene.is_in(sf::Mouse::getPosition(parent_window.get_window())) ||
			!scene.is_active())) || scene.is_moving())
			rotation_forbidden = true;

		else if (!scene.is_moving() && prev_mouse_click && !sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
			rotation_forbidden = false;

		if (!scene.is_moving() && scene.is_active() && scene.is_in(sf::Mouse::getPosition(parent_window.get_window())))
			rotation_forbidden = false;

		if (!scene.is_active())
			rotation_forbidden = true;

		if (look_active && !rotation_forbidden && sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
		{
			Vector2 move = Vector2(sf::Mouse::getPosition()) - prev_mouse_pos;

			camera.position -= center;
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
