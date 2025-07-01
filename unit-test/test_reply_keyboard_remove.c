#ifndef reply_keyboard_remove_TEST
#define reply_keyboard_remove_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define reply_keyboard_remove_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/reply_keyboard_remove.h"
reply_keyboard_remove_t* instantiate_reply_keyboard_remove(int include_optional);



reply_keyboard_remove_t* instantiate_reply_keyboard_remove(int include_optional) {
  reply_keyboard_remove_t* reply_keyboard_remove = NULL;
  if (include_optional) {
    reply_keyboard_remove = reply_keyboard_remove_create(
      1,
      1
    );
  } else {
    reply_keyboard_remove = reply_keyboard_remove_create(
      1,
      1
    );
  }

  return reply_keyboard_remove;
}


#ifdef reply_keyboard_remove_MAIN

void test_reply_keyboard_remove(int include_optional) {
    reply_keyboard_remove_t* reply_keyboard_remove_1 = instantiate_reply_keyboard_remove(include_optional);

	cJSON* jsonreply_keyboard_remove_1 = reply_keyboard_remove_convertToJSON(reply_keyboard_remove_1);
	printf("reply_keyboard_remove :\n%s\n", cJSON_Print(jsonreply_keyboard_remove_1));
	reply_keyboard_remove_t* reply_keyboard_remove_2 = reply_keyboard_remove_parseFromJSON(jsonreply_keyboard_remove_1);
	cJSON* jsonreply_keyboard_remove_2 = reply_keyboard_remove_convertToJSON(reply_keyboard_remove_2);
	printf("repeating reply_keyboard_remove:\n%s\n", cJSON_Print(jsonreply_keyboard_remove_2));
}

int main() {
  test_reply_keyboard_remove(1);
  test_reply_keyboard_remove(0);

  printf("Hello world \n");
  return 0;
}

#endif // reply_keyboard_remove_MAIN
#endif // reply_keyboard_remove_TEST
