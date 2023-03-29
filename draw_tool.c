#define OLIVEC_IMPLEMENTATION
#include "dependencies/olive.c"
#ifndef NO_STANDARD_LIBRARIES
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "dependencies/stb_image_write.h"
#endif

#ifndef WIDTH
#define WIDTH 400
#endif

#ifndef HEIGHT
#define HEIGHT 300
#endif

uint32_t pixels[WIDTH * HEIGHT];

#ifdef DRAW_TOOL_COLORS_4BIT
#define WHITE 0xFFFFFFFF
#define RED 0xFF0000FF
#define GREEN 0xFF00FF00
#define BLUE 0xFFFF0000
#define BLACK 0xFF000000
#endif

#ifndef NO_STANDARD_LIBRARIES
bool write_canvas_png(Olivec_Canvas *canvas, const char *file_path) {
  return stbi_write_png(file_path, canvas->width, canvas->height, 4,
                        canvas->pixels, sizeof(uint32_t) * canvas->width);
}
#endif

Olivec_Canvas make_canvas() {
  return olivec_canvas(pixels, WIDTH, HEIGHT, WIDTH);
}
