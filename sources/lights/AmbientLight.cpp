#include "dim/dimension3D.hpp"

namespace dim
{
	Light* AmbientLight::clone() const
	{
		return new AmbientLight(*this);
	}

	AmbientLight::AmbientLight(const Color& color, float intensity)
	{
		set_color(color);
		set_intensity(intensity);
	}

	Light::Type AmbientLight::get_type() const
	{
		return Type::Ambient;
	}
}
