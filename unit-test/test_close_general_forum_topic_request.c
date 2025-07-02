#ifndef close_general_forum_topic_request_TEST
#define close_general_forum_topic_request_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define close_general_forum_topic_request_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/close_general_forum_topic_request.h"
close_general_forum_topic_request_t* instantiate_close_general_forum_topic_request(int include_optional);

#include "test_bot_command_scope_chat_chat_id.c"


close_general_forum_topic_request_t* instantiate_close_general_forum_topic_request(int include_optional) {
  close_general_forum_topic_request_t* close_general_forum_topic_request = NULL;
  if (include_optional) {
    close_general_forum_topic_request = close_general_forum_topic_request_create(
      null
    );
  } else {
    close_general_forum_topic_request = close_general_forum_topic_request_create(
      null
    );
  }

  return close_general_forum_topic_request;
}


#ifdef close_general_forum_topic_request_MAIN

void test_close_general_forum_topic_request(int include_optional) {
    close_general_forum_topic_request_t* close_general_forum_topic_request_1 = instantiate_close_general_forum_topic_request(include_optional);

	cJSON* jsonclose_general_forum_topic_request_1 = close_general_forum_topic_request_convertToJSON(close_general_forum_topic_request_1);
	printf("close_general_forum_topic_request :\n%s\n", cJSON_Print(jsonclose_general_forum_topic_request_1));
	close_general_forum_topic_request_t* close_general_forum_topic_request_2 = close_general_forum_topic_request_parseFromJSON(jsonclose_general_forum_topic_request_1);
	cJSON* jsonclose_general_forum_topic_request_2 = close_general_forum_topic_request_convertToJSON(close_general_forum_topic_request_2);
	printf("repeating close_general_forum_topic_request:\n%s\n", cJSON_Print(jsonclose_general_forum_topic_request_2));
}

int main() {
  test_close_general_forum_topic_request(1);
  test_close_general_forum_topic_request(0);

  printf("Hello world \n");
  return 0;
}

#endif // close_general_forum_topic_request_MAIN
#endif // close_general_forum_topic_request_TEST
