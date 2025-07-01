#ifndef _send_gift_post_request_TEST
#define _send_gift_post_request_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define _send_gift_post_request_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/_send_gift_post_request.h"
_send_gift_post_request_t* instantiate__send_gift_post_request(int include_optional);

#include "test__send_gift_post_request_chat_id.c"


_send_gift_post_request_t* instantiate__send_gift_post_request(int include_optional) {
  _send_gift_post_request_t* _send_gift_post_request = NULL;
  if (include_optional) {
    _send_gift_post_request = _send_gift_post_request_create(
      "0",
      56,
      null,
      1,
      "0",
      "0",
      list_createList()
    );
  } else {
    _send_gift_post_request = _send_gift_post_request_create(
      "0",
      56,
      null,
      1,
      "0",
      "0",
      list_createList()
    );
  }

  return _send_gift_post_request;
}


#ifdef _send_gift_post_request_MAIN

void test__send_gift_post_request(int include_optional) {
    _send_gift_post_request_t* _send_gift_post_request_1 = instantiate__send_gift_post_request(include_optional);

	cJSON* json_send_gift_post_request_1 = _send_gift_post_request_convertToJSON(_send_gift_post_request_1);
	printf("_send_gift_post_request :\n%s\n", cJSON_Print(json_send_gift_post_request_1));
	_send_gift_post_request_t* _send_gift_post_request_2 = _send_gift_post_request_parseFromJSON(json_send_gift_post_request_1);
	cJSON* json_send_gift_post_request_2 = _send_gift_post_request_convertToJSON(_send_gift_post_request_2);
	printf("repeating _send_gift_post_request:\n%s\n", cJSON_Print(json_send_gift_post_request_2));
}

int main() {
  test__send_gift_post_request(1);
  test__send_gift_post_request(0);

  printf("Hello world \n");
  return 0;
}

#endif // _send_gift_post_request_MAIN
#endif // _send_gift_post_request_TEST
