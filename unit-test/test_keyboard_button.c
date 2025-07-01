#ifndef keyboard_button_TEST
#define keyboard_button_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define keyboard_button_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/keyboard_button.h"
keyboard_button_t* instantiate_keyboard_button(int include_optional);

#include "test_keyboard_button_request_users.c"
#include "test_keyboard_button_request_chat.c"
#include "test_keyboard_button_poll_type.c"
#include "test_web_app_info.c"


keyboard_button_t* instantiate_keyboard_button(int include_optional) {
  keyboard_button_t* keyboard_button = NULL;
  if (include_optional) {
    keyboard_button = keyboard_button_create(
      "0",
       // false, not to have infinite recursion
      instantiate_keyboard_button_request_users(0),
       // false, not to have infinite recursion
      instantiate_keyboard_button_request_chat(0),
      1,
      1,
       // false, not to have infinite recursion
      instantiate_keyboard_button_poll_type(0),
       // false, not to have infinite recursion
      instantiate_web_app_info(0)
    );
  } else {
    keyboard_button = keyboard_button_create(
      "0",
      NULL,
      NULL,
      1,
      1,
      NULL,
      NULL
    );
  }

  return keyboard_button;
}


#ifdef keyboard_button_MAIN

void test_keyboard_button(int include_optional) {
    keyboard_button_t* keyboard_button_1 = instantiate_keyboard_button(include_optional);

	cJSON* jsonkeyboard_button_1 = keyboard_button_convertToJSON(keyboard_button_1);
	printf("keyboard_button :\n%s\n", cJSON_Print(jsonkeyboard_button_1));
	keyboard_button_t* keyboard_button_2 = keyboard_button_parseFromJSON(jsonkeyboard_button_1);
	cJSON* jsonkeyboard_button_2 = keyboard_button_convertToJSON(keyboard_button_2);
	printf("repeating keyboard_button:\n%s\n", cJSON_Print(jsonkeyboard_button_2));
}

int main() {
  test_keyboard_button(1);
  test_keyboard_button(0);

  printf("Hello world \n");
  return 0;
}

#endif // keyboard_button_MAIN
#endif // keyboard_button_TEST
