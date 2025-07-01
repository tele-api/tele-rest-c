#ifndef input_poll_option_TEST
#define input_poll_option_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define input_poll_option_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/input_poll_option.h"
input_poll_option_t* instantiate_input_poll_option(int include_optional);



input_poll_option_t* instantiate_input_poll_option(int include_optional) {
  input_poll_option_t* input_poll_option = NULL;
  if (include_optional) {
    input_poll_option = input_poll_option_create(
      "0",
      "0",
      list_createList()
    );
  } else {
    input_poll_option = input_poll_option_create(
      "0",
      "0",
      list_createList()
    );
  }

  return input_poll_option;
}


#ifdef input_poll_option_MAIN

void test_input_poll_option(int include_optional) {
    input_poll_option_t* input_poll_option_1 = instantiate_input_poll_option(include_optional);

	cJSON* jsoninput_poll_option_1 = input_poll_option_convertToJSON(input_poll_option_1);
	printf("input_poll_option :\n%s\n", cJSON_Print(jsoninput_poll_option_1));
	input_poll_option_t* input_poll_option_2 = input_poll_option_parseFromJSON(jsoninput_poll_option_1);
	cJSON* jsoninput_poll_option_2 = input_poll_option_convertToJSON(input_poll_option_2);
	printf("repeating input_poll_option:\n%s\n", cJSON_Print(jsoninput_poll_option_2));
}

int main() {
  test_input_poll_option(1);
  test_input_poll_option(0);

  printf("Hello world \n");
  return 0;
}

#endif // input_poll_option_MAIN
#endif // input_poll_option_TEST
