#ifndef post_create_chat_invite_link_request_TEST
#define post_create_chat_invite_link_request_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define post_create_chat_invite_link_request_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/post_create_chat_invite_link_request.h"
post_create_chat_invite_link_request_t* instantiate_post_create_chat_invite_link_request(int include_optional);

#include "test_post_send_message_request_chat_id.c"


post_create_chat_invite_link_request_t* instantiate_post_create_chat_invite_link_request(int include_optional) {
  post_create_chat_invite_link_request_t* post_create_chat_invite_link_request = NULL;
  if (include_optional) {
    post_create_chat_invite_link_request = post_create_chat_invite_link_request_create(
      null,
      "0",
      56,
      56,
      1
    );
  } else {
    post_create_chat_invite_link_request = post_create_chat_invite_link_request_create(
      null,
      "0",
      56,
      56,
      1
    );
  }

  return post_create_chat_invite_link_request;
}


#ifdef post_create_chat_invite_link_request_MAIN

void test_post_create_chat_invite_link_request(int include_optional) {
    post_create_chat_invite_link_request_t* post_create_chat_invite_link_request_1 = instantiate_post_create_chat_invite_link_request(include_optional);

	cJSON* jsonpost_create_chat_invite_link_request_1 = post_create_chat_invite_link_request_convertToJSON(post_create_chat_invite_link_request_1);
	printf("post_create_chat_invite_link_request :\n%s\n", cJSON_Print(jsonpost_create_chat_invite_link_request_1));
	post_create_chat_invite_link_request_t* post_create_chat_invite_link_request_2 = post_create_chat_invite_link_request_parseFromJSON(jsonpost_create_chat_invite_link_request_1);
	cJSON* jsonpost_create_chat_invite_link_request_2 = post_create_chat_invite_link_request_convertToJSON(post_create_chat_invite_link_request_2);
	printf("repeating post_create_chat_invite_link_request:\n%s\n", cJSON_Print(jsonpost_create_chat_invite_link_request_2));
}

int main() {
  test_post_create_chat_invite_link_request(1);
  test_post_create_chat_invite_link_request(0);

  printf("Hello world \n");
  return 0;
}

#endif // post_create_chat_invite_link_request_MAIN
#endif // post_create_chat_invite_link_request_TEST
