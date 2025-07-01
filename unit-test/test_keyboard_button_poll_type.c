#ifndef keyboard_button_poll_type_TEST
#define keyboard_button_poll_type_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define keyboard_button_poll_type_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/keyboard_button_poll_type.h"
keyboard_button_poll_type_t* instantiate_keyboard_button_poll_type(int include_optional);



keyboard_button_poll_type_t* instantiate_keyboard_button_poll_type(int include_optional) {
  keyboard_button_poll_type_t* keyboard_button_poll_type = NULL;
  if (include_optional) {
    keyboard_button_poll_type = keyboard_button_poll_type_create(
      "0"
    );
  } else {
    keyboard_button_poll_type = keyboard_button_poll_type_create(
      "0"
    );
  }

  return keyboard_button_poll_type;
}


#ifdef keyboard_button_poll_type_MAIN

void test_keyboard_button_poll_type(int include_optional) {
    keyboard_button_poll_type_t* keyboard_button_poll_type_1 = instantiate_keyboard_button_poll_type(include_optional);

	cJSON* jsonkeyboard_button_poll_type_1 = keyboard_button_poll_type_convertToJSON(keyboard_button_poll_type_1);
	printf("keyboard_button_poll_type :\n%s\n", cJSON_Print(jsonkeyboard_button_poll_type_1));
	keyboard_button_poll_type_t* keyboard_button_poll_type_2 = keyboard_button_poll_type_parseFromJSON(jsonkeyboard_button_poll_type_1);
	cJSON* jsonkeyboard_button_poll_type_2 = keyboard_button_poll_type_convertToJSON(keyboard_button_poll_type_2);
	printf("repeating keyboard_button_poll_type:\n%s\n", cJSON_Print(jsonkeyboard_button_poll_type_2));
}

int main() {
  test_keyboard_button_poll_type(1);
  test_keyboard_button_poll_type(0);

  printf("Hello world \n");
  return 0;
}

#endif // keyboard_button_poll_type_MAIN
#endif // keyboard_button_poll_type_TEST
