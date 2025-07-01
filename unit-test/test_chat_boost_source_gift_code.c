#ifndef chat_boost_source_gift_code_TEST
#define chat_boost_source_gift_code_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define chat_boost_source_gift_code_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/chat_boost_source_gift_code.h"
chat_boost_source_gift_code_t* instantiate_chat_boost_source_gift_code(int include_optional);

#include "test_user.c"


chat_boost_source_gift_code_t* instantiate_chat_boost_source_gift_code(int include_optional) {
  chat_boost_source_gift_code_t* chat_boost_source_gift_code = NULL;
  if (include_optional) {
    chat_boost_source_gift_code = chat_boost_source_gift_code_create(
      "gift_code",
       // false, not to have infinite recursion
      instantiate_user(0)
    );
  } else {
    chat_boost_source_gift_code = chat_boost_source_gift_code_create(
      "gift_code",
      NULL
    );
  }

  return chat_boost_source_gift_code;
}


#ifdef chat_boost_source_gift_code_MAIN

void test_chat_boost_source_gift_code(int include_optional) {
    chat_boost_source_gift_code_t* chat_boost_source_gift_code_1 = instantiate_chat_boost_source_gift_code(include_optional);

	cJSON* jsonchat_boost_source_gift_code_1 = chat_boost_source_gift_code_convertToJSON(chat_boost_source_gift_code_1);
	printf("chat_boost_source_gift_code :\n%s\n", cJSON_Print(jsonchat_boost_source_gift_code_1));
	chat_boost_source_gift_code_t* chat_boost_source_gift_code_2 = chat_boost_source_gift_code_parseFromJSON(jsonchat_boost_source_gift_code_1);
	cJSON* jsonchat_boost_source_gift_code_2 = chat_boost_source_gift_code_convertToJSON(chat_boost_source_gift_code_2);
	printf("repeating chat_boost_source_gift_code:\n%s\n", cJSON_Print(jsonchat_boost_source_gift_code_2));
}

int main() {
  test_chat_boost_source_gift_code(1);
  test_chat_boost_source_gift_code(0);

  printf("Hello world \n");
  return 0;
}

#endif // chat_boost_source_gift_code_MAIN
#endif // chat_boost_source_gift_code_TEST
