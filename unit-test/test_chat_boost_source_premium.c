#ifndef chat_boost_source_premium_TEST
#define chat_boost_source_premium_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define chat_boost_source_premium_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/chat_boost_source_premium.h"
chat_boost_source_premium_t* instantiate_chat_boost_source_premium(int include_optional);

#include "test_user.c"


chat_boost_source_premium_t* instantiate_chat_boost_source_premium(int include_optional) {
  chat_boost_source_premium_t* chat_boost_source_premium = NULL;
  if (include_optional) {
    chat_boost_source_premium = chat_boost_source_premium_create(
      "premium",
       // false, not to have infinite recursion
      instantiate_user(0)
    );
  } else {
    chat_boost_source_premium = chat_boost_source_premium_create(
      "premium",
      NULL
    );
  }

  return chat_boost_source_premium;
}


#ifdef chat_boost_source_premium_MAIN

void test_chat_boost_source_premium(int include_optional) {
    chat_boost_source_premium_t* chat_boost_source_premium_1 = instantiate_chat_boost_source_premium(include_optional);

	cJSON* jsonchat_boost_source_premium_1 = chat_boost_source_premium_convertToJSON(chat_boost_source_premium_1);
	printf("chat_boost_source_premium :\n%s\n", cJSON_Print(jsonchat_boost_source_premium_1));
	chat_boost_source_premium_t* chat_boost_source_premium_2 = chat_boost_source_premium_parseFromJSON(jsonchat_boost_source_premium_1);
	cJSON* jsonchat_boost_source_premium_2 = chat_boost_source_premium_convertToJSON(chat_boost_source_premium_2);
	printf("repeating chat_boost_source_premium:\n%s\n", cJSON_Print(jsonchat_boost_source_premium_2));
}

int main() {
  test_chat_boost_source_premium(1);
  test_chat_boost_source_premium(0);

  printf("Hello world \n");
  return 0;
}

#endif // chat_boost_source_premium_MAIN
#endif // chat_boost_source_premium_TEST
