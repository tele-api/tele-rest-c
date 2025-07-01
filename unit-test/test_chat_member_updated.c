#ifndef chat_member_updated_TEST
#define chat_member_updated_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define chat_member_updated_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/chat_member_updated.h"
chat_member_updated_t* instantiate_chat_member_updated(int include_optional);

#include "test_chat.c"
#include "test_user.c"
#include "test_chat_member.c"
#include "test_chat_member.c"
#include "test_chat_invite_link.c"


chat_member_updated_t* instantiate_chat_member_updated(int include_optional) {
  chat_member_updated_t* chat_member_updated = NULL;
  if (include_optional) {
    chat_member_updated = chat_member_updated_create(
       // false, not to have infinite recursion
      instantiate_chat(0),
       // false, not to have infinite recursion
      instantiate_user(0),
      56,
      null,
      null,
       // false, not to have infinite recursion
      instantiate_chat_invite_link(0),
      1,
      1
    );
  } else {
    chat_member_updated = chat_member_updated_create(
      NULL,
      NULL,
      56,
      null,
      null,
      NULL,
      1,
      1
    );
  }

  return chat_member_updated;
}


#ifdef chat_member_updated_MAIN

void test_chat_member_updated(int include_optional) {
    chat_member_updated_t* chat_member_updated_1 = instantiate_chat_member_updated(include_optional);

	cJSON* jsonchat_member_updated_1 = chat_member_updated_convertToJSON(chat_member_updated_1);
	printf("chat_member_updated :\n%s\n", cJSON_Print(jsonchat_member_updated_1));
	chat_member_updated_t* chat_member_updated_2 = chat_member_updated_parseFromJSON(jsonchat_member_updated_1);
	cJSON* jsonchat_member_updated_2 = chat_member_updated_convertToJSON(chat_member_updated_2);
	printf("repeating chat_member_updated:\n%s\n", cJSON_Print(jsonchat_member_updated_2));
}

int main() {
  test_chat_member_updated(1);
  test_chat_member_updated(0);

  printf("Hello world \n");
  return 0;
}

#endif // chat_member_updated_MAIN
#endif // chat_member_updated_TEST
