#ifndef delete_chat_sticker_set_request_TEST
#define delete_chat_sticker_set_request_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define delete_chat_sticker_set_request_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/delete_chat_sticker_set_request.h"
delete_chat_sticker_set_request_t* instantiate_delete_chat_sticker_set_request(int include_optional);

#include "test_bot_command_scope_chat_chat_id.c"


delete_chat_sticker_set_request_t* instantiate_delete_chat_sticker_set_request(int include_optional) {
  delete_chat_sticker_set_request_t* delete_chat_sticker_set_request = NULL;
  if (include_optional) {
    delete_chat_sticker_set_request = delete_chat_sticker_set_request_create(
      null
    );
  } else {
    delete_chat_sticker_set_request = delete_chat_sticker_set_request_create(
      null
    );
  }

  return delete_chat_sticker_set_request;
}


#ifdef delete_chat_sticker_set_request_MAIN

void test_delete_chat_sticker_set_request(int include_optional) {
    delete_chat_sticker_set_request_t* delete_chat_sticker_set_request_1 = instantiate_delete_chat_sticker_set_request(include_optional);

	cJSON* jsondelete_chat_sticker_set_request_1 = delete_chat_sticker_set_request_convertToJSON(delete_chat_sticker_set_request_1);
	printf("delete_chat_sticker_set_request :\n%s\n", cJSON_Print(jsondelete_chat_sticker_set_request_1));
	delete_chat_sticker_set_request_t* delete_chat_sticker_set_request_2 = delete_chat_sticker_set_request_parseFromJSON(jsondelete_chat_sticker_set_request_1);
	cJSON* jsondelete_chat_sticker_set_request_2 = delete_chat_sticker_set_request_convertToJSON(delete_chat_sticker_set_request_2);
	printf("repeating delete_chat_sticker_set_request:\n%s\n", cJSON_Print(jsondelete_chat_sticker_set_request_2));
}

int main() {
  test_delete_chat_sticker_set_request(1);
  test_delete_chat_sticker_set_request(0);

  printf("Hello world \n");
  return 0;
}

#endif // delete_chat_sticker_set_request_MAIN
#endif // delete_chat_sticker_set_request_TEST
