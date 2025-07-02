#ifndef post_set_chat_administrator_custom_title_request_TEST
#define post_set_chat_administrator_custom_title_request_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define post_set_chat_administrator_custom_title_request_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/post_set_chat_administrator_custom_title_request.h"
post_set_chat_administrator_custom_title_request_t* instantiate_post_set_chat_administrator_custom_title_request(int include_optional);

#include "test_post_restrict_chat_member_request_chat_id.c"


post_set_chat_administrator_custom_title_request_t* instantiate_post_set_chat_administrator_custom_title_request(int include_optional) {
  post_set_chat_administrator_custom_title_request_t* post_set_chat_administrator_custom_title_request = NULL;
  if (include_optional) {
    post_set_chat_administrator_custom_title_request = post_set_chat_administrator_custom_title_request_create(
      null,
      56,
      "0"
    );
  } else {
    post_set_chat_administrator_custom_title_request = post_set_chat_administrator_custom_title_request_create(
      null,
      56,
      "0"
    );
  }

  return post_set_chat_administrator_custom_title_request;
}


#ifdef post_set_chat_administrator_custom_title_request_MAIN

void test_post_set_chat_administrator_custom_title_request(int include_optional) {
    post_set_chat_administrator_custom_title_request_t* post_set_chat_administrator_custom_title_request_1 = instantiate_post_set_chat_administrator_custom_title_request(include_optional);

	cJSON* jsonpost_set_chat_administrator_custom_title_request_1 = post_set_chat_administrator_custom_title_request_convertToJSON(post_set_chat_administrator_custom_title_request_1);
	printf("post_set_chat_administrator_custom_title_request :\n%s\n", cJSON_Print(jsonpost_set_chat_administrator_custom_title_request_1));
	post_set_chat_administrator_custom_title_request_t* post_set_chat_administrator_custom_title_request_2 = post_set_chat_administrator_custom_title_request_parseFromJSON(jsonpost_set_chat_administrator_custom_title_request_1);
	cJSON* jsonpost_set_chat_administrator_custom_title_request_2 = post_set_chat_administrator_custom_title_request_convertToJSON(post_set_chat_administrator_custom_title_request_2);
	printf("repeating post_set_chat_administrator_custom_title_request:\n%s\n", cJSON_Print(jsonpost_set_chat_administrator_custom_title_request_2));
}

int main() {
  test_post_set_chat_administrator_custom_title_request(1);
  test_post_set_chat_administrator_custom_title_request(0);

  printf("Hello world \n");
  return 0;
}

#endif // post_set_chat_administrator_custom_title_request_MAIN
#endif // post_set_chat_administrator_custom_title_request_TEST
