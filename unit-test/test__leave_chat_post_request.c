#ifndef _leave_chat_post_request_TEST
#define _leave_chat_post_request_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define _leave_chat_post_request_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/_leave_chat_post_request.h"
_leave_chat_post_request_t* instantiate__leave_chat_post_request(int include_optional);

#include "test__leave_chat_post_request_chat_id.c"


_leave_chat_post_request_t* instantiate__leave_chat_post_request(int include_optional) {
  _leave_chat_post_request_t* _leave_chat_post_request = NULL;
  if (include_optional) {
    _leave_chat_post_request = _leave_chat_post_request_create(
      null
    );
  } else {
    _leave_chat_post_request = _leave_chat_post_request_create(
      null
    );
  }

  return _leave_chat_post_request;
}


#ifdef _leave_chat_post_request_MAIN

void test__leave_chat_post_request(int include_optional) {
    _leave_chat_post_request_t* _leave_chat_post_request_1 = instantiate__leave_chat_post_request(include_optional);

	cJSON* json_leave_chat_post_request_1 = _leave_chat_post_request_convertToJSON(_leave_chat_post_request_1);
	printf("_leave_chat_post_request :\n%s\n", cJSON_Print(json_leave_chat_post_request_1));
	_leave_chat_post_request_t* _leave_chat_post_request_2 = _leave_chat_post_request_parseFromJSON(json_leave_chat_post_request_1);
	cJSON* json_leave_chat_post_request_2 = _leave_chat_post_request_convertToJSON(_leave_chat_post_request_2);
	printf("repeating _leave_chat_post_request:\n%s\n", cJSON_Print(json_leave_chat_post_request_2));
}

int main() {
  test__leave_chat_post_request(1);
  test__leave_chat_post_request(0);

  printf("Hello world \n");
  return 0;
}

#endif // _leave_chat_post_request_MAIN
#endif // _leave_chat_post_request_TEST
