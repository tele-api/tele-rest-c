#ifndef unpin_chat_message_request_TEST
#define unpin_chat_message_request_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define unpin_chat_message_request_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/unpin_chat_message_request.h"
unpin_chat_message_request_t* instantiate_unpin_chat_message_request(int include_optional);

#include "test_send_message_request_chat_id.c"


unpin_chat_message_request_t* instantiate_unpin_chat_message_request(int include_optional) {
  unpin_chat_message_request_t* unpin_chat_message_request = NULL;
  if (include_optional) {
    unpin_chat_message_request = unpin_chat_message_request_create(
      null,
      "0",
      56
    );
  } else {
    unpin_chat_message_request = unpin_chat_message_request_create(
      null,
      "0",
      56
    );
  }

  return unpin_chat_message_request;
}


#ifdef unpin_chat_message_request_MAIN

void test_unpin_chat_message_request(int include_optional) {
    unpin_chat_message_request_t* unpin_chat_message_request_1 = instantiate_unpin_chat_message_request(include_optional);

	cJSON* jsonunpin_chat_message_request_1 = unpin_chat_message_request_convertToJSON(unpin_chat_message_request_1);
	printf("unpin_chat_message_request :\n%s\n", cJSON_Print(jsonunpin_chat_message_request_1));
	unpin_chat_message_request_t* unpin_chat_message_request_2 = unpin_chat_message_request_parseFromJSON(jsonunpin_chat_message_request_1);
	cJSON* jsonunpin_chat_message_request_2 = unpin_chat_message_request_convertToJSON(unpin_chat_message_request_2);
	printf("repeating unpin_chat_message_request:\n%s\n", cJSON_Print(jsonunpin_chat_message_request_2));
}

int main() {
  test_unpin_chat_message_request(1);
  test_unpin_chat_message_request(0);

  printf("Hello world \n");
  return 0;
}

#endif // unpin_chat_message_request_MAIN
#endif // unpin_chat_message_request_TEST
