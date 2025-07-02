#ifndef hide_general_forum_topic_request_TEST
#define hide_general_forum_topic_request_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define hide_general_forum_topic_request_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/hide_general_forum_topic_request.h"
hide_general_forum_topic_request_t* instantiate_hide_general_forum_topic_request(int include_optional);

#include "test_bot_command_scope_chat_chat_id.c"


hide_general_forum_topic_request_t* instantiate_hide_general_forum_topic_request(int include_optional) {
  hide_general_forum_topic_request_t* hide_general_forum_topic_request = NULL;
  if (include_optional) {
    hide_general_forum_topic_request = hide_general_forum_topic_request_create(
      null
    );
  } else {
    hide_general_forum_topic_request = hide_general_forum_topic_request_create(
      null
    );
  }

  return hide_general_forum_topic_request;
}


#ifdef hide_general_forum_topic_request_MAIN

void test_hide_general_forum_topic_request(int include_optional) {
    hide_general_forum_topic_request_t* hide_general_forum_topic_request_1 = instantiate_hide_general_forum_topic_request(include_optional);

	cJSON* jsonhide_general_forum_topic_request_1 = hide_general_forum_topic_request_convertToJSON(hide_general_forum_topic_request_1);
	printf("hide_general_forum_topic_request :\n%s\n", cJSON_Print(jsonhide_general_forum_topic_request_1));
	hide_general_forum_topic_request_t* hide_general_forum_topic_request_2 = hide_general_forum_topic_request_parseFromJSON(jsonhide_general_forum_topic_request_1);
	cJSON* jsonhide_general_forum_topic_request_2 = hide_general_forum_topic_request_convertToJSON(hide_general_forum_topic_request_2);
	printf("repeating hide_general_forum_topic_request:\n%s\n", cJSON_Print(jsonhide_general_forum_topic_request_2));
}

int main() {
  test_hide_general_forum_topic_request(1);
  test_hide_general_forum_topic_request(0);

  printf("Hello world \n");
  return 0;
}

#endif // hide_general_forum_topic_request_MAIN
#endif // hide_general_forum_topic_request_TEST
