#ifndef post_ban_chat_sender_chat_request_TEST
#define post_ban_chat_sender_chat_request_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define post_ban_chat_sender_chat_request_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/post_ban_chat_sender_chat_request.h"
post_ban_chat_sender_chat_request_t* instantiate_post_ban_chat_sender_chat_request(int include_optional);

#include "test_post_send_message_request_chat_id.c"


post_ban_chat_sender_chat_request_t* instantiate_post_ban_chat_sender_chat_request(int include_optional) {
  post_ban_chat_sender_chat_request_t* post_ban_chat_sender_chat_request = NULL;
  if (include_optional) {
    post_ban_chat_sender_chat_request = post_ban_chat_sender_chat_request_create(
      null,
      56
    );
  } else {
    post_ban_chat_sender_chat_request = post_ban_chat_sender_chat_request_create(
      null,
      56
    );
  }

  return post_ban_chat_sender_chat_request;
}


#ifdef post_ban_chat_sender_chat_request_MAIN

void test_post_ban_chat_sender_chat_request(int include_optional) {
    post_ban_chat_sender_chat_request_t* post_ban_chat_sender_chat_request_1 = instantiate_post_ban_chat_sender_chat_request(include_optional);

	cJSON* jsonpost_ban_chat_sender_chat_request_1 = post_ban_chat_sender_chat_request_convertToJSON(post_ban_chat_sender_chat_request_1);
	printf("post_ban_chat_sender_chat_request :\n%s\n", cJSON_Print(jsonpost_ban_chat_sender_chat_request_1));
	post_ban_chat_sender_chat_request_t* post_ban_chat_sender_chat_request_2 = post_ban_chat_sender_chat_request_parseFromJSON(jsonpost_ban_chat_sender_chat_request_1);
	cJSON* jsonpost_ban_chat_sender_chat_request_2 = post_ban_chat_sender_chat_request_convertToJSON(post_ban_chat_sender_chat_request_2);
	printf("repeating post_ban_chat_sender_chat_request:\n%s\n", cJSON_Print(jsonpost_ban_chat_sender_chat_request_2));
}

int main() {
  test_post_ban_chat_sender_chat_request(1);
  test_post_ban_chat_sender_chat_request(0);

  printf("Hello world \n");
  return 0;
}

#endif // post_ban_chat_sender_chat_request_MAIN
#endif // post_ban_chat_sender_chat_request_TEST
