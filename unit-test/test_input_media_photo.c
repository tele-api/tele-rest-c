#ifndef input_media_photo_TEST
#define input_media_photo_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define input_media_photo_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/input_media_photo.h"
input_media_photo_t* instantiate_input_media_photo(int include_optional);



input_media_photo_t* instantiate_input_media_photo(int include_optional) {
  input_media_photo_t* input_media_photo = NULL;
  if (include_optional) {
    input_media_photo = input_media_photo_create(
      "photo",
      "0",
      "0",
      "0",
      list_createList(),
      1,
      1
    );
  } else {
    input_media_photo = input_media_photo_create(
      "photo",
      "0",
      "0",
      "0",
      list_createList(),
      1,
      1
    );
  }

  return input_media_photo;
}


#ifdef input_media_photo_MAIN

void test_input_media_photo(int include_optional) {
    input_media_photo_t* input_media_photo_1 = instantiate_input_media_photo(include_optional);

	cJSON* jsoninput_media_photo_1 = input_media_photo_convertToJSON(input_media_photo_1);
	printf("input_media_photo :\n%s\n", cJSON_Print(jsoninput_media_photo_1));
	input_media_photo_t* input_media_photo_2 = input_media_photo_parseFromJSON(jsoninput_media_photo_1);
	cJSON* jsoninput_media_photo_2 = input_media_photo_convertToJSON(input_media_photo_2);
	printf("repeating input_media_photo:\n%s\n", cJSON_Print(jsoninput_media_photo_2));
}

int main() {
  test_input_media_photo(1);
  test_input_media_photo(0);

  printf("Hello world \n");
  return 0;
}

#endif // input_media_photo_MAIN
#endif // input_media_photo_TEST
