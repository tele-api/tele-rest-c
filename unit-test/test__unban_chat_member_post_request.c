#ifndef _unban_chat_member_post_request_TEST
#define _unban_chat_member_post_request_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define _unban_chat_member_post_request_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/_unban_chat_member_post_request.h"
_unban_chat_member_post_request_t* instantiate__unban_chat_member_post_request(int include_optional);

#include "test__ban_chat_member_post_request_chat_id.c"


_unban_chat_member_post_request_t* instantiate__unban_chat_member_post_request(int include_optional) {
  _unban_chat_member_post_request_t* _unban_chat_member_post_request = NULL;
  if (include_optional) {
    _unban_chat_member_post_request = _unban_chat_member_post_request_create(
      null,
      56,
      1
    );
  } else {
    _unban_chat_member_post_request = _unban_chat_member_post_request_create(
      null,
      56,
      1
    );
  }

  return _unban_chat_member_post_request;
}


#ifdef _unban_chat_member_post_request_MAIN

void test__unban_chat_member_post_request(int include_optional) {
    _unban_chat_member_post_request_t* _unban_chat_member_post_request_1 = instantiate__unban_chat_member_post_request(include_optional);

	cJSON* json_unban_chat_member_post_request_1 = _unban_chat_member_post_request_convertToJSON(_unban_chat_member_post_request_1);
	printf("_unban_chat_member_post_request :\n%s\n", cJSON_Print(json_unban_chat_member_post_request_1));
	_unban_chat_member_post_request_t* _unban_chat_member_post_request_2 = _unban_chat_member_post_request_parseFromJSON(json_unban_chat_member_post_request_1);
	cJSON* json_unban_chat_member_post_request_2 = _unban_chat_member_post_request_convertToJSON(_unban_chat_member_post_request_2);
	printf("repeating _unban_chat_member_post_request:\n%s\n", cJSON_Print(json_unban_chat_member_post_request_2));
}

int main() {
  test__unban_chat_member_post_request(1);
  test__unban_chat_member_post_request(0);

  printf("Hello world \n");
  return 0;
}

#endif // _unban_chat_member_post_request_MAIN
#endif // _unban_chat_member_post_request_TEST
