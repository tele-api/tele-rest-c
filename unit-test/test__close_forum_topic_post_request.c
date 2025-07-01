#ifndef _close_forum_topic_post_request_TEST
#define _close_forum_topic_post_request_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define _close_forum_topic_post_request_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/_close_forum_topic_post_request.h"
_close_forum_topic_post_request_t* instantiate__close_forum_topic_post_request(int include_optional);

#include "test__restrict_chat_member_post_request_chat_id.c"


_close_forum_topic_post_request_t* instantiate__close_forum_topic_post_request(int include_optional) {
  _close_forum_topic_post_request_t* _close_forum_topic_post_request = NULL;
  if (include_optional) {
    _close_forum_topic_post_request = _close_forum_topic_post_request_create(
      null,
      56
    );
  } else {
    _close_forum_topic_post_request = _close_forum_topic_post_request_create(
      null,
      56
    );
  }

  return _close_forum_topic_post_request;
}


#ifdef _close_forum_topic_post_request_MAIN

void test__close_forum_topic_post_request(int include_optional) {
    _close_forum_topic_post_request_t* _close_forum_topic_post_request_1 = instantiate__close_forum_topic_post_request(include_optional);

	cJSON* json_close_forum_topic_post_request_1 = _close_forum_topic_post_request_convertToJSON(_close_forum_topic_post_request_1);
	printf("_close_forum_topic_post_request :\n%s\n", cJSON_Print(json_close_forum_topic_post_request_1));
	_close_forum_topic_post_request_t* _close_forum_topic_post_request_2 = _close_forum_topic_post_request_parseFromJSON(json_close_forum_topic_post_request_1);
	cJSON* json_close_forum_topic_post_request_2 = _close_forum_topic_post_request_convertToJSON(_close_forum_topic_post_request_2);
	printf("repeating _close_forum_topic_post_request:\n%s\n", cJSON_Print(json_close_forum_topic_post_request_2));
}

int main() {
  test__close_forum_topic_post_request(1);
  test__close_forum_topic_post_request(0);

  printf("Hello world \n");
  return 0;
}

#endif // _close_forum_topic_post_request_MAIN
#endif // _close_forum_topic_post_request_TEST
