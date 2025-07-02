#ifndef unban_chat_member_request_TEST
#define unban_chat_member_request_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define unban_chat_member_request_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/unban_chat_member_request.h"
unban_chat_member_request_t* instantiate_unban_chat_member_request(int include_optional);

#include "test_ban_chat_member_request_chat_id.c"


unban_chat_member_request_t* instantiate_unban_chat_member_request(int include_optional) {
  unban_chat_member_request_t* unban_chat_member_request = NULL;
  if (include_optional) {
    unban_chat_member_request = unban_chat_member_request_create(
      null,
      56,
      1
    );
  } else {
    unban_chat_member_request = unban_chat_member_request_create(
      null,
      56,
      1
    );
  }

  return unban_chat_member_request;
}


#ifdef unban_chat_member_request_MAIN

void test_unban_chat_member_request(int include_optional) {
    unban_chat_member_request_t* unban_chat_member_request_1 = instantiate_unban_chat_member_request(include_optional);

	cJSON* jsonunban_chat_member_request_1 = unban_chat_member_request_convertToJSON(unban_chat_member_request_1);
	printf("unban_chat_member_request :\n%s\n", cJSON_Print(jsonunban_chat_member_request_1));
	unban_chat_member_request_t* unban_chat_member_request_2 = unban_chat_member_request_parseFromJSON(jsonunban_chat_member_request_1);
	cJSON* jsonunban_chat_member_request_2 = unban_chat_member_request_convertToJSON(unban_chat_member_request_2);
	printf("repeating unban_chat_member_request:\n%s\n", cJSON_Print(jsonunban_chat_member_request_2));
}

int main() {
  test_unban_chat_member_request(1);
  test_unban_chat_member_request(0);

  printf("Hello world \n");
  return 0;
}

#endif // unban_chat_member_request_MAIN
#endif // unban_chat_member_request_TEST
