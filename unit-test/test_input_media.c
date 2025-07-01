#ifndef input_media_TEST
#define input_media_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define input_media_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/input_media.h"
input_media_t* instantiate_input_media(int include_optional);



input_media_t* instantiate_input_media(int include_optional) {
  input_media_t* input_media = NULL;
  if (include_optional) {
    input_media = input_media_create(
      "video",
      "0",
      "0",
      "0",
      "0",
      list_createList(),
      1,
      56,
      56,
      56,
      1,
      1,
      "0",
      "0",
      "0",
      56,
      1
    );
  } else {
    input_media = input_media_create(
      "video",
      "0",
      "0",
      "0",
      "0",
      list_createList(),
      1,
      56,
      56,
      56,
      1,
      1,
      "0",
      "0",
      "0",
      56,
      1
    );
  }

  return input_media;
}


#ifdef input_media_MAIN

void test_input_media(int include_optional) {
    input_media_t* input_media_1 = instantiate_input_media(include_optional);

	cJSON* jsoninput_media_1 = input_media_convertToJSON(input_media_1);
	printf("input_media :\n%s\n", cJSON_Print(jsoninput_media_1));
	input_media_t* input_media_2 = input_media_parseFromJSON(jsoninput_media_1);
	cJSON* jsoninput_media_2 = input_media_convertToJSON(input_media_2);
	printf("repeating input_media:\n%s\n", cJSON_Print(jsoninput_media_2));
}

int main() {
  test_input_media(1);
  test_input_media(0);

  printf("Hello world \n");
  return 0;
}

#endif // input_media_MAIN
#endif // input_media_TEST
