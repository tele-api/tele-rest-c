#ifndef post_send_poll_request_TEST
#define post_send_poll_request_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define post_send_poll_request_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/post_send_poll_request.h"
post_send_poll_request_t* instantiate_post_send_poll_request(int include_optional);

#include "test_post_send_message_request_chat_id.c"
#include "test_reply_parameters.c"
#include "test_post_send_message_request_reply_markup.c"


post_send_poll_request_t* instantiate_post_send_poll_request(int include_optional) {
  post_send_poll_request_t* post_send_poll_request = NULL;
  if (include_optional) {
    post_send_poll_request = post_send_poll_request_create(
      null,
      "0",
      list_createList(),
      "0",
      56,
      "0",
      list_createList(),
      1,
      telegram_bot_api_post_send_poll_request_TYPE_quiz,
      1,
      56,
      "0",
      "0",
      list_createList(),
      56,
      56,
      1,
      1,
      1,
      1,
      "0",
       // false, not to have infinite recursion
      instantiate_reply_parameters(0),
      null
    );
  } else {
    post_send_poll_request = post_send_poll_request_create(
      null,
      "0",
      list_createList(),
      "0",
      56,
      "0",
      list_createList(),
      1,
      telegram_bot_api_post_send_poll_request_TYPE_quiz,
      1,
      56,
      "0",
      "0",
      list_createList(),
      56,
      56,
      1,
      1,
      1,
      1,
      "0",
      NULL,
      null
    );
  }

  return post_send_poll_request;
}


#ifdef post_send_poll_request_MAIN

void test_post_send_poll_request(int include_optional) {
    post_send_poll_request_t* post_send_poll_request_1 = instantiate_post_send_poll_request(include_optional);

	cJSON* jsonpost_send_poll_request_1 = post_send_poll_request_convertToJSON(post_send_poll_request_1);
	printf("post_send_poll_request :\n%s\n", cJSON_Print(jsonpost_send_poll_request_1));
	post_send_poll_request_t* post_send_poll_request_2 = post_send_poll_request_parseFromJSON(jsonpost_send_poll_request_1);
	cJSON* jsonpost_send_poll_request_2 = post_send_poll_request_convertToJSON(post_send_poll_request_2);
	printf("repeating post_send_poll_request:\n%s\n", cJSON_Print(jsonpost_send_poll_request_2));
}

int main() {
  test_post_send_poll_request(1);
  test_post_send_poll_request(0);

  printf("Hello world \n");
  return 0;
}

#endif // post_send_poll_request_MAIN
#endif // post_send_poll_request_TEST
