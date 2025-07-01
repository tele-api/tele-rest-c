#ifndef _copy_messages_post_request_TEST
#define _copy_messages_post_request_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define _copy_messages_post_request_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/_copy_messages_post_request.h"
_copy_messages_post_request_t* instantiate__copy_messages_post_request(int include_optional);

#include "test__send_message_post_request_chat_id.c"
#include "test__forward_messages_post_request_from_chat_id.c"


_copy_messages_post_request_t* instantiate__copy_messages_post_request(int include_optional) {
  _copy_messages_post_request_t* _copy_messages_post_request = NULL;
  if (include_optional) {
    _copy_messages_post_request = _copy_messages_post_request_create(
      null,
      null,
      list_createList(),
      56,
      1,
      1,
      1
    );
  } else {
    _copy_messages_post_request = _copy_messages_post_request_create(
      null,
      null,
      list_createList(),
      56,
      1,
      1,
      1
    );
  }

  return _copy_messages_post_request;
}


#ifdef _copy_messages_post_request_MAIN

void test__copy_messages_post_request(int include_optional) {
    _copy_messages_post_request_t* _copy_messages_post_request_1 = instantiate__copy_messages_post_request(include_optional);

	cJSON* json_copy_messages_post_request_1 = _copy_messages_post_request_convertToJSON(_copy_messages_post_request_1);
	printf("_copy_messages_post_request :\n%s\n", cJSON_Print(json_copy_messages_post_request_1));
	_copy_messages_post_request_t* _copy_messages_post_request_2 = _copy_messages_post_request_parseFromJSON(json_copy_messages_post_request_1);
	cJSON* json_copy_messages_post_request_2 = _copy_messages_post_request_convertToJSON(_copy_messages_post_request_2);
	printf("repeating _copy_messages_post_request:\n%s\n", cJSON_Print(json_copy_messages_post_request_2));
}

int main() {
  test__copy_messages_post_request(1);
  test__copy_messages_post_request(0);

  printf("Hello world \n");
  return 0;
}

#endif // _copy_messages_post_request_MAIN
#endif // _copy_messages_post_request_TEST
