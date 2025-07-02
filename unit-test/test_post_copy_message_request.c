#ifndef post_copy_message_request_TEST
#define post_copy_message_request_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define post_copy_message_request_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/post_copy_message_request.h"
post_copy_message_request_t* instantiate_post_copy_message_request(int include_optional);

#include "test_post_send_message_request_chat_id.c"
#include "test_post_forward_message_request_from_chat_id.c"
#include "test_reply_parameters.c"
#include "test_post_send_message_request_reply_markup.c"


post_copy_message_request_t* instantiate_post_copy_message_request(int include_optional) {
  post_copy_message_request_t* post_copy_message_request = NULL;
  if (include_optional) {
    post_copy_message_request = post_copy_message_request_create(
      null,
      null,
      56,
      56,
      56,
      "0",
      "0",
      list_createList(),
      1,
      1,
      1,
      1,
       // false, not to have infinite recursion
      instantiate_reply_parameters(0),
      null
    );
  } else {
    post_copy_message_request = post_copy_message_request_create(
      null,
      null,
      56,
      56,
      56,
      "0",
      "0",
      list_createList(),
      1,
      1,
      1,
      1,
      NULL,
      null
    );
  }

  return post_copy_message_request;
}


#ifdef post_copy_message_request_MAIN

void test_post_copy_message_request(int include_optional) {
    post_copy_message_request_t* post_copy_message_request_1 = instantiate_post_copy_message_request(include_optional);

	cJSON* jsonpost_copy_message_request_1 = post_copy_message_request_convertToJSON(post_copy_message_request_1);
	printf("post_copy_message_request :\n%s\n", cJSON_Print(jsonpost_copy_message_request_1));
	post_copy_message_request_t* post_copy_message_request_2 = post_copy_message_request_parseFromJSON(jsonpost_copy_message_request_1);
	cJSON* jsonpost_copy_message_request_2 = post_copy_message_request_convertToJSON(post_copy_message_request_2);
	printf("repeating post_copy_message_request:\n%s\n", cJSON_Print(jsonpost_copy_message_request_2));
}

int main() {
  test_post_copy_message_request(1);
  test_post_copy_message_request(0);

  printf("Hello world \n");
  return 0;
}

#endif // post_copy_message_request_MAIN
#endif // post_copy_message_request_TEST
