#ifndef chat_boost_source_giveaway_TEST
#define chat_boost_source_giveaway_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define chat_boost_source_giveaway_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/chat_boost_source_giveaway.h"
chat_boost_source_giveaway_t* instantiate_chat_boost_source_giveaway(int include_optional);

#include "test_user.c"


chat_boost_source_giveaway_t* instantiate_chat_boost_source_giveaway(int include_optional) {
  chat_boost_source_giveaway_t* chat_boost_source_giveaway = NULL;
  if (include_optional) {
    chat_boost_source_giveaway = chat_boost_source_giveaway_create(
      "giveaway",
      56,
       // false, not to have infinite recursion
      instantiate_user(0),
      56,
      1
    );
  } else {
    chat_boost_source_giveaway = chat_boost_source_giveaway_create(
      "giveaway",
      56,
      NULL,
      56,
      1
    );
  }

  return chat_boost_source_giveaway;
}


#ifdef chat_boost_source_giveaway_MAIN

void test_chat_boost_source_giveaway(int include_optional) {
    chat_boost_source_giveaway_t* chat_boost_source_giveaway_1 = instantiate_chat_boost_source_giveaway(include_optional);

	cJSON* jsonchat_boost_source_giveaway_1 = chat_boost_source_giveaway_convertToJSON(chat_boost_source_giveaway_1);
	printf("chat_boost_source_giveaway :\n%s\n", cJSON_Print(jsonchat_boost_source_giveaway_1));
	chat_boost_source_giveaway_t* chat_boost_source_giveaway_2 = chat_boost_source_giveaway_parseFromJSON(jsonchat_boost_source_giveaway_1);
	cJSON* jsonchat_boost_source_giveaway_2 = chat_boost_source_giveaway_convertToJSON(chat_boost_source_giveaway_2);
	printf("repeating chat_boost_source_giveaway:\n%s\n", cJSON_Print(jsonchat_boost_source_giveaway_2));
}

int main() {
  test_chat_boost_source_giveaway(1);
  test_chat_boost_source_giveaway(0);

  printf("Hello world \n");
  return 0;
}

#endif // chat_boost_source_giveaway_MAIN
#endif // chat_boost_source_giveaway_TEST
