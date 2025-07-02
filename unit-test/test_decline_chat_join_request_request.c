#ifndef decline_chat_join_request_request_TEST
#define decline_chat_join_request_request_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define decline_chat_join_request_request_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/decline_chat_join_request_request.h"
decline_chat_join_request_request_t* instantiate_decline_chat_join_request_request(int include_optional);

#include "test_send_message_request_chat_id.c"


decline_chat_join_request_request_t* instantiate_decline_chat_join_request_request(int include_optional) {
  decline_chat_join_request_request_t* decline_chat_join_request_request = NULL;
  if (include_optional) {
    decline_chat_join_request_request = decline_chat_join_request_request_create(
      null,
      56
    );
  } else {
    decline_chat_join_request_request = decline_chat_join_request_request_create(
      null,
      56
    );
  }

  return decline_chat_join_request_request;
}


#ifdef decline_chat_join_request_request_MAIN

void test_decline_chat_join_request_request(int include_optional) {
    decline_chat_join_request_request_t* decline_chat_join_request_request_1 = instantiate_decline_chat_join_request_request(include_optional);

	cJSON* jsondecline_chat_join_request_request_1 = decline_chat_join_request_request_convertToJSON(decline_chat_join_request_request_1);
	printf("decline_chat_join_request_request :\n%s\n", cJSON_Print(jsondecline_chat_join_request_request_1));
	decline_chat_join_request_request_t* decline_chat_join_request_request_2 = decline_chat_join_request_request_parseFromJSON(jsondecline_chat_join_request_request_1);
	cJSON* jsondecline_chat_join_request_request_2 = decline_chat_join_request_request_convertToJSON(decline_chat_join_request_request_2);
	printf("repeating decline_chat_join_request_request:\n%s\n", cJSON_Print(jsondecline_chat_join_request_request_2));
}

int main() {
  test_decline_chat_join_request_request(1);
  test_decline_chat_join_request_request(0);

  printf("Hello world \n");
  return 0;
}

#endif // decline_chat_join_request_request_MAIN
#endif // decline_chat_join_request_request_TEST
