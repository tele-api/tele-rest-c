#ifndef animation_TEST
#define animation_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define animation_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/animation.h"
animation_t* instantiate_animation(int include_optional);

#include "test_photo_size.c"


animation_t* instantiate_animation(int include_optional) {
  animation_t* animation = NULL;
  if (include_optional) {
    animation = animation_create(
      "0",
      "0",
      56,
      56,
      56,
       // false, not to have infinite recursion
      instantiate_photo_size(0),
      "0",
      "0",
      56
    );
  } else {
    animation = animation_create(
      "0",
      "0",
      56,
      56,
      56,
      NULL,
      "0",
      "0",
      56
    );
  }

  return animation;
}


#ifdef animation_MAIN

void test_animation(int include_optional) {
    animation_t* animation_1 = instantiate_animation(include_optional);

	cJSON* jsonanimation_1 = animation_convertToJSON(animation_1);
	printf("animation :\n%s\n", cJSON_Print(jsonanimation_1));
	animation_t* animation_2 = animation_parseFromJSON(jsonanimation_1);
	cJSON* jsonanimation_2 = animation_convertToJSON(animation_2);
	printf("repeating animation:\n%s\n", cJSON_Print(jsonanimation_2));
}

int main() {
  test_animation(1);
  test_animation(0);

  printf("Hello world \n");
  return 0;
}

#endif // animation_MAIN
#endif // animation_TEST
