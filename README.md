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
	* [Windows](#summary)
	* [2D](#summary)
	* [3D](#summary)
	* [Simplified OpenGL objects](#summary)
	* [Utils](#summary)
* **[Install](#install)**
* **[Demo](#demo)**
* **[Wiki](#wiki)**
* **[Notes](#notes)**

# Features

* #### Windows :

	* Interactive windows with buttons, sliders... *(see **[ImGui](https://github.com/ocornut/imgui)** for more information)*.

	* Scene windows for display.

* #### 2D :

	* Rectangles, circles, custom shapes, images... *(see **[SFML](https://www.sfml-dev.org/)** for more information)* on a scene or the main window.

	* A drag controller to move the view with the mouse.

* #### 3D :

	* Cubes, spheres, cylinders, cones, custom meshes...

	* Phong materials, Textures...

	* Ambient, directional and point lights.

	* Perspective and orthographic cameras.

	* Drag, fly and orbit controllers.

* #### Simplified OpenGL objects :

	* Shaders, framebuffers, vertexbuffers, textures...

* #### Utils :

	* Colors, vectors, utils functions...

# Install

# Demo

# Wiki

# Notes

The Barnes-Hut algorithm was used to optimize the simulation, here is what the different areas used for the calculation look like:

<p align="center">
	<img src="https://i.imgur.com/XUF0ODw.png" width="700">
</p>

<br/>

# Credits

* [**Angel Uriot**](https://github.com/angeluriot) : Creator of the project.
