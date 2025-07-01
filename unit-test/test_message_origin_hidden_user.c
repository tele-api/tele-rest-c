#ifndef message_origin_hidden_user_TEST
#define message_origin_hidden_user_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define message_origin_hidden_user_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/message_origin_hidden_user.h"
message_origin_hidden_user_t* instantiate_message_origin_hidden_user(int include_optional);



message_origin_hidden_user_t* instantiate_message_origin_hidden_user(int include_optional) {
  message_origin_hidden_user_t* message_origin_hidden_user = NULL;
  if (include_optional) {
    message_origin_hidden_user = message_origin_hidden_user_create(
      "hidden_user",
      56,
      "0"
    );
  } else {
    message_origin_hidden_user = message_origin_hidden_user_create(
      "hidden_user",
      56,
      "0"
    );
  }

  return message_origin_hidden_user;
}


#ifdef message_origin_hidden_user_MAIN

void test_message_origin_hidden_user(int include_optional) {
    message_origin_hidden_user_t* message_origin_hidden_user_1 = instantiate_message_origin_hidden_user(include_optional);

	cJSON* jsonmessage_origin_hidden_user_1 = message_origin_hidden_user_convertToJSON(message_origin_hidden_user_1);
	printf("message_origin_hidden_user :\n%s\n", cJSON_Print(jsonmessage_origin_hidden_user_1));
	message_origin_hidden_user_t* message_origin_hidden_user_2 = message_origin_hidden_user_parseFromJSON(jsonmessage_origin_hidden_user_1);
	cJSON* jsonmessage_origin_hidden_user_2 = message_origin_hidden_user_convertToJSON(message_origin_hidden_user_2);
	printf("repeating message_origin_hidden_user:\n%s\n", cJSON_Print(jsonmessage_origin_hidden_user_2));
}

int main() {
  test_message_origin_hidden_user(1);
  test_message_origin_hidden_user(0);

  printf("Hello world \n");
  return 0;
}

#endif // message_origin_hidden_user_MAIN
#endif // message_origin_hidden_user_TEST
