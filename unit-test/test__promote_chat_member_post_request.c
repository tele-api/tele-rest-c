#ifndef _promote_chat_member_post_request_TEST
#define _promote_chat_member_post_request_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define _promote_chat_member_post_request_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/_promote_chat_member_post_request.h"
_promote_chat_member_post_request_t* instantiate__promote_chat_member_post_request(int include_optional);

#include "test__send_message_post_request_chat_id.c"


_promote_chat_member_post_request_t* instantiate__promote_chat_member_post_request(int include_optional) {
  _promote_chat_member_post_request_t* _promote_chat_member_post_request = NULL;
  if (include_optional) {
    _promote_chat_member_post_request = _promote_chat_member_post_request_create(
      null,
      56,
      1,
      1,
      1,
      1,
      1,
      1,
      1,
      1,
      1,
      1,
      1,
      1,
      1,
      1,
      1
    );
  } else {
    _promote_chat_member_post_request = _promote_chat_member_post_request_create(
      null,
      56,
      1,
      1,
      1,
      1,
      1,
      1,
      1,
      1,
      1,
      1,
      1,
      1,
      1,
      1,
      1
    );
  }

  return _promote_chat_member_post_request;
}


#ifdef _promote_chat_member_post_request_MAIN

void test__promote_chat_member_post_request(int include_optional) {
    _promote_chat_member_post_request_t* _promote_chat_member_post_request_1 = instantiate__promote_chat_member_post_request(include_optional);

	cJSON* json_promote_chat_member_post_request_1 = _promote_chat_member_post_request_convertToJSON(_promote_chat_member_post_request_1);
	printf("_promote_chat_member_post_request :\n%s\n", cJSON_Print(json_promote_chat_member_post_request_1));
	_promote_chat_member_post_request_t* _promote_chat_member_post_request_2 = _promote_chat_member_post_request_parseFromJSON(json_promote_chat_member_post_request_1);
	cJSON* json_promote_chat_member_post_request_2 = _promote_chat_member_post_request_convertToJSON(_promote_chat_member_post_request_2);
	printf("repeating _promote_chat_member_post_request:\n%s\n", cJSON_Print(json_promote_chat_member_post_request_2));
}

int main() {
  test__promote_chat_member_post_request(1);
  test__promote_chat_member_post_request(0);

  printf("Hello world \n");
  return 0;
}

#endif // _promote_chat_member_post_request_MAIN
#endif // _promote_chat_member_post_request_TEST
