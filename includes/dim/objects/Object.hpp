#ifndef DIM_OBJECT_HPP
#define DIM_OBJECT_HPP

#include "dim/utils/libraries.hpp"
#include "dim/vectors/Vector3.hpp"
#include "dim/opengl/VertexBuffer.hpp"
#include "dim/objects/Material.hpp"
#include "dim/lights/Light.hpp"
#include "dim/opengl/Shader.hpp"
#include "dim/cameras/Camera.hpp"
#include "dim/windows/Scene.hpp"

namespace dim
{
	class Scene;
	class Window;
	class Shader;

	class Object
	{
	private:

		Shader			shader;
		VertexBuffer	vertex_buffer;
		Texture			texture;
		glm::mat4		scaling_matrix;
		glm::mat4		rotation_matrix;
		glm::mat4		translation_matrix;
		glm::mat4		origin_matrix;
		glm::mat4		model;
		float			thickness;
		bool			textured;
		mutable bool	binded;

		void			draw(Camera* camera, const std::vector<Light*>& lights, DrawType draw_type, bool scene_shader) const;

	public:

		Mesh			mesh;
		Material		material;

						Object();
						Object(const Object& other);
						Object(const Mesh& mesh, const Material& material = Material(Color::white, 0.1f, 0.5f, 0.4f, 50.f));

		Object&			operator=(const Object& other);

		void			create(const Mesh& mesh, const Material& material = Material(Color::white, 0.1f, 0.5f, 0.4f, 50.f));
		void			set_shader(const std::string& shader_name);
		void			set_shader(const Shader& shader);
		void			set_texture(const std::string& texture_name);
		void			set_texture(const Texture& texture);
		void			set_mesh(const Mesh& mesh, dim::DataType data_sent = dim::DataType::All);
		void			update_mesh(dim::DataType data_sent = dim::DataType::All);

		void			set_size(float x, float y, float z);
		void			set_size(const Vector3& size);
		void			set_rotation(float angle, const Vector3& axis);
		void			set_position(float x, float y, float z);
		void			set_position(const Vector3& position);
		void			set_origin(float x, float y, float z);
		void			set_origin(const Vector3& origin);
		void			set_thickness(float thickness);

		void			scale(float x, float y, float z);
		void			scale(const Vector3& scale);
		void			rotate(float angle, const Vector3& axis);
		void			move(float x, float y, float z);
		void			move(const Vector3& movement);

		Vector3			get_size() const;
		glm::mat4		get_rotation() const;
		Vector3			get_position() const;
		Vector3			get_origin() const;
		float			get_thickness() const;

		void			bind() const;
		void			unbind() const;

		friend			Scene;
		friend			Window;
	};
}

#endif
