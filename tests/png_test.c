#define DRAW_TOOL_COLORS_4BIT
#include "../draw_tool.c"
#include <sys/time.h>

int main() {
  struct timeval tv;
  gettimeofday(&tv, NULL);
  srand(tv.tv_usec);

  const int DIAMONDS = 5;
  const int SIZE = 10;
  Olivec_Canvas oc = make_canvas();
  olivec_fill(oc, BLUE | (GREEN >> 1));
  olivec_rect(oc, 0, HEIGHT * 2 / 3, WIDTH, HEIGHT / 3, RED | (GREEN << 6));
  for (int i = 0; i < DIAMONDS; ++i) {
    int x = (double)rand() / RAND_MAX * WIDTH;
    int y = (double)rand() / RAND_MAX * HEIGHT / 3;
    int size = (double)rand() / RAND_MAX * SIZE + 5;
    int rgb = (double)rand() / RAND_MAX * 255;
    int color =
        (0xFF << 8 * 3) | (rgb << 8 * 2) | (rgb << 8 * 1) | (rgb << 8 * 0);
    olivec_triangle(oc, x + size, y + (size << 1), x + (size << 1), y, x, y,
                    color);
    olivec_triangle(oc, x + size, y - (size << 1), x + (size << 1), y, x, y,
                    color);
  }
  write_canvas_png(&oc, "output/test.png");
}
