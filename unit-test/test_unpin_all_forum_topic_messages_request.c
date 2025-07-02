#ifndef unpin_all_forum_topic_messages_request_TEST
#define unpin_all_forum_topic_messages_request_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define unpin_all_forum_topic_messages_request_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/unpin_all_forum_topic_messages_request.h"
unpin_all_forum_topic_messages_request_t* instantiate_unpin_all_forum_topic_messages_request(int include_optional);

#include "test_bot_command_scope_chat_chat_id.c"


unpin_all_forum_topic_messages_request_t* instantiate_unpin_all_forum_topic_messages_request(int include_optional) {
  unpin_all_forum_topic_messages_request_t* unpin_all_forum_topic_messages_request = NULL;
  if (include_optional) {
    unpin_all_forum_topic_messages_request = unpin_all_forum_topic_messages_request_create(
      null,
      56
    );
  } else {
    unpin_all_forum_topic_messages_request = unpin_all_forum_topic_messages_request_create(
      null,
      56
    );
  }

  return unpin_all_forum_topic_messages_request;
}


#ifdef unpin_all_forum_topic_messages_request_MAIN

void test_unpin_all_forum_topic_messages_request(int include_optional) {
    unpin_all_forum_topic_messages_request_t* unpin_all_forum_topic_messages_request_1 = instantiate_unpin_all_forum_topic_messages_request(include_optional);

	cJSON* jsonunpin_all_forum_topic_messages_request_1 = unpin_all_forum_topic_messages_request_convertToJSON(unpin_all_forum_topic_messages_request_1);
	printf("unpin_all_forum_topic_messages_request :\n%s\n", cJSON_Print(jsonunpin_all_forum_topic_messages_request_1));
	unpin_all_forum_topic_messages_request_t* unpin_all_forum_topic_messages_request_2 = unpin_all_forum_topic_messages_request_parseFromJSON(jsonunpin_all_forum_topic_messages_request_1);
	cJSON* jsonunpin_all_forum_topic_messages_request_2 = unpin_all_forum_topic_messages_request_convertToJSON(unpin_all_forum_topic_messages_request_2);
	printf("repeating unpin_all_forum_topic_messages_request:\n%s\n", cJSON_Print(jsonunpin_all_forum_topic_messages_request_2));
}

int main() {
  test_unpin_all_forum_topic_messages_request(1);
  test_unpin_all_forum_topic_messages_request(0);

  printf("Hello world \n");
  return 0;
}

#endif // unpin_all_forum_topic_messages_request_MAIN
#endif // unpin_all_forum_topic_messages_request_TEST
