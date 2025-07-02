#ifndef post_approve_chat_join_request_request_TEST
#define post_approve_chat_join_request_request_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define post_approve_chat_join_request_request_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/post_approve_chat_join_request_request.h"
post_approve_chat_join_request_request_t* instantiate_post_approve_chat_join_request_request(int include_optional);

#include "test_post_send_message_request_chat_id.c"


post_approve_chat_join_request_request_t* instantiate_post_approve_chat_join_request_request(int include_optional) {
  post_approve_chat_join_request_request_t* post_approve_chat_join_request_request = NULL;
  if (include_optional) {
    post_approve_chat_join_request_request = post_approve_chat_join_request_request_create(
      null,
      56
    );
  } else {
    post_approve_chat_join_request_request = post_approve_chat_join_request_request_create(
      null,
      56
    );
  }

  return post_approve_chat_join_request_request;
}


#ifdef post_approve_chat_join_request_request_MAIN

void test_post_approve_chat_join_request_request(int include_optional) {
    post_approve_chat_join_request_request_t* post_approve_chat_join_request_request_1 = instantiate_post_approve_chat_join_request_request(include_optional);

	cJSON* jsonpost_approve_chat_join_request_request_1 = post_approve_chat_join_request_request_convertToJSON(post_approve_chat_join_request_request_1);
	printf("post_approve_chat_join_request_request :\n%s\n", cJSON_Print(jsonpost_approve_chat_join_request_request_1));
	post_approve_chat_join_request_request_t* post_approve_chat_join_request_request_2 = post_approve_chat_join_request_request_parseFromJSON(jsonpost_approve_chat_join_request_request_1);
	cJSON* jsonpost_approve_chat_join_request_request_2 = post_approve_chat_join_request_request_convertToJSON(post_approve_chat_join_request_request_2);
	printf("repeating post_approve_chat_join_request_request:\n%s\n", cJSON_Print(jsonpost_approve_chat_join_request_request_2));
}

int main() {
  test_post_approve_chat_join_request_request(1);
  test_post_approve_chat_join_request_request(0);

  printf("Hello world \n");
  return 0;
}

#endif // post_approve_chat_join_request_request_MAIN
#endif // post_approve_chat_join_request_request_TEST
