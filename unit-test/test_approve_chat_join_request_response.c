#ifndef approve_chat_join_request_response_TEST
#define approve_chat_join_request_response_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define approve_chat_join_request_response_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/approve_chat_join_request_response.h"
approve_chat_join_request_response_t* instantiate_approve_chat_join_request_response(int include_optional);



approve_chat_join_request_response_t* instantiate_approve_chat_join_request_response(int include_optional) {
  approve_chat_join_request_response_t* approve_chat_join_request_response = NULL;
  if (include_optional) {
    approve_chat_join_request_response = approve_chat_join_request_response_create(
      1,
      1
    );
  } else {
    approve_chat_join_request_response = approve_chat_join_request_response_create(
      1,
      1
    );
  }

  return approve_chat_join_request_response;
}


#ifdef approve_chat_join_request_response_MAIN

void test_approve_chat_join_request_response(int include_optional) {
    approve_chat_join_request_response_t* approve_chat_join_request_response_1 = instantiate_approve_chat_join_request_response(include_optional);

	cJSON* jsonapprove_chat_join_request_response_1 = approve_chat_join_request_response_convertToJSON(approve_chat_join_request_response_1);
	printf("approve_chat_join_request_response :\n%s\n", cJSON_Print(jsonapprove_chat_join_request_response_1));
	approve_chat_join_request_response_t* approve_chat_join_request_response_2 = approve_chat_join_request_response_parseFromJSON(jsonapprove_chat_join_request_response_1);
	cJSON* jsonapprove_chat_join_request_response_2 = approve_chat_join_request_response_convertToJSON(approve_chat_join_request_response_2);
	printf("repeating approve_chat_join_request_response:\n%s\n", cJSON_Print(jsonapprove_chat_join_request_response_2));
}

int main() {
  test_approve_chat_join_request_response(1);
  test_approve_chat_join_request_response(0);

  printf("Hello world \n");
  return 0;
}

#endif // approve_chat_join_request_response_MAIN
#endif // approve_chat_join_request_response_TEST
