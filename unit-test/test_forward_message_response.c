#ifndef forward_message_response_TEST
#define forward_message_response_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define forward_message_response_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/forward_message_response.h"
forward_message_response_t* instantiate_forward_message_response(int include_optional);

#include "test_message.c"


forward_message_response_t* instantiate_forward_message_response(int include_optional) {
  forward_message_response_t* forward_message_response = NULL;
  if (include_optional) {
    forward_message_response = forward_message_response_create(
      1,
       // false, not to have infinite recursion
      instantiate_message(0)
    );
  } else {
    forward_message_response = forward_message_response_create(
      1,
      NULL
    );
  }

  return forward_message_response;
}


#ifdef forward_message_response_MAIN

void test_forward_message_response(int include_optional) {
    forward_message_response_t* forward_message_response_1 = instantiate_forward_message_response(include_optional);

	cJSON* jsonforward_message_response_1 = forward_message_response_convertToJSON(forward_message_response_1);
	printf("forward_message_response :\n%s\n", cJSON_Print(jsonforward_message_response_1));
	forward_message_response_t* forward_message_response_2 = forward_message_response_parseFromJSON(jsonforward_message_response_1);
	cJSON* jsonforward_message_response_2 = forward_message_response_convertToJSON(forward_message_response_2);
	printf("repeating forward_message_response:\n%s\n", cJSON_Print(jsonforward_message_response_2));
}

int main() {
  test_forward_message_response(1);
  test_forward_message_response(0);

  printf("Hello world \n");
  return 0;
}

#endif // forward_message_response_MAIN
#endif // forward_message_response_TEST
