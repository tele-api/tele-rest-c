#ifndef input_story_content_TEST
#define input_story_content_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define input_story_content_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/input_story_content.h"
input_story_content_t* instantiate_input_story_content(int include_optional);



input_story_content_t* instantiate_input_story_content(int include_optional) {
  input_story_content_t* input_story_content = NULL;
  if (include_optional) {
    input_story_content = input_story_content_create(
      "video",
      "0",
      "0",
      1.337,
      1.337,
      1
    );
  } else {
    input_story_content = input_story_content_create(
      "video",
      "0",
      "0",
      1.337,
      1.337,
      1
    );
  }

  return input_story_content;
}


#ifdef input_story_content_MAIN

void test_input_story_content(int include_optional) {
    input_story_content_t* input_story_content_1 = instantiate_input_story_content(include_optional);

	cJSON* jsoninput_story_content_1 = input_story_content_convertToJSON(input_story_content_1);
	printf("input_story_content :\n%s\n", cJSON_Print(jsoninput_story_content_1));
	input_story_content_t* input_story_content_2 = input_story_content_parseFromJSON(jsoninput_story_content_1);
	cJSON* jsoninput_story_content_2 = input_story_content_convertToJSON(input_story_content_2);
	printf("repeating input_story_content:\n%s\n", cJSON_Print(jsoninput_story_content_2));
}

int main() {
  test_input_story_content(1);
  test_input_story_content(0);

  printf("Hello world \n");
  return 0;
}

#endif // input_story_content_MAIN
#endif // input_story_content_TEST
