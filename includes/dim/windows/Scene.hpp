#ifndef DIM_SCENE_HPP
#define DIM_SCENE_HPP

#include "dim/utils/libraries.hpp"
#include "dim/utils/utils.hpp"
#include "dim/opengl/FrameBuffer.hpp"
#include "dim/cameras/Camera2D.hpp"

namespace dim
{
	void shut_down();
	class Camera;
	class Object;
	class Controller;
	class OrbitController;
	class FlyController;
	class DragController;

	class Scene
	{
	private:

		std::string								name;
		FrameBuffer								frame_buffer;
		sf::RenderTexture						render_texture;
		Controller*								controller;
		Camera*									camera;
		Vector2int								size;
		Vector2int								min;
		Vector2int								max;
		bool									active;
		bool									moving;
		bool									resized;
		unsigned int							frame_id;
		bool									unique_shader;
		Shader									shader;
		mutable bool							binded;
		Camera2D								fixed_camera2D;
		std::vector<Light*>						lights;
		Shader									post_processing_shader;
		bool									post_processing;
		VertexBuffer							screen;
		sf::RenderTexture						clear_texture;
		bool									to_delete;

		static std::map<std::string, Scene*>	scenes;

	public:

		Camera2D								camera2D;

												Scene();
												Scene(const Scene& other);
												Scene(const std::string& name);
												~Scene();

		Scene&									operator=(const Scene& other);

		void									create(const std::string& name);
		void									check_events(const sf::Event& sf_event);
		void									update();
		void									bind() const;
		void									unbind() const;
		std::string								get_name() const;
		void									set_name(const std::string& name);
		void									set_camera(const Camera& camera);
		Camera&									get_camera();
		void									set_controller(const Controller& controller);
		Controller&								get_controller();
		unsigned int							get_width() const;
		unsigned int							get_height() const;
		Vector2int								get_size() const;
		Vector2int								get_center() const;
		FrameBuffer								get_frame_buffer() const;
		const sf::RenderTexture&				get_render_texture() const;
		bool									is_active() const;
		bool									is_moving() const;
		bool									is_resized() const;
		void									set_shader(const Shader& shader);
		Shader									get_shader() const;
		void									set_post_processing_shader(const Shader& shader);
		Shader									get_post_processing_shader() const;
		bool									is_in(const Vector2& position) const;
		Vector2									get_2d_world_mouse_position();
		void									add_light(const Light& light);
		void									clear_lights();
		void									clear(const Color& color = Color::transparent);
		void									draw(const sf::Drawable& drawable, bool fixed = false);
		void									draw(const Object& object, DrawType draw_type = DrawType::Default);
		void									draw(const VertexBuffer& vertex_buffer, DrawType draw_type = DrawType::Triangles);
		void									display();

		static void								add(Scene& scene);
		static void								add(const std::string& name);
		static void								remove(const std::string& name);
		static Scene&							get(const std::string& name);
		static void								check_all_events(const sf::Event& sf_event);
		static void								update_all();
		static void								clear_all();
		static void								display_all();

		friend									Controller;
		friend									OrbitController;
		friend									FlyController;
		friend									DragController;
		friend void								shut_down();
	};
}

#endif
