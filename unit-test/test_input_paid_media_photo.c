#ifndef input_paid_media_photo_TEST
#define input_paid_media_photo_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define input_paid_media_photo_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/input_paid_media_photo.h"
input_paid_media_photo_t* instantiate_input_paid_media_photo(int include_optional);



input_paid_media_photo_t* instantiate_input_paid_media_photo(int include_optional) {
  input_paid_media_photo_t* input_paid_media_photo = NULL;
  if (include_optional) {
    input_paid_media_photo = input_paid_media_photo_create(
      "photo",
      "0"
    );
  } else {
    input_paid_media_photo = input_paid_media_photo_create(
      "photo",
      "0"
    );
  }

  return input_paid_media_photo;
}


#ifdef input_paid_media_photo_MAIN

void test_input_paid_media_photo(int include_optional) {
    input_paid_media_photo_t* input_paid_media_photo_1 = instantiate_input_paid_media_photo(include_optional);

	cJSON* jsoninput_paid_media_photo_1 = input_paid_media_photo_convertToJSON(input_paid_media_photo_1);
	printf("input_paid_media_photo :\n%s\n", cJSON_Print(jsoninput_paid_media_photo_1));
	input_paid_media_photo_t* input_paid_media_photo_2 = input_paid_media_photo_parseFromJSON(jsoninput_paid_media_photo_1);
	cJSON* jsoninput_paid_media_photo_2 = input_paid_media_photo_convertToJSON(input_paid_media_photo_2);
	printf("repeating input_paid_media_photo:\n%s\n", cJSON_Print(jsoninput_paid_media_photo_2));
}

int main() {
  test_input_paid_media_photo(1);
  test_input_paid_media_photo(0);

  printf("Hello world \n");
  return 0;
}

#endif // input_paid_media_photo_MAIN
#endif // input_paid_media_photo_TEST
