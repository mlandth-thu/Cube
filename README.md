# Cube
 Simple 3D OpenGL scene

## Sources
- Youtube Tutorial: https://www.youtube.com/watch?v=DkyOI59Ij2c
- Accompanying code base from: https://github.com/PardCode/OpenGL-3D-Game-Tutorial-Series/tree/tutorials/Tutorial7_Cube

## How to
- Open the "OpenGLGame.sln" file (Visual Studio Project)
- Then run the project

### Locations
- Main class: /Game/main.cpp
- Logic: /OGL3D/source/OGL3D/Game/OGame.cpp
- Shaders: /Assets/Shaders/...

## Example
The video "Cube-mlandth.mp4" shows a short clip of the running scene

## Changes / modifications:

- Modified shader
  - Changed color
  - Modified shader to use 3 parameters instead of 2 for a more advanced gradient
- Scene
  - Slowed down the moving scene
  - Added individual values for the rotation on x, y and z axis instead of a single value <br>
    This leads to a better overall surround view of the cube
