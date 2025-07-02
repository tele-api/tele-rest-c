#ifndef delete_forum_topic_request_TEST
#define delete_forum_topic_request_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define delete_forum_topic_request_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/delete_forum_topic_request.h"
delete_forum_topic_request_t* instantiate_delete_forum_topic_request(int include_optional);

#include "test_bot_command_scope_chat_chat_id.c"


delete_forum_topic_request_t* instantiate_delete_forum_topic_request(int include_optional) {
  delete_forum_topic_request_t* delete_forum_topic_request = NULL;
  if (include_optional) {
    delete_forum_topic_request = delete_forum_topic_request_create(
      null,
      56
    );
  } else {
    delete_forum_topic_request = delete_forum_topic_request_create(
      null,
      56
    );
  }

  return delete_forum_topic_request;
}


#ifdef delete_forum_topic_request_MAIN

void test_delete_forum_topic_request(int include_optional) {
    delete_forum_topic_request_t* delete_forum_topic_request_1 = instantiate_delete_forum_topic_request(include_optional);

	cJSON* jsondelete_forum_topic_request_1 = delete_forum_topic_request_convertToJSON(delete_forum_topic_request_1);
	printf("delete_forum_topic_request :\n%s\n", cJSON_Print(jsondelete_forum_topic_request_1));
	delete_forum_topic_request_t* delete_forum_topic_request_2 = delete_forum_topic_request_parseFromJSON(jsondelete_forum_topic_request_1);
	cJSON* jsondelete_forum_topic_request_2 = delete_forum_topic_request_convertToJSON(delete_forum_topic_request_2);
	printf("repeating delete_forum_topic_request:\n%s\n", cJSON_Print(jsondelete_forum_topic_request_2));
}

int main() {
  test_delete_forum_topic_request(1);
  test_delete_forum_topic_request(0);

  printf("Hello world \n");
  return 0;
}

#endif // delete_forum_topic_request_MAIN
#endif // delete_forum_topic_request_TEST
