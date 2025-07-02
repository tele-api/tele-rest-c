#ifndef reopen_general_forum_topic_request_TEST
#define reopen_general_forum_topic_request_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define reopen_general_forum_topic_request_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/reopen_general_forum_topic_request.h"
reopen_general_forum_topic_request_t* instantiate_reopen_general_forum_topic_request(int include_optional);

#include "test_bot_command_scope_chat_chat_id.c"


reopen_general_forum_topic_request_t* instantiate_reopen_general_forum_topic_request(int include_optional) {
  reopen_general_forum_topic_request_t* reopen_general_forum_topic_request = NULL;
  if (include_optional) {
    reopen_general_forum_topic_request = reopen_general_forum_topic_request_create(
      null
    );
  } else {
    reopen_general_forum_topic_request = reopen_general_forum_topic_request_create(
      null
    );
  }

  return reopen_general_forum_topic_request;
}


#ifdef reopen_general_forum_topic_request_MAIN

void test_reopen_general_forum_topic_request(int include_optional) {
    reopen_general_forum_topic_request_t* reopen_general_forum_topic_request_1 = instantiate_reopen_general_forum_topic_request(include_optional);

	cJSON* jsonreopen_general_forum_topic_request_1 = reopen_general_forum_topic_request_convertToJSON(reopen_general_forum_topic_request_1);
	printf("reopen_general_forum_topic_request :\n%s\n", cJSON_Print(jsonreopen_general_forum_topic_request_1));
	reopen_general_forum_topic_request_t* reopen_general_forum_topic_request_2 = reopen_general_forum_topic_request_parseFromJSON(jsonreopen_general_forum_topic_request_1);
	cJSON* jsonreopen_general_forum_topic_request_2 = reopen_general_forum_topic_request_convertToJSON(reopen_general_forum_topic_request_2);
	printf("repeating reopen_general_forum_topic_request:\n%s\n", cJSON_Print(jsonreopen_general_forum_topic_request_2));
}

int main() {
  test_reopen_general_forum_topic_request(1);
  test_reopen_general_forum_topic_request(0);

  printf("Hello world \n");
  return 0;
}

#endif // reopen_general_forum_topic_request_MAIN
#endif // reopen_general_forum_topic_request_TEST
