#ifndef chat_boost_updated_TEST
#define chat_boost_updated_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define chat_boost_updated_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/chat_boost_updated.h"
chat_boost_updated_t* instantiate_chat_boost_updated(int include_optional);

#include "test_chat.c"
#include "test_chat_boost.c"


chat_boost_updated_t* instantiate_chat_boost_updated(int include_optional) {
  chat_boost_updated_t* chat_boost_updated = NULL;
  if (include_optional) {
    chat_boost_updated = chat_boost_updated_create(
       // false, not to have infinite recursion
      instantiate_chat(0),
       // false, not to have infinite recursion
      instantiate_chat_boost(0)
    );
  } else {
    chat_boost_updated = chat_boost_updated_create(
      NULL,
      NULL
    );
  }

  return chat_boost_updated;
}


#ifdef chat_boost_updated_MAIN

void test_chat_boost_updated(int include_optional) {
    chat_boost_updated_t* chat_boost_updated_1 = instantiate_chat_boost_updated(include_optional);

	cJSON* jsonchat_boost_updated_1 = chat_boost_updated_convertToJSON(chat_boost_updated_1);
	printf("chat_boost_updated :\n%s\n", cJSON_Print(jsonchat_boost_updated_1));
	chat_boost_updated_t* chat_boost_updated_2 = chat_boost_updated_parseFromJSON(jsonchat_boost_updated_1);
	cJSON* jsonchat_boost_updated_2 = chat_boost_updated_convertToJSON(chat_boost_updated_2);
	printf("repeating chat_boost_updated:\n%s\n", cJSON_Print(jsonchat_boost_updated_2));
}

int main() {
  test_chat_boost_updated(1);
  test_chat_boost_updated(0);

  printf("Hello world \n");
  return 0;
}

#endif // chat_boost_updated_MAIN
#endif // chat_boost_updated_TEST
