#ifndef chat_location_TEST
#define chat_location_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define chat_location_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/chat_location.h"
chat_location_t* instantiate_chat_location(int include_optional);

#include "test_location.c"


chat_location_t* instantiate_chat_location(int include_optional) {
  chat_location_t* chat_location = NULL;
  if (include_optional) {
    chat_location = chat_location_create(
       // false, not to have infinite recursion
      instantiate_location(0),
      "0"
    );
  } else {
    chat_location = chat_location_create(
      NULL,
      "0"
    );
  }

  return chat_location;
}


#ifdef chat_location_MAIN

void test_chat_location(int include_optional) {
    chat_location_t* chat_location_1 = instantiate_chat_location(include_optional);

	cJSON* jsonchat_location_1 = chat_location_convertToJSON(chat_location_1);
	printf("chat_location :\n%s\n", cJSON_Print(jsonchat_location_1));
	chat_location_t* chat_location_2 = chat_location_parseFromJSON(jsonchat_location_1);
	cJSON* jsonchat_location_2 = chat_location_convertToJSON(chat_location_2);
	printf("repeating chat_location:\n%s\n", cJSON_Print(jsonchat_location_2));
}

int main() {
  test_chat_location(1);
  test_chat_location(0);

  printf("Hello world \n");
  return 0;
}

#endif // chat_location_MAIN
#endif // chat_location_TEST
