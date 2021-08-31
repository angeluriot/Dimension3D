#ifndef DIM_AMBIENTLIGHT_HPP
#define DIM_AMBIENTLIGHT_HPP

#include "dim/lights/Light.hpp"

namespace dim
{
	class AmbientLight : public Light
	{
	private:

		Light*			clone() const override;

	public:

						AmbientLight(const AmbientLight& other) = default;
						AmbientLight(const Color& color = Color::white, float intensity = 1.f);

		AmbientLight&	operator=(const AmbientLight& other) = default;

		Type			get_type() const override;
	};
}

#endif
