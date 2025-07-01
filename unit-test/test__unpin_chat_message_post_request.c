#ifndef _unpin_chat_message_post_request_TEST
#define _unpin_chat_message_post_request_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define _unpin_chat_message_post_request_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/_unpin_chat_message_post_request.h"
_unpin_chat_message_post_request_t* instantiate__unpin_chat_message_post_request(int include_optional);

#include "test__send_message_post_request_chat_id.c"


_unpin_chat_message_post_request_t* instantiate__unpin_chat_message_post_request(int include_optional) {
  _unpin_chat_message_post_request_t* _unpin_chat_message_post_request = NULL;
  if (include_optional) {
    _unpin_chat_message_post_request = _unpin_chat_message_post_request_create(
      null,
      "0",
      56
    );
  } else {
    _unpin_chat_message_post_request = _unpin_chat_message_post_request_create(
      null,
      "0",
      56
    );
  }

  return _unpin_chat_message_post_request;
}


#ifdef _unpin_chat_message_post_request_MAIN

void test__unpin_chat_message_post_request(int include_optional) {
    _unpin_chat_message_post_request_t* _unpin_chat_message_post_request_1 = instantiate__unpin_chat_message_post_request(include_optional);

	cJSON* json_unpin_chat_message_post_request_1 = _unpin_chat_message_post_request_convertToJSON(_unpin_chat_message_post_request_1);
	printf("_unpin_chat_message_post_request :\n%s\n", cJSON_Print(json_unpin_chat_message_post_request_1));
	_unpin_chat_message_post_request_t* _unpin_chat_message_post_request_2 = _unpin_chat_message_post_request_parseFromJSON(json_unpin_chat_message_post_request_1);
	cJSON* json_unpin_chat_message_post_request_2 = _unpin_chat_message_post_request_convertToJSON(_unpin_chat_message_post_request_2);
	printf("repeating _unpin_chat_message_post_request:\n%s\n", cJSON_Print(json_unpin_chat_message_post_request_2));
}

int main() {
  test__unpin_chat_message_post_request(1);
  test__unpin_chat_message_post_request(0);

  printf("Hello world \n");
  return 0;
}

#endif // _unpin_chat_message_post_request_MAIN
#endif // _unpin_chat_message_post_request_TEST
