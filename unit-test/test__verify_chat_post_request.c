#ifndef _verify_chat_post_request_TEST
#define _verify_chat_post_request_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define _verify_chat_post_request_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/_verify_chat_post_request.h"
_verify_chat_post_request_t* instantiate__verify_chat_post_request(int include_optional);

#include "test__send_message_post_request_chat_id.c"


_verify_chat_post_request_t* instantiate__verify_chat_post_request(int include_optional) {
  _verify_chat_post_request_t* _verify_chat_post_request = NULL;
  if (include_optional) {
    _verify_chat_post_request = _verify_chat_post_request_create(
      null,
      "0"
    );
  } else {
    _verify_chat_post_request = _verify_chat_post_request_create(
      null,
      "0"
    );
  }

  return _verify_chat_post_request;
}


#ifdef _verify_chat_post_request_MAIN

void test__verify_chat_post_request(int include_optional) {
    _verify_chat_post_request_t* _verify_chat_post_request_1 = instantiate__verify_chat_post_request(include_optional);

	cJSON* json_verify_chat_post_request_1 = _verify_chat_post_request_convertToJSON(_verify_chat_post_request_1);
	printf("_verify_chat_post_request :\n%s\n", cJSON_Print(json_verify_chat_post_request_1));
	_verify_chat_post_request_t* _verify_chat_post_request_2 = _verify_chat_post_request_parseFromJSON(json_verify_chat_post_request_1);
	cJSON* json_verify_chat_post_request_2 = _verify_chat_post_request_convertToJSON(_verify_chat_post_request_2);
	printf("repeating _verify_chat_post_request:\n%s\n", cJSON_Print(json_verify_chat_post_request_2));
}

int main() {
  test__verify_chat_post_request(1);
  test__verify_chat_post_request(0);

  printf("Hello world \n");
  return 0;
}

#endif // _verify_chat_post_request_MAIN
#endif // _verify_chat_post_request_TEST
