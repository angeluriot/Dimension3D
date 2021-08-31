#ifndef DIM_VERTEXBUFFER_HPP
#define DIM_VERTEXBUFFER_HPP

#include "dim/utils/libraries.hpp"
#include "dim/opengl/Shader.hpp"
#include "dim/vectors/Vector2.hpp"
#include "dim/vectors/Vector3.hpp"
#include "dim/vectors/Vector4.hpp"
#include "dim/opengl/Texture.hpp"

namespace dim
{
	class Texture;
	class Mesh;

	enum class DataType : uint8_t { Positions = 1, Normals = 2, TexCoords = 4, All = 7 };

	enum class DrawType { Default = 15, Points = GL_POINTS, Lines = GL_LINES, Triangles = GL_TRIANGLES };

	class VertexBuffer
	{
	private:

		Shader							shader;
		std::shared_ptr<GLuint>			vbo;
		std::shared_ptr<GLuint>			vao;
		std::shared_ptr<unsigned int>	nb_vertices;

	public:

										VertexBuffer();
										VertexBuffer(const VertexBuffer& other) = default;
										VertexBuffer(const std::string& shader_name);
										VertexBuffer(const Shader& shader);
										VertexBuffer(const std::string& shader_name, const Mesh& mesh, DataType data_sent = DataType::All);
										VertexBuffer(const Shader& shader, const Mesh& mesh, DataType data_sent = DataType::All);
										~VertexBuffer();

		VertexBuffer&					operator=(const VertexBuffer& other) = default;

		void							set_shader(const std::string& shader_name);
		void							set_shader(const Shader& shader);
		void							send_data(const std::string& shader_name, const Mesh& mesh, DataType data_sent = DataType::All);
		void							send_data(const Shader& shader, const Mesh& mesh, DataType data_sent = DataType::All);
		void							send_data(const Mesh& mesh, DataType data_sent = DataType::All);
		Shader							get_shader() const;
		unsigned int					get_nb_vertices() const;

		void							bind() const;
		static void						unbind();
		void							draw(DrawType draw_type = DrawType::Triangles) const;
	};

	DataType operator&(DataType type_1, DataType type_2);
	DataType operator|(DataType type_1, DataType type_2);
	DataType operator^(DataType type_1, DataType type_2);
	DataType operator~(DataType type);
}

#endif
