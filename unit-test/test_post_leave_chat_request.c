#ifndef post_leave_chat_request_TEST
#define post_leave_chat_request_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define post_leave_chat_request_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/post_leave_chat_request.h"
post_leave_chat_request_t* instantiate_post_leave_chat_request(int include_optional);

#include "test_post_leave_chat_request_chat_id.c"


post_leave_chat_request_t* instantiate_post_leave_chat_request(int include_optional) {
  post_leave_chat_request_t* post_leave_chat_request = NULL;
  if (include_optional) {
    post_leave_chat_request = post_leave_chat_request_create(
      null
    );
  } else {
    post_leave_chat_request = post_leave_chat_request_create(
      null
    );
  }

  return post_leave_chat_request;
}


#ifdef post_leave_chat_request_MAIN

void test_post_leave_chat_request(int include_optional) {
    post_leave_chat_request_t* post_leave_chat_request_1 = instantiate_post_leave_chat_request(include_optional);

	cJSON* jsonpost_leave_chat_request_1 = post_leave_chat_request_convertToJSON(post_leave_chat_request_1);
	printf("post_leave_chat_request :\n%s\n", cJSON_Print(jsonpost_leave_chat_request_1));
	post_leave_chat_request_t* post_leave_chat_request_2 = post_leave_chat_request_parseFromJSON(jsonpost_leave_chat_request_1);
	cJSON* jsonpost_leave_chat_request_2 = post_leave_chat_request_convertToJSON(post_leave_chat_request_2);
	printf("repeating post_leave_chat_request:\n%s\n", cJSON_Print(jsonpost_leave_chat_request_2));
}

int main() {
  test_post_leave_chat_request(1);
  test_post_leave_chat_request(0);

  printf("Hello world \n");
  return 0;
}

#endif // post_leave_chat_request_MAIN
#endif // post_leave_chat_request_TEST
