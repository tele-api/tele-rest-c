#ifndef _forward_message_post_request_TEST
#define _forward_message_post_request_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define _forward_message_post_request_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/_forward_message_post_request.h"
_forward_message_post_request_t* instantiate__forward_message_post_request(int include_optional);

#include "test__send_message_post_request_chat_id.c"
#include "test__forward_message_post_request_from_chat_id.c"


_forward_message_post_request_t* instantiate__forward_message_post_request(int include_optional) {
  _forward_message_post_request_t* _forward_message_post_request = NULL;
  if (include_optional) {
    _forward_message_post_request = _forward_message_post_request_create(
      null,
      null,
      56,
      56,
      56,
      1,
      1
    );
  } else {
    _forward_message_post_request = _forward_message_post_request_create(
      null,
      null,
      56,
      56,
      56,
      1,
      1
    );
  }

  return _forward_message_post_request;
}


#ifdef _forward_message_post_request_MAIN

void test__forward_message_post_request(int include_optional) {
    _forward_message_post_request_t* _forward_message_post_request_1 = instantiate__forward_message_post_request(include_optional);

	cJSON* json_forward_message_post_request_1 = _forward_message_post_request_convertToJSON(_forward_message_post_request_1);
	printf("_forward_message_post_request :\n%s\n", cJSON_Print(json_forward_message_post_request_1));
	_forward_message_post_request_t* _forward_message_post_request_2 = _forward_message_post_request_parseFromJSON(json_forward_message_post_request_1);
	cJSON* json_forward_message_post_request_2 = _forward_message_post_request_convertToJSON(_forward_message_post_request_2);
	printf("repeating _forward_message_post_request:\n%s\n", cJSON_Print(json_forward_message_post_request_2));
}

int main() {
  test__forward_message_post_request(1);
  test__forward_message_post_request(0);

  printf("Hello world \n");
  return 0;
}

#endif // _forward_message_post_request_MAIN
#endif // _forward_message_post_request_TEST
