#ifndef DIM_CAMERA2D_HPP
#define DIM_CAMERA2D_HPP

#include "dim/utils/libraries.hpp"

namespace dim
{
	class Camera2D
	{
	private:

		sf::View	view;
		float		zoom_level;
		Vector2		size;

	public:

					Camera2D();
					Camera2D(const Camera2D& other) = default;

		Camera2D&	operator=(const Camera2D& other) = default;

		void		set_zoom(float zoom);
		void		set_rotation(float angle);
		void		set_position(const Vector2& position);
		void		set_position(float x, float y);

		void		zoom(float zoom);
		void		rotate(float angle);
		void		move(const Vector2& move);
		void		move(float x, float y);

		void		set_resolution(unsigned int width, unsigned int height);
		void		set_resolution(const Vector2int& resolution);
		sf::View&	get_view();
		float		get_zoom() const;
		Vector2		get_resolution() const;
	};
}

#endif
