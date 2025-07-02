#ifndef decline_chat_join_request_response_TEST
#define decline_chat_join_request_response_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define decline_chat_join_request_response_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/decline_chat_join_request_response.h"
decline_chat_join_request_response_t* instantiate_decline_chat_join_request_response(int include_optional);



decline_chat_join_request_response_t* instantiate_decline_chat_join_request_response(int include_optional) {
  decline_chat_join_request_response_t* decline_chat_join_request_response = NULL;
  if (include_optional) {
    decline_chat_join_request_response = decline_chat_join_request_response_create(
      1,
      1
    );
  } else {
    decline_chat_join_request_response = decline_chat_join_request_response_create(
      1,
      1
    );
  }

  return decline_chat_join_request_response;
}


#ifdef decline_chat_join_request_response_MAIN

void test_decline_chat_join_request_response(int include_optional) {
    decline_chat_join_request_response_t* decline_chat_join_request_response_1 = instantiate_decline_chat_join_request_response(include_optional);

	cJSON* jsondecline_chat_join_request_response_1 = decline_chat_join_request_response_convertToJSON(decline_chat_join_request_response_1);
	printf("decline_chat_join_request_response :\n%s\n", cJSON_Print(jsondecline_chat_join_request_response_1));
	decline_chat_join_request_response_t* decline_chat_join_request_response_2 = decline_chat_join_request_response_parseFromJSON(jsondecline_chat_join_request_response_1);
	cJSON* jsondecline_chat_join_request_response_2 = decline_chat_join_request_response_convertToJSON(decline_chat_join_request_response_2);
	printf("repeating decline_chat_join_request_response:\n%s\n", cJSON_Print(jsondecline_chat_join_request_response_2));
}

int main() {
  test_decline_chat_join_request_response(1);
  test_decline_chat_join_request_response(0);

  printf("Hello world \n");
  return 0;
}

#endif // decline_chat_join_request_response_MAIN
#endif // decline_chat_join_request_response_TEST
