#include <stdint.h>
#define DRAW_TOOL_COLORS_4BIT
#define NO_STANDARD_LIBRARIES

#include "../draw_tool.c"

uint32_t *render() {
  Olivec_Canvas oc = make_canvas();
  olivec_fill(oc, BLUE);
  return oc.pixels;
}
