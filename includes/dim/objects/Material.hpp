#ifndef DIM_MATERIAL_HPP
#define DIM_MATERIAL_HPP

#include "dim/utils/libraries.hpp"
#include "dim/utils/Color.hpp"

namespace dim
{
	class Material
	{
	private:

		Color		color;
		float		ambient;
		float		diffuse;
		float		specular;
		float		shininess;
		bool		illuminated;

	public:

					Material(const Material& other) = default;
					Material(const Color& color = Color(0.f, 0.f, 0.f, 0.f));
					Material(const Color& color, float ambient, float diffuse, float specular, float shininess);

		Material&	operator=(const Material& other) = default;

		Color		get_color() const;
		void		set_color(const Color& color);
		float		get_ambient() const;
		void		set_ambient(float ambient);
		float		get_diffuse() const;
		void		set_diffuse(float diffuse);
		float		get_specular() const;
		void		set_specular(float specular);
		float		get_shininess() const;
		void		set_shininess(float shininess);
		bool		is_illuminated() const;
		void		set_illuminated(bool illuminated);
	};
}

#endif
