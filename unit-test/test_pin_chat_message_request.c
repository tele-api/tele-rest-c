#ifndef pin_chat_message_request_TEST
#define pin_chat_message_request_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define pin_chat_message_request_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/pin_chat_message_request.h"
pin_chat_message_request_t* instantiate_pin_chat_message_request(int include_optional);

#include "test_send_message_request_chat_id.c"


pin_chat_message_request_t* instantiate_pin_chat_message_request(int include_optional) {
  pin_chat_message_request_t* pin_chat_message_request = NULL;
  if (include_optional) {
    pin_chat_message_request = pin_chat_message_request_create(
      null,
      56,
      "0",
      1
    );
  } else {
    pin_chat_message_request = pin_chat_message_request_create(
      null,
      56,
      "0",
      1
    );
  }

  return pin_chat_message_request;
}


#ifdef pin_chat_message_request_MAIN

void test_pin_chat_message_request(int include_optional) {
    pin_chat_message_request_t* pin_chat_message_request_1 = instantiate_pin_chat_message_request(include_optional);

	cJSON* jsonpin_chat_message_request_1 = pin_chat_message_request_convertToJSON(pin_chat_message_request_1);
	printf("pin_chat_message_request :\n%s\n", cJSON_Print(jsonpin_chat_message_request_1));
	pin_chat_message_request_t* pin_chat_message_request_2 = pin_chat_message_request_parseFromJSON(jsonpin_chat_message_request_1);
	cJSON* jsonpin_chat_message_request_2 = pin_chat_message_request_convertToJSON(pin_chat_message_request_2);
	printf("repeating pin_chat_message_request:\n%s\n", cJSON_Print(jsonpin_chat_message_request_2));
}

int main() {
  test_pin_chat_message_request(1);
  test_pin_chat_message_request(0);

  printf("Hello world \n");
  return 0;
}

#endif // pin_chat_message_request_MAIN
#endif // pin_chat_message_request_TEST
