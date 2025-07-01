#ifndef _stop_poll_post_request_TEST
#define _stop_poll_post_request_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define _stop_poll_post_request_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/_stop_poll_post_request.h"
_stop_poll_post_request_t* instantiate__stop_poll_post_request(int include_optional);

#include "test__send_message_post_request_chat_id.c"
#include "test_inline_keyboard_markup.c"


_stop_poll_post_request_t* instantiate__stop_poll_post_request(int include_optional) {
  _stop_poll_post_request_t* _stop_poll_post_request = NULL;
  if (include_optional) {
    _stop_poll_post_request = _stop_poll_post_request_create(
      null,
      56,
      "0",
       // false, not to have infinite recursion
      instantiate_inline_keyboard_markup(0)
    );
  } else {
    _stop_poll_post_request = _stop_poll_post_request_create(
      null,
      56,
      "0",
      NULL
    );
  }

  return _stop_poll_post_request;
}


#ifdef _stop_poll_post_request_MAIN

void test__stop_poll_post_request(int include_optional) {
    _stop_poll_post_request_t* _stop_poll_post_request_1 = instantiate__stop_poll_post_request(include_optional);

	cJSON* json_stop_poll_post_request_1 = _stop_poll_post_request_convertToJSON(_stop_poll_post_request_1);
	printf("_stop_poll_post_request :\n%s\n", cJSON_Print(json_stop_poll_post_request_1));
	_stop_poll_post_request_t* _stop_poll_post_request_2 = _stop_poll_post_request_parseFromJSON(json_stop_poll_post_request_1);
	cJSON* json_stop_poll_post_request_2 = _stop_poll_post_request_convertToJSON(_stop_poll_post_request_2);
	printf("repeating _stop_poll_post_request:\n%s\n", cJSON_Print(json_stop_poll_post_request_2));
}

int main() {
  test__stop_poll_post_request(1);
  test__stop_poll_post_request(0);

  printf("Hello world \n");
  return 0;
}

#endif // _stop_poll_post_request_MAIN
#endif // _stop_poll_post_request_TEST
