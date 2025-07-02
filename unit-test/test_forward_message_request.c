#ifndef forward_message_request_TEST
#define forward_message_request_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define forward_message_request_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/forward_message_request.h"
forward_message_request_t* instantiate_forward_message_request(int include_optional);

#include "test_send_message_request_chat_id.c"
#include "test_forward_message_request_from_chat_id.c"


forward_message_request_t* instantiate_forward_message_request(int include_optional) {
  forward_message_request_t* forward_message_request = NULL;
  if (include_optional) {
    forward_message_request = forward_message_request_create(
      null,
      null,
      56,
      56,
      56,
      1,
      1
    );
  } else {
    forward_message_request = forward_message_request_create(
      null,
      null,
      56,
      56,
      56,
      1,
      1
    );
  }

  return forward_message_request;
}


#ifdef forward_message_request_MAIN

void test_forward_message_request(int include_optional) {
    forward_message_request_t* forward_message_request_1 = instantiate_forward_message_request(include_optional);

	cJSON* jsonforward_message_request_1 = forward_message_request_convertToJSON(forward_message_request_1);
	printf("forward_message_request :\n%s\n", cJSON_Print(jsonforward_message_request_1));
	forward_message_request_t* forward_message_request_2 = forward_message_request_parseFromJSON(jsonforward_message_request_1);
	cJSON* jsonforward_message_request_2 = forward_message_request_convertToJSON(forward_message_request_2);
	printf("repeating forward_message_request:\n%s\n", cJSON_Print(jsonforward_message_request_2));
}

int main() {
  test_forward_message_request(1);
  test_forward_message_request(0);

  printf("Hello world \n");
  return 0;
}

#endif // forward_message_request_MAIN
#endif // forward_message_request_TEST
