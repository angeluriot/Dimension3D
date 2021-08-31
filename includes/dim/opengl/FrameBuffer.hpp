#ifndef DIM_FRAMEBUFFER_HPP
#define DIM_FRAMEBUFFER_HPP

#include "dim/utils/libraries.hpp"
#include "dim/opengl/Texture.hpp"
#include "dim/utils/Color.hpp"
#include "dim/vectors/Vector2int.hpp"

namespace dim
{
	class FrameBuffer
	{
	private:

		std::shared_ptr<GLuint>						fbo;
		std::shared_ptr<GLuint>						rbo;
		Texture										texture;
		std::shared_ptr<unsigned int>				width;
		std::shared_ptr<unsigned int>				height;

		static std::map<std::string, FrameBuffer>	frame_buffers;

	public:

													FrameBuffer();
													FrameBuffer(const FrameBuffer& other) = default;
													FrameBuffer(unsigned int width, unsigned int height);
													FrameBuffer(const Vector2int& size);
													~FrameBuffer();

		FrameBuffer&								operator=(const FrameBuffer& other) = default;

		void										create(unsigned int width, unsigned int height);
		void										create(const Vector2int& size);
		void										bind() const;
		static void									unbind();
		GLuint										get_id() const;
		Texture										get_texture() const;
		void										set_size(unsigned int width, unsigned int height);
		void										set_size(const Vector2int& size);
		void										set_width(unsigned int width);
		void										set_height(unsigned int height);
		Vector2int									get_size() const;
		unsigned int								get_width() const;
		unsigned int								get_height() const;
		void										clear(const Color& color = Color::transparent) const;

		static void									add(const std::string& name, const FrameBuffer& frame_buffer);
		static void									add(const std::string& name, unsigned int width, unsigned int height);
		static void									remove(const std::string& name);
		static FrameBuffer							get(const std::string& name);
	};
}

#endif
