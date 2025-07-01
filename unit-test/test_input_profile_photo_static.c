#ifndef input_profile_photo_static_TEST
#define input_profile_photo_static_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define input_profile_photo_static_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/input_profile_photo_static.h"
input_profile_photo_static_t* instantiate_input_profile_photo_static(int include_optional);



input_profile_photo_static_t* instantiate_input_profile_photo_static(int include_optional) {
  input_profile_photo_static_t* input_profile_photo_static = NULL;
  if (include_optional) {
    input_profile_photo_static = input_profile_photo_static_create(
      "static",
      "0"
    );
  } else {
    input_profile_photo_static = input_profile_photo_static_create(
      "static",
      "0"
    );
  }

  return input_profile_photo_static;
}


#ifdef input_profile_photo_static_MAIN

void test_input_profile_photo_static(int include_optional) {
    input_profile_photo_static_t* input_profile_photo_static_1 = instantiate_input_profile_photo_static(include_optional);

	cJSON* jsoninput_profile_photo_static_1 = input_profile_photo_static_convertToJSON(input_profile_photo_static_1);
	printf("input_profile_photo_static :\n%s\n", cJSON_Print(jsoninput_profile_photo_static_1));
	input_profile_photo_static_t* input_profile_photo_static_2 = input_profile_photo_static_parseFromJSON(jsoninput_profile_photo_static_1);
	cJSON* jsoninput_profile_photo_static_2 = input_profile_photo_static_convertToJSON(input_profile_photo_static_2);
	printf("repeating input_profile_photo_static:\n%s\n", cJSON_Print(jsoninput_profile_photo_static_2));
}

int main() {
  test_input_profile_photo_static(1);
  test_input_profile_photo_static(0);

  printf("Hello world \n");
  return 0;
}

#endif // input_profile_photo_static_MAIN
#endif // input_profile_photo_static_TEST
