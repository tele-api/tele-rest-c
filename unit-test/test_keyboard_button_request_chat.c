#ifndef keyboard_button_request_chat_TEST
#define keyboard_button_request_chat_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define keyboard_button_request_chat_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/keyboard_button_request_chat.h"
keyboard_button_request_chat_t* instantiate_keyboard_button_request_chat(int include_optional);

#include "test_chat_administrator_rights.c"
#include "test_chat_administrator_rights.c"


keyboard_button_request_chat_t* instantiate_keyboard_button_request_chat(int include_optional) {
  keyboard_button_request_chat_t* keyboard_button_request_chat = NULL;
  if (include_optional) {
    keyboard_button_request_chat = keyboard_button_request_chat_create(
      56,
      1,
      1,
      1,
      1,
       // false, not to have infinite recursion
      instantiate_chat_administrator_rights(0),
       // false, not to have infinite recursion
      instantiate_chat_administrator_rights(0),
      1,
      1,
      1,
      1
    );
  } else {
    keyboard_button_request_chat = keyboard_button_request_chat_create(
      56,
      1,
      1,
      1,
      1,
      NULL,
      NULL,
      1,
      1,
      1,
      1
    );
  }

  return keyboard_button_request_chat;
}


#ifdef keyboard_button_request_chat_MAIN

void test_keyboard_button_request_chat(int include_optional) {
    keyboard_button_request_chat_t* keyboard_button_request_chat_1 = instantiate_keyboard_button_request_chat(include_optional);

	cJSON* jsonkeyboard_button_request_chat_1 = keyboard_button_request_chat_convertToJSON(keyboard_button_request_chat_1);
	printf("keyboard_button_request_chat :\n%s\n", cJSON_Print(jsonkeyboard_button_request_chat_1));
	keyboard_button_request_chat_t* keyboard_button_request_chat_2 = keyboard_button_request_chat_parseFromJSON(jsonkeyboard_button_request_chat_1);
	cJSON* jsonkeyboard_button_request_chat_2 = keyboard_button_request_chat_convertToJSON(keyboard_button_request_chat_2);
	printf("repeating keyboard_button_request_chat:\n%s\n", cJSON_Print(jsonkeyboard_button_request_chat_2));
}

int main() {
  test_keyboard_button_request_chat(1);
  test_keyboard_button_request_chat(0);

  printf("Hello world \n");
  return 0;
}

#endif // keyboard_button_request_chat_MAIN
#endif // keyboard_button_request_chat_TEST
