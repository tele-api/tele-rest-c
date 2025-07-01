#ifndef input_story_content_photo_TEST
#define input_story_content_photo_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define input_story_content_photo_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/input_story_content_photo.h"
input_story_content_photo_t* instantiate_input_story_content_photo(int include_optional);



input_story_content_photo_t* instantiate_input_story_content_photo(int include_optional) {
  input_story_content_photo_t* input_story_content_photo = NULL;
  if (include_optional) {
    input_story_content_photo = input_story_content_photo_create(
      "photo",
      "0"
    );
  } else {
    input_story_content_photo = input_story_content_photo_create(
      "photo",
      "0"
    );
  }

  return input_story_content_photo;
}


#ifdef input_story_content_photo_MAIN

void test_input_story_content_photo(int include_optional) {
    input_story_content_photo_t* input_story_content_photo_1 = instantiate_input_story_content_photo(include_optional);

	cJSON* jsoninput_story_content_photo_1 = input_story_content_photo_convertToJSON(input_story_content_photo_1);
	printf("input_story_content_photo :\n%s\n", cJSON_Print(jsoninput_story_content_photo_1));
	input_story_content_photo_t* input_story_content_photo_2 = input_story_content_photo_parseFromJSON(jsoninput_story_content_photo_1);
	cJSON* jsoninput_story_content_photo_2 = input_story_content_photo_convertToJSON(input_story_content_photo_2);
	printf("repeating input_story_content_photo:\n%s\n", cJSON_Print(jsoninput_story_content_photo_2));
}

int main() {
  test_input_story_content_photo(1);
  test_input_story_content_photo(0);

  printf("Hello world \n");
  return 0;
}

#endif // input_story_content_photo_MAIN
#endif // input_story_content_photo_TEST
