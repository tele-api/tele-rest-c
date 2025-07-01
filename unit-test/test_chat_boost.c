#ifndef chat_boost_TEST
#define chat_boost_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define chat_boost_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/chat_boost.h"
chat_boost_t* instantiate_chat_boost(int include_optional);

#include "test_chat_boost_source.c"


chat_boost_t* instantiate_chat_boost(int include_optional) {
  chat_boost_t* chat_boost = NULL;
  if (include_optional) {
    chat_boost = chat_boost_create(
      "0",
      56,
      56,
      null
    );
  } else {
    chat_boost = chat_boost_create(
      "0",
      56,
      56,
      null
    );
  }

  return chat_boost;
}


#ifdef chat_boost_MAIN

void test_chat_boost(int include_optional) {
    chat_boost_t* chat_boost_1 = instantiate_chat_boost(include_optional);

	cJSON* jsonchat_boost_1 = chat_boost_convertToJSON(chat_boost_1);
	printf("chat_boost :\n%s\n", cJSON_Print(jsonchat_boost_1));
	chat_boost_t* chat_boost_2 = chat_boost_parseFromJSON(jsonchat_boost_1);
	cJSON* jsonchat_boost_2 = chat_boost_convertToJSON(chat_boost_2);
	printf("repeating chat_boost:\n%s\n", cJSON_Print(jsonchat_boost_2));
}

int main() {
  test_chat_boost(1);
  test_chat_boost(0);

  printf("Hello world \n");
  return 0;
}

#endif // chat_boost_MAIN
#endif // chat_boost_TEST
