#ifndef chat_member_TEST
#define chat_member_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define chat_member_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/chat_member.h"
chat_member_t* instantiate_chat_member(int include_optional);

#include "test_user.c"


chat_member_t* instantiate_chat_member(int include_optional) {
  chat_member_t* chat_member = NULL;
  if (include_optional) {
    chat_member = chat_member_create(
      "kicked",
       // false, not to have infinite recursion
      instantiate_user(0),
      1,
      1,
      1,
      1,
      1,
      1,
      1,
      1,
      1,
      1,
      1,
      1,
      1,
      1,
      56,
      1,
      1,
      1,
      1,
      1,
      1,
      1,
      1,
      1,
      1,
      1,
      "0",
      1,
      1
    );
  } else {
    chat_member = chat_member_create(
      "kicked",
      NULL,
      1,
      1,
      1,
      1,
      1,
      1,
      1,
      1,
      1,
      1,
      1,
      1,
      1,
      1,
      56,
      1,
      1,
      1,
      1,
      1,
      1,
      1,
      1,
      1,
      1,
      1,
      "0",
      1,
      1
    );
  }

  return chat_member;
}


#ifdef chat_member_MAIN

void test_chat_member(int include_optional) {
    chat_member_t* chat_member_1 = instantiate_chat_member(include_optional);

	cJSON* jsonchat_member_1 = chat_member_convertToJSON(chat_member_1);
	printf("chat_member :\n%s\n", cJSON_Print(jsonchat_member_1));
	chat_member_t* chat_member_2 = chat_member_parseFromJSON(jsonchat_member_1);
	cJSON* jsonchat_member_2 = chat_member_convertToJSON(chat_member_2);
	printf("repeating chat_member:\n%s\n", cJSON_Print(jsonchat_member_2));
}

int main() {
  test_chat_member(1);
  test_chat_member(0);

  printf("Hello world \n");
  return 0;
}

#endif // chat_member_MAIN
#endif // chat_member_TEST
