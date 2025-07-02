#ifndef approve_chat_join_request_request_TEST
#define approve_chat_join_request_request_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define approve_chat_join_request_request_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/approve_chat_join_request_request.h"
approve_chat_join_request_request_t* instantiate_approve_chat_join_request_request(int include_optional);

#include "test_send_message_request_chat_id.c"


approve_chat_join_request_request_t* instantiate_approve_chat_join_request_request(int include_optional) {
  approve_chat_join_request_request_t* approve_chat_join_request_request = NULL;
  if (include_optional) {
    approve_chat_join_request_request = approve_chat_join_request_request_create(
      null,
      56
    );
  } else {
    approve_chat_join_request_request = approve_chat_join_request_request_create(
      null,
      56
    );
  }

  return approve_chat_join_request_request;
}


#ifdef approve_chat_join_request_request_MAIN

void test_approve_chat_join_request_request(int include_optional) {
    approve_chat_join_request_request_t* approve_chat_join_request_request_1 = instantiate_approve_chat_join_request_request(include_optional);

	cJSON* jsonapprove_chat_join_request_request_1 = approve_chat_join_request_request_convertToJSON(approve_chat_join_request_request_1);
	printf("approve_chat_join_request_request :\n%s\n", cJSON_Print(jsonapprove_chat_join_request_request_1));
	approve_chat_join_request_request_t* approve_chat_join_request_request_2 = approve_chat_join_request_request_parseFromJSON(jsonapprove_chat_join_request_request_1);
	cJSON* jsonapprove_chat_join_request_request_2 = approve_chat_join_request_request_convertToJSON(approve_chat_join_request_request_2);
	printf("repeating approve_chat_join_request_request:\n%s\n", cJSON_Print(jsonapprove_chat_join_request_request_2));
}

int main() {
  test_approve_chat_join_request_request(1);
  test_approve_chat_join_request_request(0);

  printf("Hello world \n");
  return 0;
}

#endif // approve_chat_join_request_request_MAIN
#endif // approve_chat_join_request_request_TEST
