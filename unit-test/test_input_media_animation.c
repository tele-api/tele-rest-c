#ifndef input_media_animation_TEST
#define input_media_animation_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define input_media_animation_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/input_media_animation.h"
input_media_animation_t* instantiate_input_media_animation(int include_optional);



input_media_animation_t* instantiate_input_media_animation(int include_optional) {
  input_media_animation_t* input_media_animation = NULL;
  if (include_optional) {
    input_media_animation = input_media_animation_create(
      "animation",
      "0",
      "0",
      "0",
      "0",
      list_createList(),
      1,
      56,
      56,
      56,
      1
    );
  } else {
    input_media_animation = input_media_animation_create(
      "animation",
      "0",
      "0",
      "0",
      "0",
      list_createList(),
      1,
      56,
      56,
      56,
      1
    );
  }

  return input_media_animation;
}


#ifdef input_media_animation_MAIN

void test_input_media_animation(int include_optional) {
    input_media_animation_t* input_media_animation_1 = instantiate_input_media_animation(include_optional);

	cJSON* jsoninput_media_animation_1 = input_media_animation_convertToJSON(input_media_animation_1);
	printf("input_media_animation :\n%s\n", cJSON_Print(jsoninput_media_animation_1));
	input_media_animation_t* input_media_animation_2 = input_media_animation_parseFromJSON(jsoninput_media_animation_1);
	cJSON* jsoninput_media_animation_2 = input_media_animation_convertToJSON(input_media_animation_2);
	printf("repeating input_media_animation:\n%s\n", cJSON_Print(jsoninput_media_animation_2));
}

int main() {
  test_input_media_animation(1);
  test_input_media_animation(0);

  printf("Hello world \n");
  return 0;
}

#endif // input_media_animation_MAIN
#endif // input_media_animation_TEST
