#ifndef DIM_WINDOW_HPP
#define DIM_WINDOW_HPP

#include "dim/utils/libraries.hpp"
#include "dim/cameras/Camera2D.hpp"
#include "dim/opengl/FrameBuffer.hpp"

namespace dim
{
	class Camera;
	class Camera2D;
	class Object;
	class Controller;
	class OrbitController;
	class FlyController;
	class DragController;

	/**
	 * @brief A static class that represents the main window, it can be binded for optimization but it is not essential.
	 */



	class Window
	{
	private:

		sf::RenderWindow*    window;                // A pointer to a SFML window.
		float                screen_coef;           // The coefficient between HD and the size of the window.
		sf::Clock            clock;                 // Update elapsed_time.
		float                elapsed_time;          // The elapsed time since the last frame.
		float                thickness;             // The current OpenGL line thickness.
		bool                 cull_face;             // The current OpenGL cull face mode (true for enabled).
		Controller*          controller;            // The controller of the window.
		Camera*              camera;                // The 3D camera of the window.
		bool                 unique_shader;         // True if all objects are drawn with the same shader.
		Shader               shader;                // The shader used if unique_shader is true.
		bool                 binded;                // True if the window is currently binded.
		Camera2D             fixed_camera2D;        // The 2D camera of fixed SFML shapes.
		std::vector<Light*>	 lights;                // The lights of the window.
		FrameBuffer          frame_buffer;          // The frame buffer where Dimension3D objects are drawn.
		Shader               post_processing_shader;// The post processing shader used id post_processing is true.
		bool                 post_processing;       // True if you want to add a post processing shader to the window.
		VertexBuffer         screen;                // Screen object used to apply the post processing shader.
		Camera2D             camera2D;              // The 2D camera of the window.
		Color                background_color;

	public:
		static const Color default_background_color; 
		static const Vector2int minium_size; // The minimal size of the window (and the initial size of others like scenes of frame buffers).
		bool running = false;

		Window( 
				sf::RenderWindow*	window					= nullptr, 
				float				screen_coef				= 1.f, 
				float				elapsed_time			= 1.f / 60.f, 
				float				thickness				= 1.f, 
				const Color			background_color		= default_background_color, 
				bool				running					= false, 
				bool				cull_face				= true, 
				Controller*			controller				= nullptr, 
				Camera*				camera					= nullptr, 
				bool				unique_shader			= false, 
				bool				binded					= false, 
				std::vector<Light*>	lights					= {}, 
				bool				post_processing			= false 
			);

		/**
		 * Getters
		 */
		sf::RenderWindow& get_window();
		const sf::RenderWindow& get_window() const;
		const Color get_background_color() const;
		Vector2int get_position() const;
		unsigned int get_width() const;
		unsigned int get_height() const;
		Vector2int get_size() const;
		Camera& get_camera();
		Camera2D& get_camera2D();
		Controller& get_controller();
		const Camera& get_camera() const;
		const Camera2D& get_camera2D() const;
		const Controller& get_controller() const;
		Shader get_shader();
		FrameBuffer get_frame_buffer();
		Shader get_post_processing_shader();
		Vector2 get_2d_world_mouse_position() const;
		/**
		 * @brief Give the elapsed time since the last frame.
		 *
		 * @return the elapsed time since the last frame
		 */
		float get_elapsed_time() const;

		/**
		 * Setters
		 */
		void set_controller(const Controller& controller);
		void set_camera(const Camera& camera);
		void set_shader(const std::string& shader_name);
		void set_shader(const Shader& shader);
		void set_post_processing_shader(const std::string& shader_name);
		void set_post_processing_shader(const Shader& shader);
		static void set_thickness(float thickness);
		/**
		 * @brief Change the OpenGL cull face mode.
		 *
		 * @param enable true to enable OpenGL cull face, false otherwise
		 */
		void set_cull_face(bool enable);

		/**
		 * @brief Open the window and initialize all the libraries.
		 *
		 * @param name the name of the window
		 * @param screen_ratio the ratio to the size of the screen
		 * @param icon_path the path to an image for the icon of the window
		 */
		void open(const std::string& name, float screen_ratio, const std::string& icon_path = "");

		/**
		 * @brief Open the window and initialize all the libraries.
		 *
		 * @param name the name of the window
		 * @param width the width of the window
		 * @param height the height of the window
		 * @param icon_path the path to an image for the icon of the window
		 */
		void open(const std::string& name, unsigned int width, unsigned int height, const std::string& icon_path = "");

		/**
		 * @brief Open the window and initialize all the libraries.
		 *
		 * @param name the name of the window
		 * @param size the size of the window
		 * @param icon_path the path to an image for the icon of the window
		 */
		void open(const std::string& name, const Vector2int& size, const std::string& icon_path = "");

		void bind();
		void unbind();
		
		/**
		 * @brief Add a light to the window.
		 *
		 * @param light the light to add
		 */
		void add_light(const Light& light);

		/**
		 * @brief Remove all lights.
		 */
		void clear_lights();
		/**
		 * @brief Clear the rendered image.
		 *
		 * @param color the new background color
		 */
		void clear(const Color& color = default_background_color);

		/**
		 * @brief But the current SFML events in the sf_event parameter.
		 *
		 * @param sf_event collect the SFML events
		 * @return false when all the events are collected, true otherwise
		 */
		bool poll_event(sf::Event& sf_event);

		/**
		 * @brief Check and handle mouse and resize events.
		 *
		 * @param sf_event the SFML event
		 */
		void check_events(const sf::Event& sf_event);

		/**
		 * @brief Update the window based of the user actions.
		 */
		void update();

		/**
		 * @brief Draw an SFML shape on the window.
		 *
		 * @param drawable the SFML shape to draw
		 * @param fixed true if the shape should not be affected by the 2D camera
		 */
		void draw(const sf::Drawable& drawable, bool fixed = false);

		/**
		 * @brief Draw a Dimension3D object on the window.
		 *
		 * @param object the Dimension3D object to draw
		 * @param draw_type the way to draw it
		 */
		void draw(const Object& object, DrawType draw_type = DrawType::Default);

		/**
		 * @brief Draw a vertex buffer on the window.
		 *
		 * @param vertex_buffer the vertex buffer to draw
		 * @param draw_type the way to draw it
		 */
		void draw(const VertexBuffer& vertex_buffer, DrawType draw_type = DrawType::Triangles);

		/**
		 * @brief Draw the scene on the main window.
		 */
		void display();

		/**
		 * @brief Close the window and shut down all the libraries.
		 */
		void close();

		/**
		 * @brief Convert an HD position into the window position.
		 *
		 * @param position the input HD position
		 * @return the output window position
		 */
		int hd_to_window(int position) const;

		/**
		 * @brief Convert an HD position into the window position.
		 *
		 * @param x the input HD X position
		 * @param y the input HD Y position
		 * @return the output window position
		 */
		Vector2int hd_to_window(int x, int y) const;

		/**
		 * @brief Convert an HD position into the window position.
		 *
		 * @param position the input HD position
		 * @return the output window position
		 */
		Vector2int hd_to_window(const Vector2int& position) const;

		/**
		 * @brief Tell if the position is in the window.
		 *
		 * @param position the position to test
		 * @return true if the position is in the window, false otherwise
		 */
		bool is_in(const Vector2& position) const;

		/**
		 * @brief Tell if the position is on the border of the window.
		 *
		 * @param position the position to test
		 * @return true if the position is on the border of the window, false otherwise
		 */
		bool is_on_border(const Vector2& position) const;
	};

	/**
	 * @brief Convert an HD position into the window position.
	 *
	 * @param position the input HD position
	 * @return the output window position
	 */
	int hd_to_window(int position);

	/**
	 * @brief Convert an HD position into the window position.
	 *
	 * @param x the input HD X position
	 * @param y the input HD Y position
	 * @return the output window position
	 */
	Vector2int hd_to_window(int x, int y);

	/**
	 * @brief Convert an HD position into the window position.
	 *
	 * @param position the input HD position
	 * @return the output window position
	 */
	Vector2int hd_to_window(const Vector2int& position);
}

#endif
