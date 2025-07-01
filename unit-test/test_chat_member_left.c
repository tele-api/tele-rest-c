#ifndef chat_member_left_TEST
#define chat_member_left_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define chat_member_left_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/chat_member_left.h"
chat_member_left_t* instantiate_chat_member_left(int include_optional);

#include "test_user.c"


chat_member_left_t* instantiate_chat_member_left(int include_optional) {
  chat_member_left_t* chat_member_left = NULL;
  if (include_optional) {
    chat_member_left = chat_member_left_create(
      "left",
       // false, not to have infinite recursion
      instantiate_user(0)
    );
  } else {
    chat_member_left = chat_member_left_create(
      "left",
      NULL
    );
  }

  return chat_member_left;
}


#ifdef chat_member_left_MAIN

void test_chat_member_left(int include_optional) {
    chat_member_left_t* chat_member_left_1 = instantiate_chat_member_left(include_optional);

	cJSON* jsonchat_member_left_1 = chat_member_left_convertToJSON(chat_member_left_1);
	printf("chat_member_left :\n%s\n", cJSON_Print(jsonchat_member_left_1));
	chat_member_left_t* chat_member_left_2 = chat_member_left_parseFromJSON(jsonchat_member_left_1);
	cJSON* jsonchat_member_left_2 = chat_member_left_convertToJSON(chat_member_left_2);
	printf("repeating chat_member_left:\n%s\n", cJSON_Print(jsonchat_member_left_2));
}

int main() {
  test_chat_member_left(1);
  test_chat_member_left(0);

  printf("Hello world \n");
  return 0;
}

#endif // chat_member_left_MAIN
#endif // chat_member_left_TEST
