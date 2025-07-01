#ifndef input_profile_photo_TEST
#define input_profile_photo_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define input_profile_photo_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/input_profile_photo.h"
input_profile_photo_t* instantiate_input_profile_photo(int include_optional);



input_profile_photo_t* instantiate_input_profile_photo(int include_optional) {
  input_profile_photo_t* input_profile_photo = NULL;
  if (include_optional) {
    input_profile_photo = input_profile_photo_create(
      "animated",
      "0",
      "0",
      1.337
    );
  } else {
    input_profile_photo = input_profile_photo_create(
      "animated",
      "0",
      "0",
      1.337
    );
  }

  return input_profile_photo;
}


#ifdef input_profile_photo_MAIN

void test_input_profile_photo(int include_optional) {
    input_profile_photo_t* input_profile_photo_1 = instantiate_input_profile_photo(include_optional);

	cJSON* jsoninput_profile_photo_1 = input_profile_photo_convertToJSON(input_profile_photo_1);
	printf("input_profile_photo :\n%s\n", cJSON_Print(jsoninput_profile_photo_1));
	input_profile_photo_t* input_profile_photo_2 = input_profile_photo_parseFromJSON(jsoninput_profile_photo_1);
	cJSON* jsoninput_profile_photo_2 = input_profile_photo_convertToJSON(input_profile_photo_2);
	printf("repeating input_profile_photo:\n%s\n", cJSON_Print(jsoninput_profile_photo_2));
}

int main() {
  test_input_profile_photo(1);
  test_input_profile_photo(0);

  printf("Hello world \n");
  return 0;
}

#endif // input_profile_photo_MAIN
#endif // input_profile_photo_TEST
