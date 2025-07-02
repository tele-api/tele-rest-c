#ifndef post_send_gift_request_TEST
#define post_send_gift_request_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define post_send_gift_request_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/post_send_gift_request.h"
post_send_gift_request_t* instantiate_post_send_gift_request(int include_optional);

#include "test_post_send_gift_request_chat_id.c"


post_send_gift_request_t* instantiate_post_send_gift_request(int include_optional) {
  post_send_gift_request_t* post_send_gift_request = NULL;
  if (include_optional) {
    post_send_gift_request = post_send_gift_request_create(
      "0",
      56,
      null,
      1,
      "0",
      "0",
      list_createList()
    );
  } else {
    post_send_gift_request = post_send_gift_request_create(
      "0",
      56,
      null,
      1,
      "0",
      "0",
      list_createList()
    );
  }

  return post_send_gift_request;
}


#ifdef post_send_gift_request_MAIN

void test_post_send_gift_request(int include_optional) {
    post_send_gift_request_t* post_send_gift_request_1 = instantiate_post_send_gift_request(include_optional);

	cJSON* jsonpost_send_gift_request_1 = post_send_gift_request_convertToJSON(post_send_gift_request_1);
	printf("post_send_gift_request :\n%s\n", cJSON_Print(jsonpost_send_gift_request_1));
	post_send_gift_request_t* post_send_gift_request_2 = post_send_gift_request_parseFromJSON(jsonpost_send_gift_request_1);
	cJSON* jsonpost_send_gift_request_2 = post_send_gift_request_convertToJSON(post_send_gift_request_2);
	printf("repeating post_send_gift_request:\n%s\n", cJSON_Print(jsonpost_send_gift_request_2));
}

int main() {
  test_post_send_gift_request(1);
  test_post_send_gift_request(0);

  printf("Hello world \n");
  return 0;
}

#endif // post_send_gift_request_MAIN
#endif // post_send_gift_request_TEST
