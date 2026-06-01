# Image Viewer

A simple C program for viewing PPM image files.

## Features

- Loads and displays PPM format images
- Minimal dependencies

## Requirements

- **SDL2**: Simple DirectMedia Layer 2
  - Download: https://www.libsdl.org/download-2.0.php
  - On Linux: `sudo apt-get install libsdl2-dev`

## Files

- `iv.c`: Main image viewer implementation
- `sample.ppm`: Sample image file

## How to Run

1. Compile the program:
   ```bash
   gcc -o iv iv.c `sdl2-config --cflags --libs`
   ```

2. Run with a PPM image:
   ```bash
   cat sample.ppm | ./iv
   ```