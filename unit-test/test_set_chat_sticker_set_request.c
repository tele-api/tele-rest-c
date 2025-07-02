#ifndef set_chat_sticker_set_request_TEST
#define set_chat_sticker_set_request_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define set_chat_sticker_set_request_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/set_chat_sticker_set_request.h"
set_chat_sticker_set_request_t* instantiate_set_chat_sticker_set_request(int include_optional);

#include "test_bot_command_scope_chat_chat_id.c"


set_chat_sticker_set_request_t* instantiate_set_chat_sticker_set_request(int include_optional) {
  set_chat_sticker_set_request_t* set_chat_sticker_set_request = NULL;
  if (include_optional) {
    set_chat_sticker_set_request = set_chat_sticker_set_request_create(
      null,
      "0"
    );
  } else {
    set_chat_sticker_set_request = set_chat_sticker_set_request_create(
      null,
      "0"
    );
  }

  return set_chat_sticker_set_request;
}


#ifdef set_chat_sticker_set_request_MAIN

void test_set_chat_sticker_set_request(int include_optional) {
    set_chat_sticker_set_request_t* set_chat_sticker_set_request_1 = instantiate_set_chat_sticker_set_request(include_optional);

	cJSON* jsonset_chat_sticker_set_request_1 = set_chat_sticker_set_request_convertToJSON(set_chat_sticker_set_request_1);
	printf("set_chat_sticker_set_request :\n%s\n", cJSON_Print(jsonset_chat_sticker_set_request_1));
	set_chat_sticker_set_request_t* set_chat_sticker_set_request_2 = set_chat_sticker_set_request_parseFromJSON(jsonset_chat_sticker_set_request_1);
	cJSON* jsonset_chat_sticker_set_request_2 = set_chat_sticker_set_request_convertToJSON(set_chat_sticker_set_request_2);
	printf("repeating set_chat_sticker_set_request:\n%s\n", cJSON_Print(jsonset_chat_sticker_set_request_2));
}

int main() {
  test_set_chat_sticker_set_request(1);
  test_set_chat_sticker_set_request(0);

  printf("Hello world \n");
  return 0;
}

#endif // set_chat_sticker_set_request_MAIN
#endif // set_chat_sticker_set_request_TEST
