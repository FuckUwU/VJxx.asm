#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "VJxx/integral_image.h"

#define IN_VALUES { \
    0,    0,    0,    0,    0,    0, \
    0,  255,  255,  510,  510,  765, \
    0,  255,  510, 765,  1020, 1275, \
    0,  510,  765, 1275, 1530, 2040 \
}
#define IN_WIDTH 6
#define IN_HEIGHT 4
#define IN_SIZE IN_WIDTH * IN_HEIGHT * sizeof(unsigned int)

#define EXPECTED_SUM 1020

int main() {
  vjxx_integral_image_t integral_img;
  integral_img.width = IN_WIDTH;
  integral_img.height = IN_HEIGHT;
  const unsigned int in_values[] = IN_VALUES;
  integral_img.values = in_values;
  memcpy(integral_img.values, in_values, IN_WIDTH * IN_HEIGHT);
  printf("\n\n%d\n\n", vjxx_sum_area(integral_img, 1, 1, 5, 3));
  if (vjxx_sum_area(integral_img, 1, 1, 5, 3) != EXPECTED_SUM) {
    return EXIT_FAILURE;
  }
  
  return EXIT_SUCCESS;
}

