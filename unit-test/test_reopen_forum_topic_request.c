#ifndef reopen_forum_topic_request_TEST
#define reopen_forum_topic_request_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define reopen_forum_topic_request_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/reopen_forum_topic_request.h"
reopen_forum_topic_request_t* instantiate_reopen_forum_topic_request(int include_optional);

#include "test_bot_command_scope_chat_chat_id.c"


reopen_forum_topic_request_t* instantiate_reopen_forum_topic_request(int include_optional) {
  reopen_forum_topic_request_t* reopen_forum_topic_request = NULL;
  if (include_optional) {
    reopen_forum_topic_request = reopen_forum_topic_request_create(
      null,
      56
    );
  } else {
    reopen_forum_topic_request = reopen_forum_topic_request_create(
      null,
      56
    );
  }

  return reopen_forum_topic_request;
}


#ifdef reopen_forum_topic_request_MAIN

void test_reopen_forum_topic_request(int include_optional) {
    reopen_forum_topic_request_t* reopen_forum_topic_request_1 = instantiate_reopen_forum_topic_request(include_optional);

	cJSON* jsonreopen_forum_topic_request_1 = reopen_forum_topic_request_convertToJSON(reopen_forum_topic_request_1);
	printf("reopen_forum_topic_request :\n%s\n", cJSON_Print(jsonreopen_forum_topic_request_1));
	reopen_forum_topic_request_t* reopen_forum_topic_request_2 = reopen_forum_topic_request_parseFromJSON(jsonreopen_forum_topic_request_1);
	cJSON* jsonreopen_forum_topic_request_2 = reopen_forum_topic_request_convertToJSON(reopen_forum_topic_request_2);
	printf("repeating reopen_forum_topic_request:\n%s\n", cJSON_Print(jsonreopen_forum_topic_request_2));
}

int main() {
  test_reopen_forum_topic_request(1);
  test_reopen_forum_topic_request(0);

  printf("Hello world \n");
  return 0;
}

#endif // reopen_forum_topic_request_MAIN
#endif // reopen_forum_topic_request_TEST
