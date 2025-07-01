#ifndef input_venue_message_content_TEST
#define input_venue_message_content_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define input_venue_message_content_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/input_venue_message_content.h"
input_venue_message_content_t* instantiate_input_venue_message_content(int include_optional);



input_venue_message_content_t* instantiate_input_venue_message_content(int include_optional) {
  input_venue_message_content_t* input_venue_message_content = NULL;
  if (include_optional) {
    input_venue_message_content = input_venue_message_content_create(
      1.337,
      1.337,
      "0",
      "0",
      "0",
      "0",
      "0",
      "0"
    );
  } else {
    input_venue_message_content = input_venue_message_content_create(
      1.337,
      1.337,
      "0",
      "0",
      "0",
      "0",
      "0",
      "0"
    );
  }

  return input_venue_message_content;
}


#ifdef input_venue_message_content_MAIN

void test_input_venue_message_content(int include_optional) {
    input_venue_message_content_t* input_venue_message_content_1 = instantiate_input_venue_message_content(include_optional);

	cJSON* jsoninput_venue_message_content_1 = input_venue_message_content_convertToJSON(input_venue_message_content_1);
	printf("input_venue_message_content :\n%s\n", cJSON_Print(jsoninput_venue_message_content_1));
	input_venue_message_content_t* input_venue_message_content_2 = input_venue_message_content_parseFromJSON(jsoninput_venue_message_content_1);
	cJSON* jsoninput_venue_message_content_2 = input_venue_message_content_convertToJSON(input_venue_message_content_2);
	printf("repeating input_venue_message_content:\n%s\n", cJSON_Print(jsoninput_venue_message_content_2));
}

int main() {
  test_input_venue_message_content(1);
  test_input_venue_message_content(0);

  printf("Hello world \n");
  return 0;
}

#endif // input_venue_message_content_MAIN
#endif // input_venue_message_content_TEST
