#ifndef keyboard_button_request_users_TEST
#define keyboard_button_request_users_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define keyboard_button_request_users_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/keyboard_button_request_users.h"
keyboard_button_request_users_t* instantiate_keyboard_button_request_users(int include_optional);



keyboard_button_request_users_t* instantiate_keyboard_button_request_users(int include_optional) {
  keyboard_button_request_users_t* keyboard_button_request_users = NULL;
  if (include_optional) {
    keyboard_button_request_users = keyboard_button_request_users_create(
      56,
      1,
      1,
      56,
      1,
      1,
      1
    );
  } else {
    keyboard_button_request_users = keyboard_button_request_users_create(
      56,
      1,
      1,
      56,
      1,
      1,
      1
    );
  }

  return keyboard_button_request_users;
}


#ifdef keyboard_button_request_users_MAIN

void test_keyboard_button_request_users(int include_optional) {
    keyboard_button_request_users_t* keyboard_button_request_users_1 = instantiate_keyboard_button_request_users(include_optional);

	cJSON* jsonkeyboard_button_request_users_1 = keyboard_button_request_users_convertToJSON(keyboard_button_request_users_1);
	printf("keyboard_button_request_users :\n%s\n", cJSON_Print(jsonkeyboard_button_request_users_1));
	keyboard_button_request_users_t* keyboard_button_request_users_2 = keyboard_button_request_users_parseFromJSON(jsonkeyboard_button_request_users_1);
	cJSON* jsonkeyboard_button_request_users_2 = keyboard_button_request_users_convertToJSON(keyboard_button_request_users_2);
	printf("repeating keyboard_button_request_users:\n%s\n", cJSON_Print(jsonkeyboard_button_request_users_2));
}

int main() {
  test_keyboard_button_request_users(1);
  test_keyboard_button_request_users(0);

  printf("Hello world \n");
  return 0;
}

#endif // keyboard_button_request_users_MAIN
#endif // keyboard_button_request_users_TEST
