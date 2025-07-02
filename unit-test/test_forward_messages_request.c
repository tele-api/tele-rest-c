#ifndef forward_messages_request_TEST
#define forward_messages_request_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define forward_messages_request_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/forward_messages_request.h"
forward_messages_request_t* instantiate_forward_messages_request(int include_optional);

#include "test_send_message_request_chat_id.c"
#include "test_forward_messages_request_from_chat_id.c"


forward_messages_request_t* instantiate_forward_messages_request(int include_optional) {
  forward_messages_request_t* forward_messages_request = NULL;
  if (include_optional) {
    forward_messages_request = forward_messages_request_create(
      null,
      null,
      list_createList(),
      56,
      1,
      1
    );
  } else {
    forward_messages_request = forward_messages_request_create(
      null,
      null,
      list_createList(),
      56,
      1,
      1
    );
  }

  return forward_messages_request;
}


#ifdef forward_messages_request_MAIN

void test_forward_messages_request(int include_optional) {
    forward_messages_request_t* forward_messages_request_1 = instantiate_forward_messages_request(include_optional);

	cJSON* jsonforward_messages_request_1 = forward_messages_request_convertToJSON(forward_messages_request_1);
	printf("forward_messages_request :\n%s\n", cJSON_Print(jsonforward_messages_request_1));
	forward_messages_request_t* forward_messages_request_2 = forward_messages_request_parseFromJSON(jsonforward_messages_request_1);
	cJSON* jsonforward_messages_request_2 = forward_messages_request_convertToJSON(forward_messages_request_2);
	printf("repeating forward_messages_request:\n%s\n", cJSON_Print(jsonforward_messages_request_2));
}

int main() {
  test_forward_messages_request(1);
  test_forward_messages_request(0);

  printf("Hello world \n");
  return 0;
}

#endif // forward_messages_request_MAIN
#endif // forward_messages_request_TEST
