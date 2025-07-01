#ifndef chat_member_restricted_TEST
#define chat_member_restricted_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define chat_member_restricted_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/chat_member_restricted.h"
chat_member_restricted_t* instantiate_chat_member_restricted(int include_optional);

#include "test_user.c"


chat_member_restricted_t* instantiate_chat_member_restricted(int include_optional) {
  chat_member_restricted_t* chat_member_restricted = NULL;
  if (include_optional) {
    chat_member_restricted = chat_member_restricted_create(
      "restricted",
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
      56
    );
  } else {
    chat_member_restricted = chat_member_restricted_create(
      "restricted",
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
      56
    );
  }

  return chat_member_restricted;
}


#ifdef chat_member_restricted_MAIN

void test_chat_member_restricted(int include_optional) {
    chat_member_restricted_t* chat_member_restricted_1 = instantiate_chat_member_restricted(include_optional);

	cJSON* jsonchat_member_restricted_1 = chat_member_restricted_convertToJSON(chat_member_restricted_1);
	printf("chat_member_restricted :\n%s\n", cJSON_Print(jsonchat_member_restricted_1));
	chat_member_restricted_t* chat_member_restricted_2 = chat_member_restricted_parseFromJSON(jsonchat_member_restricted_1);
	cJSON* jsonchat_member_restricted_2 = chat_member_restricted_convertToJSON(chat_member_restricted_2);
	printf("repeating chat_member_restricted:\n%s\n", cJSON_Print(jsonchat_member_restricted_2));
}

int main() {
  test_chat_member_restricted(1);
  test_chat_member_restricted(0);

  printf("Hello world \n");
  return 0;
}

#endif // chat_member_restricted_MAIN
#endif // chat_member_restricted_TEST
