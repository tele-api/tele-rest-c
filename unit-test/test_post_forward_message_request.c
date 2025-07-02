#ifndef post_forward_message_request_TEST
#define post_forward_message_request_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define post_forward_message_request_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/post_forward_message_request.h"
post_forward_message_request_t* instantiate_post_forward_message_request(int include_optional);

#include "test_post_send_message_request_chat_id.c"
#include "test_post_forward_message_request_from_chat_id.c"


post_forward_message_request_t* instantiate_post_forward_message_request(int include_optional) {
  post_forward_message_request_t* post_forward_message_request = NULL;
  if (include_optional) {
    post_forward_message_request = post_forward_message_request_create(
      null,
      null,
      56,
      56,
      56,
      1,
      1
    );
  } else {
    post_forward_message_request = post_forward_message_request_create(
      null,
      null,
      56,
      56,
      56,
      1,
      1
    );
  }

  return post_forward_message_request;
}


#ifdef post_forward_message_request_MAIN

void test_post_forward_message_request(int include_optional) {
    post_forward_message_request_t* post_forward_message_request_1 = instantiate_post_forward_message_request(include_optional);

	cJSON* jsonpost_forward_message_request_1 = post_forward_message_request_convertToJSON(post_forward_message_request_1);
	printf("post_forward_message_request :\n%s\n", cJSON_Print(jsonpost_forward_message_request_1));
	post_forward_message_request_t* post_forward_message_request_2 = post_forward_message_request_parseFromJSON(jsonpost_forward_message_request_1);
	cJSON* jsonpost_forward_message_request_2 = post_forward_message_request_convertToJSON(post_forward_message_request_2);
	printf("repeating post_forward_message_request:\n%s\n", cJSON_Print(jsonpost_forward_message_request_2));
}

int main() {
  test_post_forward_message_request(1);
  test_post_forward_message_request(0);

  printf("Hello world \n");
  return 0;
}

#endif // post_forward_message_request_MAIN
#endif // post_forward_message_request_TEST
