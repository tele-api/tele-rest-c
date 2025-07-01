#ifndef _pin_chat_message_post_request_TEST
#define _pin_chat_message_post_request_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define _pin_chat_message_post_request_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/_pin_chat_message_post_request.h"
_pin_chat_message_post_request_t* instantiate__pin_chat_message_post_request(int include_optional);

#include "test__send_message_post_request_chat_id.c"


_pin_chat_message_post_request_t* instantiate__pin_chat_message_post_request(int include_optional) {
  _pin_chat_message_post_request_t* _pin_chat_message_post_request = NULL;
  if (include_optional) {
    _pin_chat_message_post_request = _pin_chat_message_post_request_create(
      null,
      56,
      "0",
      1
    );
  } else {
    _pin_chat_message_post_request = _pin_chat_message_post_request_create(
      null,
      56,
      "0",
      1
    );
  }

  return _pin_chat_message_post_request;
}


#ifdef _pin_chat_message_post_request_MAIN

void test__pin_chat_message_post_request(int include_optional) {
    _pin_chat_message_post_request_t* _pin_chat_message_post_request_1 = instantiate__pin_chat_message_post_request(include_optional);

	cJSON* json_pin_chat_message_post_request_1 = _pin_chat_message_post_request_convertToJSON(_pin_chat_message_post_request_1);
	printf("_pin_chat_message_post_request :\n%s\n", cJSON_Print(json_pin_chat_message_post_request_1));
	_pin_chat_message_post_request_t* _pin_chat_message_post_request_2 = _pin_chat_message_post_request_parseFromJSON(json_pin_chat_message_post_request_1);
	cJSON* json_pin_chat_message_post_request_2 = _pin_chat_message_post_request_convertToJSON(_pin_chat_message_post_request_2);
	printf("repeating _pin_chat_message_post_request:\n%s\n", cJSON_Print(json_pin_chat_message_post_request_2));
}

int main() {
  test__pin_chat_message_post_request(1);
  test__pin_chat_message_post_request(0);

  printf("Hello world \n");
  return 0;
}

#endif // _pin_chat_message_post_request_MAIN
#endif // _pin_chat_message_post_request_TEST
