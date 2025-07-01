#ifndef message_entity_TEST
#define message_entity_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define message_entity_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/message_entity.h"
message_entity_t* instantiate_message_entity(int include_optional);

#include "test_user.c"


message_entity_t* instantiate_message_entity(int include_optional) {
  message_entity_t* message_entity = NULL;
  if (include_optional) {
    message_entity = message_entity_create(
      telegram_bot_api_message_entity_TYPE_mention,
      56,
      56,
      "0",
       // false, not to have infinite recursion
      instantiate_user(0),
      "0",
      "0"
    );
  } else {
    message_entity = message_entity_create(
      telegram_bot_api_message_entity_TYPE_mention,
      56,
      56,
      "0",
      NULL,
      "0",
      "0"
    );
  }

  return message_entity;
}


#ifdef message_entity_MAIN

void test_message_entity(int include_optional) {
    message_entity_t* message_entity_1 = instantiate_message_entity(include_optional);

	cJSON* jsonmessage_entity_1 = message_entity_convertToJSON(message_entity_1);
	printf("message_entity :\n%s\n", cJSON_Print(jsonmessage_entity_1));
	message_entity_t* message_entity_2 = message_entity_parseFromJSON(jsonmessage_entity_1);
	cJSON* jsonmessage_entity_2 = message_entity_convertToJSON(message_entity_2);
	printf("repeating message_entity:\n%s\n", cJSON_Print(jsonmessage_entity_2));
}

int main() {
  test_message_entity(1);
  test_message_entity(0);

  printf("Hello world \n");
  return 0;
}

#endif // message_entity_MAIN
#endif // message_entity_TEST
