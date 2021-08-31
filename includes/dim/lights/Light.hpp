#ifndef DIM_LIGHT_HPP
#define DIM_LIGHT_HPP

#include "dim/utils/libraries.hpp"
#include "dim/vectors/Vector3.hpp"
#include "dim/lights/Light.hpp"
#include "dim/utils/Color.hpp"

namespace dim
{
	class Shader;
	class Scene;
	class Window;

	class Light
	{
	protected:

		Vector3			vector;
		Color			color;
		float			intensity;

		virtual Light*	clone() const = 0;

	public:

		enum class Type { Ambient = 0, Directional = 1, Point = 2 };

						Light();
						Light(const Light& other) = default;

		Light&			operator=(const Light& other) = default;

		virtual Type	get_type() const = 0;
		Color			get_color() const;
		void			set_color(const Color& color);
		float			get_intensity() const;
		void			set_intensity(float intensity);

		friend			Shader;
		friend			Scene;
		friend			Window;
	};
}

#endif
