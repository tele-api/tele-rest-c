#ifndef message_origin_TEST
#define message_origin_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define message_origin_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/message_origin.h"
message_origin_t* instantiate_message_origin(int include_optional);

#include "test_user.c"
#include "test_chat.c"
#include "test_chat.c"


message_origin_t* instantiate_message_origin(int include_optional) {
  message_origin_t* message_origin = NULL;
  if (include_optional) {
    message_origin = message_origin_create(
      "channel",
      56,
       // false, not to have infinite recursion
      instantiate_user(0),
      "0",
       // false, not to have infinite recursion
      instantiate_chat(0),
       // false, not to have infinite recursion
      instantiate_chat(0),
      56,
      "0"
    );
  } else {
    message_origin = message_origin_create(
      "channel",
      56,
      NULL,
      "0",
      NULL,
      NULL,
      56,
      "0"
    );
  }

  return message_origin;
}


#ifdef message_origin_MAIN

void test_message_origin(int include_optional) {
    message_origin_t* message_origin_1 = instantiate_message_origin(include_optional);

	cJSON* jsonmessage_origin_1 = message_origin_convertToJSON(message_origin_1);
	printf("message_origin :\n%s\n", cJSON_Print(jsonmessage_origin_1));
	message_origin_t* message_origin_2 = message_origin_parseFromJSON(jsonmessage_origin_1);
	cJSON* jsonmessage_origin_2 = message_origin_convertToJSON(message_origin_2);
	printf("repeating message_origin:\n%s\n", cJSON_Print(jsonmessage_origin_2));
}

int main() {
  test_message_origin(1);
  test_message_origin(0);

  printf("Hello world \n");
  return 0;
}

#endif // message_origin_MAIN
#endif // message_origin_TEST
