# cub3d

42 School - cub3d Project  
A raycasting engine inspired by Wolfenstein 3D.

## Overview

This project is a 3D graphical game engine using **raycasting** technique. It renders a 3D perspective from a 2D map, including textured walls, floor/ceiling coloring, sprite rendering, and player movement.

## Features

- Realistic 3D rendering using raycasting
- Textured walls (different textures per direction)
- Floor and ceiling colors (or optional textures)
- Player movement (WASD + arrow keys)
- Collision detection with walls
- Sprite rendering (objects like pillars, barrels, etc.)
- Minimap (optional bonus)
- Smooth mouse look / camera rotation
- Parsing of custom `.cub` map files
- Error handling and input validation

## Controls

| Key          | Action                  |
|--------------|-------------------------|
| `W` / `↑`    | Move forward            |
| `S` / `↓`    | Move backward           |
| `A`          | Strafe left             |
| `D`          | Strafe right            |
| `←` / `→`    | Rotate camera           |
| `ESC`        | Exit game               |

## Project Structure
```
cub3d/
├── Makefile
├── source/          # Main source files
├── include/         # Header files
├── libft/           # Custom C library
├── mlx/             # MiniLibX (graphics library)
├── maps/            # .cub map files
├── textures/        # Wall textures
├── images/          # Screenshots or assets
└── README.md
```
## Usage

```
# Clone the repository
git clone https://github.com/rmatthesius/cub3d.git
cd cub3d

# Compile
make

# Run with a map
./cub3d maps/map.cub
```

## Building
```
make          # Compile the project
make clean    # Remove object files
make fclean   # Full clean (includes executable)
make re       # Rebuild everything
```
## Requirements

- macOS or Linux
- MiniLibX (included in the repo)
- X11 / OpenGL development libraries (Linux)

## Notes

- This is a 42 School project — the goal is to code a small 3D engine from scratch without using modern game engines.
- All maps must follow the .cub format specification (see subject PDF).
- This was a group project


Read-only repository
You are welcome to view, fork, or clone the code, but you cannot push any changes.
