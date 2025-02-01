# Village Scene Graphics Project

A simple yet beautiful OpenGL-based graphics project that renders an animated village scene with various interactive elements.

## Features

- Animated sun rise effect
- Moving sailboats on a river
- Flying birds with wing animations
- Detailed house with windows and doors
- Multiple trees with gradient coloring
- Background scenery with mountains
- Fenced areas and surroundings

## Prerequisites

To run this project, you need:

- macOS (This project uses OpenGL and GLUT for macOS)
- C++ compiler (g++ or clang++)
- OpenGL framework
- GLUT framework

## Project Structure

- `main.cpp` - Main program file containing the display and animation logic
- `house.cpp` - House drawing implementation
- `tree.cpp` - Tree drawing with gradient effects
- `bird.cpp` - Bird animation and drawing logic
- `surrounding.cpp` - Background and scenery elements
- `Makefile` - Build configuration

## How to Build and Run

1. Open Terminal and navigate to the project directory:
   ```bash
   cd path/to/Graphics-Mini-Project
   ```

2. Compile the project using make:
   ```bash
   make
   ```

3. Run the executable:
   ```bash
   ./village
   ```

## Scene Components

1. **Sky and Ground**
   - Sky blue background
   - Light yellow-green ground

2. **Animated Elements**
   - Rising sun with rays
   - Boats moving across the river
   - Birds flying with wing-flapping animation

3. **Static Elements**
   - House with windows and doors
   - Multiple trees with gradient coloring
   - Fenced areas
   - Mountains in the background

## Controls

The scene is automatically animated. Just run the program and watch the animations:
- Sun rises gradually
- Boats move back and forth on the river
- Birds fly across the sky with realistic wing movements

## Technical Details

- Written in C++ using OpenGL
- Uses GLUT for window management
- Implements various OpenGL primitives (GL_POLYGON, GL_TRIANGLES, GL_LINES)
- Features smooth animations and color gradients
- Modular code structure with separate files for each major component

## Author

Rohit Kumar Mandal

## License

This project is open source and available under the MIT License. 
