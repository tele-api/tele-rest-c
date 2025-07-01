#ifndef inline_keyboard_button_TEST
#define inline_keyboard_button_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define inline_keyboard_button_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/inline_keyboard_button.h"
inline_keyboard_button_t* instantiate_inline_keyboard_button(int include_optional);

#include "test_web_app_info.c"
#include "test_login_url.c"
#include "test_switch_inline_query_chosen_chat.c"
#include "test_copy_text_button.c"


inline_keyboard_button_t* instantiate_inline_keyboard_button(int include_optional) {
  inline_keyboard_button_t* inline_keyboard_button = NULL;
  if (include_optional) {
    inline_keyboard_button = inline_keyboard_button_create(
      "0",
      "0",
      "0",
       // false, not to have infinite recursion
      instantiate_web_app_info(0),
       // false, not to have infinite recursion
      instantiate_login_url(0),
      "0",
      "0",
       // false, not to have infinite recursion
      instantiate_switch_inline_query_chosen_chat(0),
       // false, not to have infinite recursion
      instantiate_copy_text_button(0),
      null,
      1
    );
  } else {
    inline_keyboard_button = inline_keyboard_button_create(
      "0",
      "0",
      "0",
      NULL,
      NULL,
      "0",
      "0",
      NULL,
      NULL,
      null,
      1
    );
  }

  return inline_keyboard_button;
}


#ifdef inline_keyboard_button_MAIN

void test_inline_keyboard_button(int include_optional) {
    inline_keyboard_button_t* inline_keyboard_button_1 = instantiate_inline_keyboard_button(include_optional);

	cJSON* jsoninline_keyboard_button_1 = inline_keyboard_button_convertToJSON(inline_keyboard_button_1);
	printf("inline_keyboard_button :\n%s\n", cJSON_Print(jsoninline_keyboard_button_1));
	inline_keyboard_button_t* inline_keyboard_button_2 = inline_keyboard_button_parseFromJSON(jsoninline_keyboard_button_1);
	cJSON* jsoninline_keyboard_button_2 = inline_keyboard_button_convertToJSON(inline_keyboard_button_2);
	printf("repeating inline_keyboard_button:\n%s\n", cJSON_Print(jsoninline_keyboard_button_2));
}

int main() {
  test_inline_keyboard_button(1);
  test_inline_keyboard_button(0);

  printf("Hello world \n");
  return 0;
}

#endif // inline_keyboard_button_MAIN
#endif // inline_keyboard_button_TEST
