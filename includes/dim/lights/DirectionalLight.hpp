#ifndef DIM_DIRECTIONALLIGHT_HPP
#define DIM_DIRECTIONALLIGHT_HPP

#include "dim/lights/Light.hpp"

namespace dim
{
	class DirectionalLight : public Light
	{
	private:

		Light*				clone() const override;

	public:

							DirectionalLight(const DirectionalLight& other) = default;
							DirectionalLight(const Vector3& direction = Vector3(0.f, -1.f, 0.f), const Color& color = Color::white, float intensity = 1.f);

		DirectionalLight&	operator=(const DirectionalLight& other) = default;

		void				set_direction(float x, float y, float z);
		void				set_direction(const Vector3& direction);
		Vector3				get_direction() const;
		Type				get_type() const override;
	};
}

#endif
