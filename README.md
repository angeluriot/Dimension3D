# Dimension3D

![Release](https://img.shields.io/badge/Release-v1.0-blueviolet)
![Language](https://img.shields.io/badge/Language-C%2B%2B-0052cf)
![Size](https://img.shields.io/badge/Size-234Ko-f12222)
![Open Source](https://badges.frapsoft.com/os/v2/open-source.svg?v=103)

<br/>

This repository contains the source code of a simple graphics library (2D, 3D and windows). It looks like **[SFML](https://www.sfml-dev.org/)** for 3D or **[ThreeJS](https://threejs.org/)** for C++.

<br/>

<p align="center">
	<img src="https://i.imgur.com/qzPqvit.png" width="700">
</p>

# Summary

* **[Summary](#summary)**
* **[Features](#features)**
	* [Windows](#windows-)
	* [2D](#2d-)
	* [3D](#3d-)
	* [Simplified OpenGL objects](#simplified-opengl-objects-)
	* [Utils](#utils-)
* **[Install](#install)**
	* [Dependecies](#dependecies)
		* [Compilers](#compilers-)
		* [Libraries](#libraries-)
	* [Integrating into your project](#integrating-into-your-project-not-recommended) *(not recommended)*
	* [Using the skeleton project](#using-the-skeleton-project-recommended) *(recommended)*
* **[Demo](#demo)**
	* [Code example](#code-example)
	* [Release](#release)
* **[Wiki](#wiki)**
* **[Notes](#notes)**
* **[Credits](#credits)**

# Features

### Windows :

* Interactive windows with buttons, sliders... *(see **[ImGui](https://github.com/ocornut/imgui)** for more information)*.

* Scene windows for display.

### 2D :

* Rectangles, circles, custom shapes, images... *(see **[SFML](https://www.sfml-dev.org/)** for more information)* on a scene or the main window.

* A drag controller to move the view with the mouse.

### 3D :

* Cubes, spheres, cylinders, cones, custom meshes...

* Phong materials, Textures...

* Ambient, directional and point lights.

* Perspective and orthographic cameras.

* Drag, fly and orbit controllers.

### Simplified OpenGL objects :

* Shaders, framebuffers, vertexbuffers, textures...

### Utils :

* Colors, vectors, small functions...

# Install

### Dependecies

* #### Compilers :
	* **[CMake](https://cmake.org/)**.
	* **[GCC](https://gcc.gnu.org/)** for **Linux**.
	* **[Clang](https://clang.llvm.org/)** for **MacOS**.
	* **[Visual Studio](https://visualstudio.microsoft.com/)** (the software or the compiler only) for **Windows**. *(recommended)*
	* **[MinGW](https://www.mingw-w64.org/)** for **Windows**. *(not recommended)*

* #### Libraries :
	* **[GLM](http://glm.g-truc.net/0.9.6/api/index.html)**.
	* **[GLEW](http://glew.sourceforge.net/)**.
	* **[SFML](https://www.sfml-dev.org/)**.
	* **[ImGui](https://github.com/ocornut/imgui)**.
	* **[ImGui-SFML](https://github.com/eliasdaler/imgui-sfml)**.

### Integrating into your project *(not recommended)*

Link all the **[dependecies](#dependecies)** to your project and compile the **Dimension3D library** as if it was part of your project.

### Using the skeleton project *(recommended)*

Download the **[skeleton project](https://github.com/angeluriot/Graphics_skeleton)**, delete the **[main.cpp](https://github.com/angeluriot/Graphics_skeleton/blob/master/sources/main.cpp)** demo and put your project files in the **[sources folder](https://github.com/angeluriot/Graphics_skeleton/tree/master/sources)**.

Then run the correct launch file :

* **[unix_launch.sh](https://github.com/angeluriot/Graphics_skeleton/blob/master/unix_launch.sh)** to create and compile the project with **GCC 64** on **Linux** or **Clang 64** on **MacOS**. *(recommended)*

* **[vs32_launch.bat](https://github.com/angeluriot/Graphics_skeleton/blob/master/vs32_launch.bat)** or **[vs64_launch.bat](https://github.com/angeluriot/Graphics_skeleton/blob/master/vs64_launch.bat)** to create the project with **Visual Studio 32** or **64** on **Windows**. *(recommended)*

* **[mingw32_launch.bat](https://github.com/angeluriot/Graphics_skeleton/blob/master/mingw32_launch.bat)** or **[mingw64_launch.bat](https://github.com/angeluriot/Graphics_skeleton/blob/master/mingw64_launch.bat)** to create and compile the project with **MinGW 32** or **64** on **Windows**. *(not recommended)*

***Note** : You will have to run it again each time you add a source file.*

# Demo

### Code example

Be careful to keep a structure similar to the one shown here :

```cpp
#include <dim/dimension3D.hpp>

int main()
{
    dim::Window::open("App", 0.75f);
    dim::Scene scene("Scene");

    // Camera
    scene.set_controller(dim::OrbitController());

    dim::PerspectiveCamera cam;
    cam.set_position(dim::Vector3(0.f, 0.f, 3.f));
    scene.set_camera(cam);

    // Lights
    scene.add_light(dim::DirectionalLight(dim::Vector3(-1.f, -1.f, -1.f), dim::Color(1.f, 1.f, 1.f)));

    // Objects
    dim::Object object_1(dim::Mesh::Sphere(256, 256), dim::Material(dim::Color(1.f, 0.1f, 0.1f), 0.1f, 0.5f, 0.6f, 30.f));

    dim::Object object_2(dim::Mesh::Cone(256), dim::Material(dim::Color(0.1f, 1.f, 0.1f), 0.1f, 0.5f, 0.6f, 30.f));
    object_2.move(dim::Vector3(1.1f, 0.f, 0.f));

    dim::Object object_3(dim::Mesh::Cylinder(256), dim::Material(dim::Color(0.1f, 0.1f, 1.f), 0.1f, 0.5f, 0.6f, 30.f));
    object_3.move(dim::Vector3(-1.1f, 0.f, 0.f));

    // Buttons info
    float color[4] = { 1.f, 1.f, 1.f, 1.f };

    // Main loop
    while (dim::Window::running)
    {
        // Dimension3D
        sf::Event sf_event;
        while (dim::Window::get_window().pollEvent(sf_event))
        {
            dim::Window::check_events(sf_event);
            scene.check_events(sf_event);
        }

        dim::Window::clear();
        scene.clear();

        dim::Window::update();
        scene.update();

        scene.draw(object_1);
        scene.draw(object_2);
        scene.draw(object_3);

        scene.display();

        // ImGui
        ImGui::Begin("Menu");
        ImGui::Button("Button");
        ImGui::ColorPicker3("Color picker", color, ImGuiColorEditFlags_PickerHueWheel);
        ImGui::End();

        // Dimension3D
        dim::Window::display();
    }

    dim::shut_down();
    return EXIT_SUCCESS;
}
```

### Release

You can also see the **[releases](https://github.com/angeluriot/Graphics_skeleton/releases)** of the **[skeleton project](https://github.com/angeluriot/Graphics_skeleton)** to test the example code without compiling.

# Wiki



# Notes

* This is a small project of a single beginner programmer so there may be bugs if you do not use the library as indicated.

# Credits

* [**Angel Uriot**](https://github.com/angeluriot) : Creator of the library.
