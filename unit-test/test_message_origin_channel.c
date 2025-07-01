#ifndef message_origin_channel_TEST
#define message_origin_channel_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define message_origin_channel_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/message_origin_channel.h"
message_origin_channel_t* instantiate_message_origin_channel(int include_optional);

#include "test_chat.c"


message_origin_channel_t* instantiate_message_origin_channel(int include_optional) {
  message_origin_channel_t* message_origin_channel = NULL;
  if (include_optional) {
    message_origin_channel = message_origin_channel_create(
      "channel",
      56,
       // false, not to have infinite recursion
      instantiate_chat(0),
      56,
      "0"
    );
  } else {
    message_origin_channel = message_origin_channel_create(
      "channel",
      56,
      NULL,
      56,
      "0"
    );
  }

  return message_origin_channel;
}


#ifdef message_origin_channel_MAIN

void test_message_origin_channel(int include_optional) {
    message_origin_channel_t* message_origin_channel_1 = instantiate_message_origin_channel(include_optional);

	cJSON* jsonmessage_origin_channel_1 = message_origin_channel_convertToJSON(message_origin_channel_1);
	printf("message_origin_channel :\n%s\n", cJSON_Print(jsonmessage_origin_channel_1));
	message_origin_channel_t* message_origin_channel_2 = message_origin_channel_parseFromJSON(jsonmessage_origin_channel_1);
	cJSON* jsonmessage_origin_channel_2 = message_origin_channel_convertToJSON(message_origin_channel_2);
	printf("repeating message_origin_channel:\n%s\n", cJSON_Print(jsonmessage_origin_channel_2));
}

int main() {
  test_message_origin_channel(1);
  test_message_origin_channel(0);

  printf("Hello world \n");
  return 0;
}

#endif // message_origin_channel_MAIN
#endif // message_origin_channel_TEST
