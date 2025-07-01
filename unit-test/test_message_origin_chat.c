#ifndef message_origin_chat_TEST
#define message_origin_chat_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define message_origin_chat_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/message_origin_chat.h"
message_origin_chat_t* instantiate_message_origin_chat(int include_optional);

#include "test_chat.c"


message_origin_chat_t* instantiate_message_origin_chat(int include_optional) {
  message_origin_chat_t* message_origin_chat = NULL;
  if (include_optional) {
    message_origin_chat = message_origin_chat_create(
      "chat",
      56,
       // false, not to have infinite recursion
      instantiate_chat(0),
      "0"
    );
  } else {
    message_origin_chat = message_origin_chat_create(
      "chat",
      56,
      NULL,
      "0"
    );
  }

  return message_origin_chat;
}


#ifdef message_origin_chat_MAIN

void test_message_origin_chat(int include_optional) {
    message_origin_chat_t* message_origin_chat_1 = instantiate_message_origin_chat(include_optional);

	cJSON* jsonmessage_origin_chat_1 = message_origin_chat_convertToJSON(message_origin_chat_1);
	printf("message_origin_chat :\n%s\n", cJSON_Print(jsonmessage_origin_chat_1));
	message_origin_chat_t* message_origin_chat_2 = message_origin_chat_parseFromJSON(jsonmessage_origin_chat_1);
	cJSON* jsonmessage_origin_chat_2 = message_origin_chat_convertToJSON(message_origin_chat_2);
	printf("repeating message_origin_chat:\n%s\n", cJSON_Print(jsonmessage_origin_chat_2));
}

int main() {
  test_message_origin_chat(1);
  test_message_origin_chat(0);

  printf("Hello world \n");
  return 0;
}

#endif // message_origin_chat_MAIN
#endif // message_origin_chat_TEST
