#ifndef input_sticker_TEST
#define input_sticker_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define input_sticker_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/input_sticker.h"
input_sticker_t* instantiate_input_sticker(int include_optional);

#include "test_mask_position.c"


input_sticker_t* instantiate_input_sticker(int include_optional) {
  input_sticker_t* input_sticker = NULL;
  if (include_optional) {
    input_sticker = input_sticker_create(
      "0",
      telegram_bot_api_input_sticker_FORMAT_static,
      list_createList(),
       // false, not to have infinite recursion
      instantiate_mask_position(0),
      list_createList()
    );
  } else {
    input_sticker = input_sticker_create(
      "0",
      telegram_bot_api_input_sticker_FORMAT_static,
      list_createList(),
      NULL,
      list_createList()
    );
  }

  return input_sticker;
}


#ifdef input_sticker_MAIN

void test_input_sticker(int include_optional) {
    input_sticker_t* input_sticker_1 = instantiate_input_sticker(include_optional);

	cJSON* jsoninput_sticker_1 = input_sticker_convertToJSON(input_sticker_1);
	printf("input_sticker :\n%s\n", cJSON_Print(jsoninput_sticker_1));
	input_sticker_t* input_sticker_2 = input_sticker_parseFromJSON(jsoninput_sticker_1);
	cJSON* jsoninput_sticker_2 = input_sticker_convertToJSON(input_sticker_2);
	printf("repeating input_sticker:\n%s\n", cJSON_Print(jsoninput_sticker_2));
}

int main() {
  test_input_sticker(1);
  test_input_sticker(0);

  printf("Hello world \n");
  return 0;
}

#endif // input_sticker_MAIN
#endif // input_sticker_TEST
