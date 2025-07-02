#ifndef edit_general_forum_topic_request_TEST
#define edit_general_forum_topic_request_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define edit_general_forum_topic_request_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/edit_general_forum_topic_request.h"
edit_general_forum_topic_request_t* instantiate_edit_general_forum_topic_request(int include_optional);

#include "test_bot_command_scope_chat_chat_id.c"


edit_general_forum_topic_request_t* instantiate_edit_general_forum_topic_request(int include_optional) {
  edit_general_forum_topic_request_t* edit_general_forum_topic_request = NULL;
  if (include_optional) {
    edit_general_forum_topic_request = edit_general_forum_topic_request_create(
      null,
      "0"
    );
  } else {
    edit_general_forum_topic_request = edit_general_forum_topic_request_create(
      null,
      "0"
    );
  }

  return edit_general_forum_topic_request;
}


#ifdef edit_general_forum_topic_request_MAIN

void test_edit_general_forum_topic_request(int include_optional) {
    edit_general_forum_topic_request_t* edit_general_forum_topic_request_1 = instantiate_edit_general_forum_topic_request(include_optional);

	cJSON* jsonedit_general_forum_topic_request_1 = edit_general_forum_topic_request_convertToJSON(edit_general_forum_topic_request_1);
	printf("edit_general_forum_topic_request :\n%s\n", cJSON_Print(jsonedit_general_forum_topic_request_1));
	edit_general_forum_topic_request_t* edit_general_forum_topic_request_2 = edit_general_forum_topic_request_parseFromJSON(jsonedit_general_forum_topic_request_1);
	cJSON* jsonedit_general_forum_topic_request_2 = edit_general_forum_topic_request_convertToJSON(edit_general_forum_topic_request_2);
	printf("repeating edit_general_forum_topic_request:\n%s\n", cJSON_Print(jsonedit_general_forum_topic_request_2));
}

int main() {
  test_edit_general_forum_topic_request(1);
  test_edit_general_forum_topic_request(0);

  printf("Hello world \n");
  return 0;
}

#endif // edit_general_forum_topic_request_MAIN
#endif // edit_general_forum_topic_request_TEST
