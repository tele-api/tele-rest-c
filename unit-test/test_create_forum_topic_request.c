#ifndef create_forum_topic_request_TEST
#define create_forum_topic_request_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define create_forum_topic_request_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/create_forum_topic_request.h"
create_forum_topic_request_t* instantiate_create_forum_topic_request(int include_optional);

#include "test_bot_command_scope_chat_chat_id.c"


create_forum_topic_request_t* instantiate_create_forum_topic_request(int include_optional) {
  create_forum_topic_request_t* create_forum_topic_request = NULL;
  if (include_optional) {
    create_forum_topic_request = create_forum_topic_request_create(
      null,
      "0",
      telegram_bot_api_create_forum_topic_request_ICONCOLOR_7322096,
      "0"
    );
  } else {
    create_forum_topic_request = create_forum_topic_request_create(
      null,
      "0",
      telegram_bot_api_create_forum_topic_request_ICONCOLOR_7322096,
      "0"
    );
  }

  return create_forum_topic_request;
}


#ifdef create_forum_topic_request_MAIN

void test_create_forum_topic_request(int include_optional) {
    create_forum_topic_request_t* create_forum_topic_request_1 = instantiate_create_forum_topic_request(include_optional);

	cJSON* jsoncreate_forum_topic_request_1 = create_forum_topic_request_convertToJSON(create_forum_topic_request_1);
	printf("create_forum_topic_request :\n%s\n", cJSON_Print(jsoncreate_forum_topic_request_1));
	create_forum_topic_request_t* create_forum_topic_request_2 = create_forum_topic_request_parseFromJSON(jsoncreate_forum_topic_request_1);
	cJSON* jsoncreate_forum_topic_request_2 = create_forum_topic_request_convertToJSON(create_forum_topic_request_2);
	printf("repeating create_forum_topic_request:\n%s\n", cJSON_Print(jsoncreate_forum_topic_request_2));
}

int main() {
  test_create_forum_topic_request(1);
  test_create_forum_topic_request(0);

  printf("Hello world \n");
  return 0;
}

#endif // create_forum_topic_request_MAIN
#endif // create_forum_topic_request_TEST
