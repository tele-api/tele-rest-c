#ifndef forward_messages_request_from_chat_id_TEST
#define forward_messages_request_from_chat_id_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define forward_messages_request_from_chat_id_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/forward_messages_request_from_chat_id.h"
forward_messages_request_from_chat_id_t* instantiate_forward_messages_request_from_chat_id(int include_optional);



forward_messages_request_from_chat_id_t* instantiate_forward_messages_request_from_chat_id(int include_optional) {
  forward_messages_request_from_chat_id_t* forward_messages_request_from_chat_id = NULL;
  if (include_optional) {
    forward_messages_request_from_chat_id = forward_messages_request_from_chat_id_create(
    );
  } else {
    forward_messages_request_from_chat_id = forward_messages_request_from_chat_id_create(
    );
  }

  return forward_messages_request_from_chat_id;
}


#ifdef forward_messages_request_from_chat_id_MAIN

void test_forward_messages_request_from_chat_id(int include_optional) {
    forward_messages_request_from_chat_id_t* forward_messages_request_from_chat_id_1 = instantiate_forward_messages_request_from_chat_id(include_optional);

	cJSON* jsonforward_messages_request_from_chat_id_1 = forward_messages_request_from_chat_id_convertToJSON(forward_messages_request_from_chat_id_1);
	printf("forward_messages_request_from_chat_id :\n%s\n", cJSON_Print(jsonforward_messages_request_from_chat_id_1));
	forward_messages_request_from_chat_id_t* forward_messages_request_from_chat_id_2 = forward_messages_request_from_chat_id_parseFromJSON(jsonforward_messages_request_from_chat_id_1);
	cJSON* jsonforward_messages_request_from_chat_id_2 = forward_messages_request_from_chat_id_convertToJSON(forward_messages_request_from_chat_id_2);
	printf("repeating forward_messages_request_from_chat_id:\n%s\n", cJSON_Print(jsonforward_messages_request_from_chat_id_2));
}

int main() {
  test_forward_messages_request_from_chat_id(1);
  test_forward_messages_request_from_chat_id(0);

  printf("Hello world \n");
  return 0;
}

#endif // forward_messages_request_from_chat_id_MAIN
#endif // forward_messages_request_from_chat_id_TEST
