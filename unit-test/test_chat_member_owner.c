#ifndef chat_member_owner_TEST
#define chat_member_owner_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define chat_member_owner_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/chat_member_owner.h"
chat_member_owner_t* instantiate_chat_member_owner(int include_optional);

#include "test_user.c"


chat_member_owner_t* instantiate_chat_member_owner(int include_optional) {
  chat_member_owner_t* chat_member_owner = NULL;
  if (include_optional) {
    chat_member_owner = chat_member_owner_create(
      "creator",
       // false, not to have infinite recursion
      instantiate_user(0),
      1,
      "0"
    );
  } else {
    chat_member_owner = chat_member_owner_create(
      "creator",
      NULL,
      1,
      "0"
    );
  }

  return chat_member_owner;
}


#ifdef chat_member_owner_MAIN

void test_chat_member_owner(int include_optional) {
    chat_member_owner_t* chat_member_owner_1 = instantiate_chat_member_owner(include_optional);

	cJSON* jsonchat_member_owner_1 = chat_member_owner_convertToJSON(chat_member_owner_1);
	printf("chat_member_owner :\n%s\n", cJSON_Print(jsonchat_member_owner_1));
	chat_member_owner_t* chat_member_owner_2 = chat_member_owner_parseFromJSON(jsonchat_member_owner_1);
	cJSON* jsonchat_member_owner_2 = chat_member_owner_convertToJSON(chat_member_owner_2);
	printf("repeating chat_member_owner:\n%s\n", cJSON_Print(jsonchat_member_owner_2));
}

int main() {
  test_chat_member_owner(1);
  test_chat_member_owner(0);

  printf("Hello world \n");
  return 0;
}

#endif // chat_member_owner_MAIN
#endif // chat_member_owner_TEST
