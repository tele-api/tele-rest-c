#ifndef input_profile_photo_animated_TEST
#define input_profile_photo_animated_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define input_profile_photo_animated_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/input_profile_photo_animated.h"
input_profile_photo_animated_t* instantiate_input_profile_photo_animated(int include_optional);



input_profile_photo_animated_t* instantiate_input_profile_photo_animated(int include_optional) {
  input_profile_photo_animated_t* input_profile_photo_animated = NULL;
  if (include_optional) {
    input_profile_photo_animated = input_profile_photo_animated_create(
      "animated",
      "0",
      1.337
    );
  } else {
    input_profile_photo_animated = input_profile_photo_animated_create(
      "animated",
      "0",
      1.337
    );
  }

  return input_profile_photo_animated;
}


#ifdef input_profile_photo_animated_MAIN

void test_input_profile_photo_animated(int include_optional) {
    input_profile_photo_animated_t* input_profile_photo_animated_1 = instantiate_input_profile_photo_animated(include_optional);

	cJSON* jsoninput_profile_photo_animated_1 = input_profile_photo_animated_convertToJSON(input_profile_photo_animated_1);
	printf("input_profile_photo_animated :\n%s\n", cJSON_Print(jsoninput_profile_photo_animated_1));
	input_profile_photo_animated_t* input_profile_photo_animated_2 = input_profile_photo_animated_parseFromJSON(jsoninput_profile_photo_animated_1);
	cJSON* jsoninput_profile_photo_animated_2 = input_profile_photo_animated_convertToJSON(input_profile_photo_animated_2);
	printf("repeating input_profile_photo_animated:\n%s\n", cJSON_Print(jsoninput_profile_photo_animated_2));
}

int main() {
  test_input_profile_photo_animated(1);
  test_input_profile_photo_animated(0);

  printf("Hello world \n");
  return 0;
}

#endif // input_profile_photo_animated_MAIN
#endif // input_profile_photo_animated_TEST
