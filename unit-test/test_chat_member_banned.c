#ifndef chat_member_banned_TEST
#define chat_member_banned_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define chat_member_banned_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/chat_member_banned.h"
chat_member_banned_t* instantiate_chat_member_banned(int include_optional);

#include "test_user.c"


chat_member_banned_t* instantiate_chat_member_banned(int include_optional) {
  chat_member_banned_t* chat_member_banned = NULL;
  if (include_optional) {
    chat_member_banned = chat_member_banned_create(
      "kicked",
       // false, not to have infinite recursion
      instantiate_user(0),
      56
    );
  } else {
    chat_member_banned = chat_member_banned_create(
      "kicked",
      NULL,
      56
    );
  }

  return chat_member_banned;
}


#ifdef chat_member_banned_MAIN

void test_chat_member_banned(int include_optional) {
    chat_member_banned_t* chat_member_banned_1 = instantiate_chat_member_banned(include_optional);

	cJSON* jsonchat_member_banned_1 = chat_member_banned_convertToJSON(chat_member_banned_1);
	printf("chat_member_banned :\n%s\n", cJSON_Print(jsonchat_member_banned_1));
	chat_member_banned_t* chat_member_banned_2 = chat_member_banned_parseFromJSON(jsonchat_member_banned_1);
	cJSON* jsonchat_member_banned_2 = chat_member_banned_convertToJSON(chat_member_banned_2);
	printf("repeating chat_member_banned:\n%s\n", cJSON_Print(jsonchat_member_banned_2));
}

int main() {
  test_chat_member_banned(1);
  test_chat_member_banned(0);

  printf("Hello world \n");
  return 0;
}

#endif // chat_member_banned_MAIN
#endif // chat_member_banned_TEST
