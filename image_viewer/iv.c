#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include <string.h>

int main () {

  FILE *pin = stdin;
  char *temp = calloc(1000, sizeof(char));
  // read format p6
  fgets(temp, 1000, pin);

  if (strncmp(temp, "P6", 2) != 0) {
    free(temp);
    printf("ERR: Not a valid ppm file!!!\n");
    return EXIT_FAILURE;
  }

  // read dimension
  char *pdim = calloc(1000, sizeof(char));
  fgets(pdim, 1000, pin);
  // read highest intensity value
  fgets(temp, 1000, pin);
  free(temp);
  
  int width = 0, height = 0;
  sscanf(pdim, "%d %d\n", &width, &height);
  free(pdim);

  SDL_Window* pwindow = SDL_CreateWindow("Image Viewer", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, 0);
  SDL_Surface* psurface = SDL_GetWindowSurface(pwindow);

  SDL_Rect pixel = (SDL_Rect){0, 0, 1, 1};
  Uint32 color = 0;

  for (int y = 0; y < height; y++) {
    for (int x = 0; x < width; x++) {
      Uint8 r, g, b;
      r = (char) getchar();
      g = (char) getchar();
      b = (char) getchar();
      color = SDL_MapRGB(psurface->format, r, g, b);
      pixel.x = x;
      pixel.y = y;
      SDL_FillRect(psurface, &pixel, color);
    }
  }

  SDL_UpdateWindowSurface(pwindow);

  int app_running = 1;
  while (app_running) {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
      if (event.type == SDL_QUIT) {
        app_running = 0;
      }
    }
  }

  return EXIT_SUCCESS;
}
