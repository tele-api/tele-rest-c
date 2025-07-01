#ifndef chat_boost_added_TEST
#define chat_boost_added_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define chat_boost_added_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/chat_boost_added.h"
chat_boost_added_t* instantiate_chat_boost_added(int include_optional);



chat_boost_added_t* instantiate_chat_boost_added(int include_optional) {
  chat_boost_added_t* chat_boost_added = NULL;
  if (include_optional) {
    chat_boost_added = chat_boost_added_create(
      56
    );
  } else {
    chat_boost_added = chat_boost_added_create(
      56
    );
  }

  return chat_boost_added;
}


#ifdef chat_boost_added_MAIN

void test_chat_boost_added(int include_optional) {
    chat_boost_added_t* chat_boost_added_1 = instantiate_chat_boost_added(include_optional);

	cJSON* jsonchat_boost_added_1 = chat_boost_added_convertToJSON(chat_boost_added_1);
	printf("chat_boost_added :\n%s\n", cJSON_Print(jsonchat_boost_added_1));
	chat_boost_added_t* chat_boost_added_2 = chat_boost_added_parseFromJSON(jsonchat_boost_added_1);
	cJSON* jsonchat_boost_added_2 = chat_boost_added_convertToJSON(chat_boost_added_2);
	printf("repeating chat_boost_added:\n%s\n", cJSON_Print(jsonchat_boost_added_2));
}

int main() {
  test_chat_boost_added(1);
  test_chat_boost_added(0);

  printf("Hello world \n");
  return 0;
}

#endif // chat_boost_added_MAIN
#endif // chat_boost_added_TEST
