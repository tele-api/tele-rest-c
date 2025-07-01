#ifndef input_message_content_TEST
#define input_message_content_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define input_message_content_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/input_message_content.h"
input_message_content_t* instantiate_input_message_content(int include_optional);

#include "test_link_preview_options.c"


input_message_content_t* instantiate_input_message_content(int include_optional) {
  input_message_content_t* input_message_content = NULL;
  if (include_optional) {
    input_message_content = input_message_content_create(
      "0",
      1.337,
      1.337,
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      list_createList(),
      "0",
      list_createList(),
       // false, not to have infinite recursion
      instantiate_link_preview_options(0),
      1.337,
      56,
      56,
      56,
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      56,
      list_createList(),
      "0",
      "0",
      56,
      56,
      56,
      1,
      1,
      1,
      1,
      1,
      1,
      1
    );
  } else {
    input_message_content = input_message_content_create(
      "0",
      1.337,
      1.337,
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      list_createList(),
      "0",
      list_createList(),
      NULL,
      1.337,
      56,
      56,
      56,
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      56,
      list_createList(),
      "0",
      "0",
      56,
      56,
      56,
      1,
      1,
      1,
      1,
      1,
      1,
      1
    );
  }

  return input_message_content;
}


#ifdef input_message_content_MAIN

void test_input_message_content(int include_optional) {
    input_message_content_t* input_message_content_1 = instantiate_input_message_content(include_optional);

	cJSON* jsoninput_message_content_1 = input_message_content_convertToJSON(input_message_content_1);
	printf("input_message_content :\n%s\n", cJSON_Print(jsoninput_message_content_1));
	input_message_content_t* input_message_content_2 = input_message_content_parseFromJSON(jsoninput_message_content_1);
	cJSON* jsoninput_message_content_2 = input_message_content_convertToJSON(input_message_content_2);
	printf("repeating input_message_content:\n%s\n", cJSON_Print(jsoninput_message_content_2));
}

int main() {
  test_input_message_content(1);
  test_input_message_content(0);

  printf("Hello world \n");
  return 0;
}

#endif // input_message_content_MAIN
#endif // input_message_content_TEST
