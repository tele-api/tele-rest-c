#ifndef chat_background_TEST
#define chat_background_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define chat_background_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/chat_background.h"
chat_background_t* instantiate_chat_background(int include_optional);

#include "test_background_type.c"


chat_background_t* instantiate_chat_background(int include_optional) {
  chat_background_t* chat_background = NULL;
  if (include_optional) {
    chat_background = chat_background_create(
      null
    );
  } else {
    chat_background = chat_background_create(
      null
    );
  }

  return chat_background;
}


#ifdef chat_background_MAIN

void test_chat_background(int include_optional) {
    chat_background_t* chat_background_1 = instantiate_chat_background(include_optional);

	cJSON* jsonchat_background_1 = chat_background_convertToJSON(chat_background_1);
	printf("chat_background :\n%s\n", cJSON_Print(jsonchat_background_1));
	chat_background_t* chat_background_2 = chat_background_parseFromJSON(jsonchat_background_1);
	cJSON* jsonchat_background_2 = chat_background_convertToJSON(chat_background_2);
	printf("repeating chat_background:\n%s\n", cJSON_Print(jsonchat_background_2));
}

int main() {
  test_chat_background(1);
  test_chat_background(0);

  printf("Hello world \n");
  return 0;
}

#endif // chat_background_MAIN
#endif // chat_background_TEST
