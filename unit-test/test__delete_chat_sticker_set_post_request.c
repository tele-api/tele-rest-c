#ifndef _delete_chat_sticker_set_post_request_TEST
#define _delete_chat_sticker_set_post_request_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define _delete_chat_sticker_set_post_request_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/_delete_chat_sticker_set_post_request.h"
_delete_chat_sticker_set_post_request_t* instantiate__delete_chat_sticker_set_post_request(int include_optional);

#include "test__restrict_chat_member_post_request_chat_id.c"


_delete_chat_sticker_set_post_request_t* instantiate__delete_chat_sticker_set_post_request(int include_optional) {
  _delete_chat_sticker_set_post_request_t* _delete_chat_sticker_set_post_request = NULL;
  if (include_optional) {
    _delete_chat_sticker_set_post_request = _delete_chat_sticker_set_post_request_create(
      null
    );
  } else {
    _delete_chat_sticker_set_post_request = _delete_chat_sticker_set_post_request_create(
      null
    );
  }

  return _delete_chat_sticker_set_post_request;
}


#ifdef _delete_chat_sticker_set_post_request_MAIN

void test__delete_chat_sticker_set_post_request(int include_optional) {
    _delete_chat_sticker_set_post_request_t* _delete_chat_sticker_set_post_request_1 = instantiate__delete_chat_sticker_set_post_request(include_optional);

	cJSON* json_delete_chat_sticker_set_post_request_1 = _delete_chat_sticker_set_post_request_convertToJSON(_delete_chat_sticker_set_post_request_1);
	printf("_delete_chat_sticker_set_post_request :\n%s\n", cJSON_Print(json_delete_chat_sticker_set_post_request_1));
	_delete_chat_sticker_set_post_request_t* _delete_chat_sticker_set_post_request_2 = _delete_chat_sticker_set_post_request_parseFromJSON(json_delete_chat_sticker_set_post_request_1);
	cJSON* json_delete_chat_sticker_set_post_request_2 = _delete_chat_sticker_set_post_request_convertToJSON(_delete_chat_sticker_set_post_request_2);
	printf("repeating _delete_chat_sticker_set_post_request:\n%s\n", cJSON_Print(json_delete_chat_sticker_set_post_request_2));
}

int main() {
  test__delete_chat_sticker_set_post_request(1);
  test__delete_chat_sticker_set_post_request(0);

  printf("Hello world \n");
  return 0;
}

#endif // _delete_chat_sticker_set_post_request_MAIN
#endif // _delete_chat_sticker_set_post_request_TEST
