#ifndef input_paid_media_TEST
#define input_paid_media_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define input_paid_media_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/input_paid_media.h"
input_paid_media_t* instantiate_input_paid_media(int include_optional);



input_paid_media_t* instantiate_input_paid_media(int include_optional) {
  input_paid_media_t* input_paid_media = NULL;
  if (include_optional) {
    input_paid_media = input_paid_media_create(
      "video",
      "0",
      "0",
      "0",
      56,
      56,
      56,
      56,
      1
    );
  } else {
    input_paid_media = input_paid_media_create(
      "video",
      "0",
      "0",
      "0",
      56,
      56,
      56,
      56,
      1
    );
  }

  return input_paid_media;
}


#ifdef input_paid_media_MAIN

void test_input_paid_media(int include_optional) {
    input_paid_media_t* input_paid_media_1 = instantiate_input_paid_media(include_optional);

	cJSON* jsoninput_paid_media_1 = input_paid_media_convertToJSON(input_paid_media_1);
	printf("input_paid_media :\n%s\n", cJSON_Print(jsoninput_paid_media_1));
	input_paid_media_t* input_paid_media_2 = input_paid_media_parseFromJSON(jsoninput_paid_media_1);
	cJSON* jsoninput_paid_media_2 = input_paid_media_convertToJSON(input_paid_media_2);
	printf("repeating input_paid_media:\n%s\n", cJSON_Print(jsoninput_paid_media_2));
}

int main() {
  test_input_paid_media(1);
  test_input_paid_media(0);

  printf("Hello world \n");
  return 0;
}

#endif // input_paid_media_MAIN
#endif // input_paid_media_TEST
