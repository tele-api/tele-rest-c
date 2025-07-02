#ifndef post_restrict_chat_member_request_TEST
#define post_restrict_chat_member_request_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define post_restrict_chat_member_request_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/post_restrict_chat_member_request.h"
post_restrict_chat_member_request_t* instantiate_post_restrict_chat_member_request(int include_optional);

#include "test_post_restrict_chat_member_request_chat_id.c"
#include "test_chat_permissions.c"


post_restrict_chat_member_request_t* instantiate_post_restrict_chat_member_request(int include_optional) {
  post_restrict_chat_member_request_t* post_restrict_chat_member_request = NULL;
  if (include_optional) {
    post_restrict_chat_member_request = post_restrict_chat_member_request_create(
      null,
      56,
       // false, not to have infinite recursion
      instantiate_chat_permissions(0),
      1,
      56
    );
  } else {
    post_restrict_chat_member_request = post_restrict_chat_member_request_create(
      null,
      56,
      NULL,
      1,
      56
    );
  }

  return post_restrict_chat_member_request;
}


#ifdef post_restrict_chat_member_request_MAIN

void test_post_restrict_chat_member_request(int include_optional) {
    post_restrict_chat_member_request_t* post_restrict_chat_member_request_1 = instantiate_post_restrict_chat_member_request(include_optional);

	cJSON* jsonpost_restrict_chat_member_request_1 = post_restrict_chat_member_request_convertToJSON(post_restrict_chat_member_request_1);
	printf("post_restrict_chat_member_request :\n%s\n", cJSON_Print(jsonpost_restrict_chat_member_request_1));
	post_restrict_chat_member_request_t* post_restrict_chat_member_request_2 = post_restrict_chat_member_request_parseFromJSON(jsonpost_restrict_chat_member_request_1);
	cJSON* jsonpost_restrict_chat_member_request_2 = post_restrict_chat_member_request_convertToJSON(post_restrict_chat_member_request_2);
	printf("repeating post_restrict_chat_member_request:\n%s\n", cJSON_Print(jsonpost_restrict_chat_member_request_2));
}

int main() {
  test_post_restrict_chat_member_request(1);
  test_post_restrict_chat_member_request(0);

  printf("Hello world \n");
  return 0;
}

#endif // post_restrict_chat_member_request_MAIN
#endif // post_restrict_chat_member_request_TEST
