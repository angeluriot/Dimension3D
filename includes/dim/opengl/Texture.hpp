#ifndef DIM_TEXTURE_HPP
#define DIM_TEXTURE_HPP

#include "dim/utils/libraries.hpp"

namespace dim
{
	class FrameBuffer;

	class Texture
	{
	public:

		enum class Warpping { Repeat = GL_REPEAT, MirroredRepeat = GL_MIRRORED_REPEAT, ClampToEdge = GL_CLAMP_TO_EDGE, ClampToBorder = GL_CLAMP_TO_BORDER };
		enum class Filtering { Nearest = GL_NEAREST, Linear = GL_LINEAR };

	private:

		std::shared_ptr<GLuint>					id;
		mutable std::shared_ptr<unsigned int>	unit;

		static std::map<std::string, Texture>	textures;
		static int								max_unit;

	public:

												Texture();
												Texture(const Texture& other) = default;
												Texture(const std::string& path, Filtering filtering = Filtering::Linear, Warpping warpping = Warpping::Repeat);
												~Texture();

		Texture&								operator=(const Texture& other) = default;

		void									load(const std::string& path, Filtering filtering = Filtering::Linear, Warpping warpping = Warpping::Repeat);
		GLuint									get_id() const;
		unsigned int							get_unit() const;
		void									bind() const;
		void									unbind() const;

		static void								add(const std::string& name, const Texture& texture);
		static void								add(const std::string& name, const std::string& path, Filtering filtering = Filtering::Linear, Warpping warpping = Warpping::Repeat);
		static void								remove(const std::string& name);
		static Texture							get(const std::string& name);

		friend									FrameBuffer;
	};
}

#endif
