#ifndef post_edit_forum_topic_request_TEST
#define post_edit_forum_topic_request_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define post_edit_forum_topic_request_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/post_edit_forum_topic_request.h"
post_edit_forum_topic_request_t* instantiate_post_edit_forum_topic_request(int include_optional);

#include "test_post_restrict_chat_member_request_chat_id.c"


post_edit_forum_topic_request_t* instantiate_post_edit_forum_topic_request(int include_optional) {
  post_edit_forum_topic_request_t* post_edit_forum_topic_request = NULL;
  if (include_optional) {
    post_edit_forum_topic_request = post_edit_forum_topic_request_create(
      null,
      56,
      "0",
      "0"
    );
  } else {
    post_edit_forum_topic_request = post_edit_forum_topic_request_create(
      null,
      56,
      "0",
      "0"
    );
  }

  return post_edit_forum_topic_request;
}


#ifdef post_edit_forum_topic_request_MAIN

void test_post_edit_forum_topic_request(int include_optional) {
    post_edit_forum_topic_request_t* post_edit_forum_topic_request_1 = instantiate_post_edit_forum_topic_request(include_optional);

	cJSON* jsonpost_edit_forum_topic_request_1 = post_edit_forum_topic_request_convertToJSON(post_edit_forum_topic_request_1);
	printf("post_edit_forum_topic_request :\n%s\n", cJSON_Print(jsonpost_edit_forum_topic_request_1));
	post_edit_forum_topic_request_t* post_edit_forum_topic_request_2 = post_edit_forum_topic_request_parseFromJSON(jsonpost_edit_forum_topic_request_1);
	cJSON* jsonpost_edit_forum_topic_request_2 = post_edit_forum_topic_request_convertToJSON(post_edit_forum_topic_request_2);
	printf("repeating post_edit_forum_topic_request:\n%s\n", cJSON_Print(jsonpost_edit_forum_topic_request_2));
}

int main() {
  test_post_edit_forum_topic_request(1);
  test_post_edit_forum_topic_request(0);

  printf("Hello world \n");
  return 0;
}

#endif // post_edit_forum_topic_request_MAIN
#endif // post_edit_forum_topic_request_TEST
