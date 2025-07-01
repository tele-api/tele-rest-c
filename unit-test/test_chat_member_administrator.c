#ifndef chat_member_administrator_TEST
#define chat_member_administrator_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define chat_member_administrator_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/chat_member_administrator.h"
chat_member_administrator_t* instantiate_chat_member_administrator(int include_optional);

#include "test_user.c"


chat_member_administrator_t* instantiate_chat_member_administrator(int include_optional) {
  chat_member_administrator_t* chat_member_administrator = NULL;
  if (include_optional) {
    chat_member_administrator = chat_member_administrator_create(
      "administrator",
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
      1,
      1,
      "0"
    );
  } else {
    chat_member_administrator = chat_member_administrator_create(
      "administrator",
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
      1,
      1,
      "0"
    );
  }

  return chat_member_administrator;
}


#ifdef chat_member_administrator_MAIN

void test_chat_member_administrator(int include_optional) {
    chat_member_administrator_t* chat_member_administrator_1 = instantiate_chat_member_administrator(include_optional);

	cJSON* jsonchat_member_administrator_1 = chat_member_administrator_convertToJSON(chat_member_administrator_1);
	printf("chat_member_administrator :\n%s\n", cJSON_Print(jsonchat_member_administrator_1));
	chat_member_administrator_t* chat_member_administrator_2 = chat_member_administrator_parseFromJSON(jsonchat_member_administrator_1);
	cJSON* jsonchat_member_administrator_2 = chat_member_administrator_convertToJSON(chat_member_administrator_2);
	printf("repeating chat_member_administrator:\n%s\n", cJSON_Print(jsonchat_member_administrator_2));
}

int main() {
  test_chat_member_administrator(1);
  test_chat_member_administrator(0);

  printf("Hello world \n");
  return 0;
}

#endif // chat_member_administrator_MAIN
#endif // chat_member_administrator_TEST
