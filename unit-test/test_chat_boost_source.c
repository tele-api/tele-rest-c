#ifndef chat_boost_source_TEST
#define chat_boost_source_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define chat_boost_source_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/chat_boost_source.h"
chat_boost_source_t* instantiate_chat_boost_source(int include_optional);

#include "test_user.c"


chat_boost_source_t* instantiate_chat_boost_source(int include_optional) {
  chat_boost_source_t* chat_boost_source = NULL;
  if (include_optional) {
    chat_boost_source = chat_boost_source_create(
      "giveaway",
       // false, not to have infinite recursion
      instantiate_user(0),
      56,
      56,
      1
    );
  } else {
    chat_boost_source = chat_boost_source_create(
      "giveaway",
      NULL,
      56,
      56,
      1
    );
  }

  return chat_boost_source;
}


#ifdef chat_boost_source_MAIN

void test_chat_boost_source(int include_optional) {
    chat_boost_source_t* chat_boost_source_1 = instantiate_chat_boost_source(include_optional);

	cJSON* jsonchat_boost_source_1 = chat_boost_source_convertToJSON(chat_boost_source_1);
	printf("chat_boost_source :\n%s\n", cJSON_Print(jsonchat_boost_source_1));
	chat_boost_source_t* chat_boost_source_2 = chat_boost_source_parseFromJSON(jsonchat_boost_source_1);
	cJSON* jsonchat_boost_source_2 = chat_boost_source_convertToJSON(chat_boost_source_2);
	printf("repeating chat_boost_source:\n%s\n", cJSON_Print(jsonchat_boost_source_2));
}

int main() {
  test_chat_boost_source(1);
  test_chat_boost_source(0);

  printf("Hello world \n");
  return 0;
}

#endif // chat_boost_source_MAIN
#endif // chat_boost_source_TEST
