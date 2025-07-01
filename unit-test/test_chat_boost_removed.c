#ifndef chat_boost_removed_TEST
#define chat_boost_removed_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define chat_boost_removed_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/chat_boost_removed.h"
chat_boost_removed_t* instantiate_chat_boost_removed(int include_optional);

#include "test_chat.c"
#include "test_chat_boost_source.c"


chat_boost_removed_t* instantiate_chat_boost_removed(int include_optional) {
  chat_boost_removed_t* chat_boost_removed = NULL;
  if (include_optional) {
    chat_boost_removed = chat_boost_removed_create(
       // false, not to have infinite recursion
      instantiate_chat(0),
      "0",
      56,
      null
    );
  } else {
    chat_boost_removed = chat_boost_removed_create(
      NULL,
      "0",
      56,
      null
    );
  }

  return chat_boost_removed;
}


#ifdef chat_boost_removed_MAIN

void test_chat_boost_removed(int include_optional) {
    chat_boost_removed_t* chat_boost_removed_1 = instantiate_chat_boost_removed(include_optional);

	cJSON* jsonchat_boost_removed_1 = chat_boost_removed_convertToJSON(chat_boost_removed_1);
	printf("chat_boost_removed :\n%s\n", cJSON_Print(jsonchat_boost_removed_1));
	chat_boost_removed_t* chat_boost_removed_2 = chat_boost_removed_parseFromJSON(jsonchat_boost_removed_1);
	cJSON* jsonchat_boost_removed_2 = chat_boost_removed_convertToJSON(chat_boost_removed_2);
	printf("repeating chat_boost_removed:\n%s\n", cJSON_Print(jsonchat_boost_removed_2));
}

int main() {
  test_chat_boost_removed(1);
  test_chat_boost_removed(0);

  printf("Hello world \n");
  return 0;
}

#endif // chat_boost_removed_MAIN
#endif // chat_boost_removed_TEST
