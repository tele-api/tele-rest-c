#ifndef forward_messages_response_TEST
#define forward_messages_response_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define forward_messages_response_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/forward_messages_response.h"
forward_messages_response_t* instantiate_forward_messages_response(int include_optional);



forward_messages_response_t* instantiate_forward_messages_response(int include_optional) {
  forward_messages_response_t* forward_messages_response = NULL;
  if (include_optional) {
    forward_messages_response = forward_messages_response_create(
      1,
      list_createList()
    );
  } else {
    forward_messages_response = forward_messages_response_create(
      1,
      list_createList()
    );
  }

  return forward_messages_response;
}


#ifdef forward_messages_response_MAIN

void test_forward_messages_response(int include_optional) {
    forward_messages_response_t* forward_messages_response_1 = instantiate_forward_messages_response(include_optional);

	cJSON* jsonforward_messages_response_1 = forward_messages_response_convertToJSON(forward_messages_response_1);
	printf("forward_messages_response :\n%s\n", cJSON_Print(jsonforward_messages_response_1));
	forward_messages_response_t* forward_messages_response_2 = forward_messages_response_parseFromJSON(jsonforward_messages_response_1);
	cJSON* jsonforward_messages_response_2 = forward_messages_response_convertToJSON(forward_messages_response_2);
	printf("repeating forward_messages_response:\n%s\n", cJSON_Print(jsonforward_messages_response_2));
}

int main() {
  test_forward_messages_response(1);
  test_forward_messages_response(0);

  printf("Hello world \n");
  return 0;
}

#endif // forward_messages_response_MAIN
#endif // forward_messages_response_TEST
