#ifndef forward_message_request_from_chat_id_TEST
#define forward_message_request_from_chat_id_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define forward_message_request_from_chat_id_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/forward_message_request_from_chat_id.h"
forward_message_request_from_chat_id_t* instantiate_forward_message_request_from_chat_id(int include_optional);



forward_message_request_from_chat_id_t* instantiate_forward_message_request_from_chat_id(int include_optional) {
  forward_message_request_from_chat_id_t* forward_message_request_from_chat_id = NULL;
  if (include_optional) {
    forward_message_request_from_chat_id = forward_message_request_from_chat_id_create(
    );
  } else {
    forward_message_request_from_chat_id = forward_message_request_from_chat_id_create(
    );
  }

  return forward_message_request_from_chat_id;
}


#ifdef forward_message_request_from_chat_id_MAIN

void test_forward_message_request_from_chat_id(int include_optional) {
    forward_message_request_from_chat_id_t* forward_message_request_from_chat_id_1 = instantiate_forward_message_request_from_chat_id(include_optional);

	cJSON* jsonforward_message_request_from_chat_id_1 = forward_message_request_from_chat_id_convertToJSON(forward_message_request_from_chat_id_1);
	printf("forward_message_request_from_chat_id :\n%s\n", cJSON_Print(jsonforward_message_request_from_chat_id_1));
	forward_message_request_from_chat_id_t* forward_message_request_from_chat_id_2 = forward_message_request_from_chat_id_parseFromJSON(jsonforward_message_request_from_chat_id_1);
	cJSON* jsonforward_message_request_from_chat_id_2 = forward_message_request_from_chat_id_convertToJSON(forward_message_request_from_chat_id_2);
	printf("repeating forward_message_request_from_chat_id:\n%s\n", cJSON_Print(jsonforward_message_request_from_chat_id_2));
}

int main() {
  test_forward_message_request_from_chat_id(1);
  test_forward_message_request_from_chat_id(0);

  printf("Hello world \n");
  return 0;
}

#endif // forward_message_request_from_chat_id_MAIN
#endif // forward_message_request_from_chat_id_TEST
