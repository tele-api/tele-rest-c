#ifndef pin_chat_message_response_TEST
#define pin_chat_message_response_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define pin_chat_message_response_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/pin_chat_message_response.h"
pin_chat_message_response_t* instantiate_pin_chat_message_response(int include_optional);



pin_chat_message_response_t* instantiate_pin_chat_message_response(int include_optional) {
  pin_chat_message_response_t* pin_chat_message_response = NULL;
  if (include_optional) {
    pin_chat_message_response = pin_chat_message_response_create(
      1,
      1
    );
  } else {
    pin_chat_message_response = pin_chat_message_response_create(
      1,
      1
    );
  }

  return pin_chat_message_response;
}


#ifdef pin_chat_message_response_MAIN

void test_pin_chat_message_response(int include_optional) {
    pin_chat_message_response_t* pin_chat_message_response_1 = instantiate_pin_chat_message_response(include_optional);

	cJSON* jsonpin_chat_message_response_1 = pin_chat_message_response_convertToJSON(pin_chat_message_response_1);
	printf("pin_chat_message_response :\n%s\n", cJSON_Print(jsonpin_chat_message_response_1));
	pin_chat_message_response_t* pin_chat_message_response_2 = pin_chat_message_response_parseFromJSON(jsonpin_chat_message_response_1);
	cJSON* jsonpin_chat_message_response_2 = pin_chat_message_response_convertToJSON(pin_chat_message_response_2);
	printf("repeating pin_chat_message_response:\n%s\n", cJSON_Print(jsonpin_chat_message_response_2));
}

int main() {
  test_pin_chat_message_response(1);
  test_pin_chat_message_response(0);

  printf("Hello world \n");
  return 0;
}

#endif // pin_chat_message_response_MAIN
#endif // pin_chat_message_response_TEST
