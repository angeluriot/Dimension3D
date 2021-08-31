#ifndef DIM_WINDOW_HPP
#define DIM_WINDOW_HPP

#include "dim/utils/libraries.hpp"

namespace dim
{
	class Camera;
	class Camera2D;
	class Object;
	class Controller;
	class OrbitController;
	class FlyController;
	class DragController;

	class Window
	{
	private:

		static sf::RenderWindow*	window;
		static float				screen_coef;
		static sf::Clock			clock;
		static float				elapsed_time;
		static float				thickness;
		static bool					cull_face;
		static Controller*			controller;
		static Camera*				camera;
		static bool					unique_shader;
		static Shader				shader;
		static bool					binded;
		static Camera2D				fixed_camera2D;
		static std::vector<Light*>	lights;
		static FrameBuffer			frame_buffer;
		static Shader				post_processing_shader;
		static bool					post_processing;
		static VertexBuffer			screen;

	public:

		static const Color			background;
		static const Vector2int		initial_size;
		static bool					running;
		static Camera2D				camera2D;

		static void					open(const std::string& name, float screen_ratio, const std::string& icon_path = "");
		static void					open(const std::string& name, unsigned int width, unsigned int height, const std::string& icon_path = "");
		static void					open(const std::string& name, const Vector2int& size, const std::string& icon_path = "");
		static sf::RenderWindow&	get_window();
		static Vector2int			get_position();
		static unsigned int			get_width();
		static unsigned int			get_height();
		static Vector2int			get_size();
		static void					bind();
		static void					unbind();
		static void					set_camera(const Camera& camera);
		static Camera&				get_camera();
		static void					set_controller(const Controller& controller);
		static Controller&			get_controller();
		static void					set_shader(const Shader& shader);
		static Shader				get_shader();
		static FrameBuffer			get_frame_buffer();
		static void					set_post_processing_shader(const Shader& shader);
		static Shader				get_post_processing_shader();
		static Vector2				get_2d_world_mouse_position();
		static void					add_light(const Light& light);
		static void					clear_lights();
		static void					clear(const Color& color = background);
		static void					check_events(const sf::Event& sf_event);
		static void					update();
		static void					draw(const sf::Drawable& drawable, bool fixed = false);
		static void					draw(const Object& object, DrawType draw_type = DrawType::Default);
		static void					draw(const VertexBuffer& vertex_buffer, DrawType draw_type = DrawType::Triangles);
		static void					display();
		static void					close();
		static int					hd_to_window(int position);
		static Vector2int			hd_to_window(int x, int y);
		static Vector2int			hd_to_window(const Vector2int& position);
		static void					set_thickness(float thickness);
		static void					set_cull_face(bool enable);
		static float				get_elapsed_time();
		static bool					is_in(const Vector2& position);
		static bool					is_on_border(const Vector2& position);
	};

	sf::RenderWindow&	get_window();
	int					hd_to_window(int position);
	Vector2int			hd_to_window(int x, int y);
	Vector2int			hd_to_window(const Vector2int& position);
}

#endif
