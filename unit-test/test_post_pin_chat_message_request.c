#ifndef post_pin_chat_message_request_TEST
#define post_pin_chat_message_request_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define post_pin_chat_message_request_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/post_pin_chat_message_request.h"
post_pin_chat_message_request_t* instantiate_post_pin_chat_message_request(int include_optional);

#include "test_post_send_message_request_chat_id.c"


post_pin_chat_message_request_t* instantiate_post_pin_chat_message_request(int include_optional) {
  post_pin_chat_message_request_t* post_pin_chat_message_request = NULL;
  if (include_optional) {
    post_pin_chat_message_request = post_pin_chat_message_request_create(
      null,
      56,
      "0",
      1
    );
  } else {
    post_pin_chat_message_request = post_pin_chat_message_request_create(
      null,
      56,
      "0",
      1
    );
  }

  return post_pin_chat_message_request;
}


#ifdef post_pin_chat_message_request_MAIN

void test_post_pin_chat_message_request(int include_optional) {
    post_pin_chat_message_request_t* post_pin_chat_message_request_1 = instantiate_post_pin_chat_message_request(include_optional);

	cJSON* jsonpost_pin_chat_message_request_1 = post_pin_chat_message_request_convertToJSON(post_pin_chat_message_request_1);
	printf("post_pin_chat_message_request :\n%s\n", cJSON_Print(jsonpost_pin_chat_message_request_1));
	post_pin_chat_message_request_t* post_pin_chat_message_request_2 = post_pin_chat_message_request_parseFromJSON(jsonpost_pin_chat_message_request_1);
	cJSON* jsonpost_pin_chat_message_request_2 = post_pin_chat_message_request_convertToJSON(post_pin_chat_message_request_2);
	printf("repeating post_pin_chat_message_request:\n%s\n", cJSON_Print(jsonpost_pin_chat_message_request_2));
}

int main() {
  test_post_pin_chat_message_request(1);
  test_post_pin_chat_message_request(0);

  printf("Hello world \n");
  return 0;
}

#endif // post_pin_chat_message_request_MAIN
#endif // post_pin_chat_message_request_TEST
