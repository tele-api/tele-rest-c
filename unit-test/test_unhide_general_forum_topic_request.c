#ifndef unhide_general_forum_topic_request_TEST
#define unhide_general_forum_topic_request_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define unhide_general_forum_topic_request_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/unhide_general_forum_topic_request.h"
unhide_general_forum_topic_request_t* instantiate_unhide_general_forum_topic_request(int include_optional);

#include "test_bot_command_scope_chat_chat_id.c"


unhide_general_forum_topic_request_t* instantiate_unhide_general_forum_topic_request(int include_optional) {
  unhide_general_forum_topic_request_t* unhide_general_forum_topic_request = NULL;
  if (include_optional) {
    unhide_general_forum_topic_request = unhide_general_forum_topic_request_create(
      null
    );
  } else {
    unhide_general_forum_topic_request = unhide_general_forum_topic_request_create(
      null
    );
  }

  return unhide_general_forum_topic_request;
}


#ifdef unhide_general_forum_topic_request_MAIN

void test_unhide_general_forum_topic_request(int include_optional) {
    unhide_general_forum_topic_request_t* unhide_general_forum_topic_request_1 = instantiate_unhide_general_forum_topic_request(include_optional);

	cJSON* jsonunhide_general_forum_topic_request_1 = unhide_general_forum_topic_request_convertToJSON(unhide_general_forum_topic_request_1);
	printf("unhide_general_forum_topic_request :\n%s\n", cJSON_Print(jsonunhide_general_forum_topic_request_1));
	unhide_general_forum_topic_request_t* unhide_general_forum_topic_request_2 = unhide_general_forum_topic_request_parseFromJSON(jsonunhide_general_forum_topic_request_1);
	cJSON* jsonunhide_general_forum_topic_request_2 = unhide_general_forum_topic_request_convertToJSON(unhide_general_forum_topic_request_2);
	printf("repeating unhide_general_forum_topic_request:\n%s\n", cJSON_Print(jsonunhide_general_forum_topic_request_2));
}

int main() {
  test_unhide_general_forum_topic_request(1);
  test_unhide_general_forum_topic_request(0);

  printf("Hello world \n");
  return 0;
}

#endif // unhide_general_forum_topic_request_MAIN
#endif // unhide_general_forum_topic_request_TEST
