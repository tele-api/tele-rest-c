#ifndef _edit_forum_topic_post_request_TEST
#define _edit_forum_topic_post_request_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define _edit_forum_topic_post_request_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/_edit_forum_topic_post_request.h"
_edit_forum_topic_post_request_t* instantiate__edit_forum_topic_post_request(int include_optional);

#include "test__restrict_chat_member_post_request_chat_id.c"


_edit_forum_topic_post_request_t* instantiate__edit_forum_topic_post_request(int include_optional) {
  _edit_forum_topic_post_request_t* _edit_forum_topic_post_request = NULL;
  if (include_optional) {
    _edit_forum_topic_post_request = _edit_forum_topic_post_request_create(
      null,
      56,
      "0",
      "0"
    );
  } else {
    _edit_forum_topic_post_request = _edit_forum_topic_post_request_create(
      null,
      56,
      "0",
      "0"
    );
  }

  return _edit_forum_topic_post_request;
}


#ifdef _edit_forum_topic_post_request_MAIN

void test__edit_forum_topic_post_request(int include_optional) {
    _edit_forum_topic_post_request_t* _edit_forum_topic_post_request_1 = instantiate__edit_forum_topic_post_request(include_optional);

	cJSON* json_edit_forum_topic_post_request_1 = _edit_forum_topic_post_request_convertToJSON(_edit_forum_topic_post_request_1);
	printf("_edit_forum_topic_post_request :\n%s\n", cJSON_Print(json_edit_forum_topic_post_request_1));
	_edit_forum_topic_post_request_t* _edit_forum_topic_post_request_2 = _edit_forum_topic_post_request_parseFromJSON(json_edit_forum_topic_post_request_1);
	cJSON* json_edit_forum_topic_post_request_2 = _edit_forum_topic_post_request_convertToJSON(_edit_forum_topic_post_request_2);
	printf("repeating _edit_forum_topic_post_request:\n%s\n", cJSON_Print(json_edit_forum_topic_post_request_2));
}

int main() {
  test__edit_forum_topic_post_request(1);
  test__edit_forum_topic_post_request(0);

  printf("Hello world \n");
  return 0;
}

#endif // _edit_forum_topic_post_request_MAIN
#endif // _edit_forum_topic_post_request_TEST
