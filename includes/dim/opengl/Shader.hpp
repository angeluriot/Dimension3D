#ifndef DIM_SHADER_HPP
#define DIM_SHADER_HPP

#include "dim/utils/libraries.hpp"
#include "dim/vectors/Vector2.hpp"
#include "dim/vectors/Vector3.hpp"
#include "dim/vectors/Vector4.hpp"
#include "dim/opengl/Texture.hpp"

namespace dim
{
	class Mesh;
	class VertexBuffer;
	class Light;
	class Material;
	class Color;
	void init();

	class Shader
	{
	private:

		std::shared_ptr<sf::Shader>				shader;

		static std::map<std::string, Shader>	shaders;
		static constexpr unsigned int			max_lights = 10;

		static void								init();

	public:

		static Shader							default_shader;

												Shader();
												Shader(const Shader& other) = default;
												Shader(const std::string& vert_path, const std::string& frag_path);

		Shader&									operator=(const Shader& other) = default;

		void									load(const std::string& vert_path, const std::string& frag_path);
		GLuint									get_id() const;
		void									bind() const;
		static void								unbind();

		void									send_uniform(const std::string& name, const Texture& texture) const;
		void									send_uniform(const std::string& name, const Light& light) const;
		void									send_uniform(const std::string& name, const std::vector<Light*>& lights) const;
		void									send_uniform(const std::string& name, const Material& material) const;

		void									send_uniform(const std::string& name, float number) const;
		void									send_uniform(const std::string& name, int number) const;

		void									send_uniform(const std::string& name, const std::vector<float>& numbers, unsigned int group = 1) const;
		void									send_uniform(const std::string& name, const std::vector<int>& numbers, unsigned int group = 1) const;

		void									send_uniform(const std::string& name, const Vector2& vector) const;
		void									send_uniform(const std::string& name, const Vector3& vector) const;
		void									send_uniform(const std::string& name, const Vector4& vector) const;
		void									send_uniform(const std::string& name, const Color& color) const;

		void									send_uniform(const std::string& name, const std::vector<Vector2>& vectors) const;
		void									send_uniform(const std::string& name, const std::vector<Vector3>& vectors) const;
		void									send_uniform(const std::string& name, const std::vector<Vector4>& vectors) const;
		void									send_uniform(const std::string& name, const std::vector<Color>& colors) const;

		void									send_uniform(const std::string& name, const glm::mat2& matrix) const;
		void									send_uniform(const std::string& name, const glm::mat3& matrix) const;
		void									send_uniform(const std::string& name, const glm::mat4& matrix) const;

		static void								add(const std::string& name, const Shader& shader);
		static void								add(const std::string& name, const std::string& vert_path, const std::string& frag_path);
		static void								remove(const std::string& name);
		static Shader							get(const std::string& name);

		friend void								init();
	};
}

#endif
