#ifndef reply_keyboard_markup_TEST
#define reply_keyboard_markup_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define reply_keyboard_markup_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/reply_keyboard_markup.h"
reply_keyboard_markup_t* instantiate_reply_keyboard_markup(int include_optional);



reply_keyboard_markup_t* instantiate_reply_keyboard_markup(int include_optional) {
  reply_keyboard_markup_t* reply_keyboard_markup = NULL;
  if (include_optional) {
    reply_keyboard_markup = reply_keyboard_markup_create(
      list_createList(),
      1,
      1,
      1,
      "0",
      1
    );
  } else {
    reply_keyboard_markup = reply_keyboard_markup_create(
      list_createList(),
      1,
      1,
      1,
      "0",
      1
    );
  }

  return reply_keyboard_markup;
}


#ifdef reply_keyboard_markup_MAIN

void test_reply_keyboard_markup(int include_optional) {
    reply_keyboard_markup_t* reply_keyboard_markup_1 = instantiate_reply_keyboard_markup(include_optional);

	cJSON* jsonreply_keyboard_markup_1 = reply_keyboard_markup_convertToJSON(reply_keyboard_markup_1);
	printf("reply_keyboard_markup :\n%s\n", cJSON_Print(jsonreply_keyboard_markup_1));
	reply_keyboard_markup_t* reply_keyboard_markup_2 = reply_keyboard_markup_parseFromJSON(jsonreply_keyboard_markup_1);
	cJSON* jsonreply_keyboard_markup_2 = reply_keyboard_markup_convertToJSON(reply_keyboard_markup_2);
	printf("repeating reply_keyboard_markup:\n%s\n", cJSON_Print(jsonreply_keyboard_markup_2));
}

int main() {
  test_reply_keyboard_markup(1);
  test_reply_keyboard_markup(0);

  printf("Hello world \n");
  return 0;
}

#endif // reply_keyboard_markup_MAIN
#endif // reply_keyboard_markup_TEST
