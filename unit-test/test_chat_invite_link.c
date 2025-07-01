#ifndef chat_invite_link_TEST
#define chat_invite_link_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define chat_invite_link_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/chat_invite_link.h"
chat_invite_link_t* instantiate_chat_invite_link(int include_optional);

#include "test_user.c"


chat_invite_link_t* instantiate_chat_invite_link(int include_optional) {
  chat_invite_link_t* chat_invite_link = NULL;
  if (include_optional) {
    chat_invite_link = chat_invite_link_create(
      "0",
       // false, not to have infinite recursion
      instantiate_user(0),
      1,
      1,
      1,
      "0",
      56,
      56,
      56,
      56,
      56
    );
  } else {
    chat_invite_link = chat_invite_link_create(
      "0",
      NULL,
      1,
      1,
      1,
      "0",
      56,
      56,
      56,
      56,
      56
    );
  }

  return chat_invite_link;
}


#ifdef chat_invite_link_MAIN

void test_chat_invite_link(int include_optional) {
    chat_invite_link_t* chat_invite_link_1 = instantiate_chat_invite_link(include_optional);

	cJSON* jsonchat_invite_link_1 = chat_invite_link_convertToJSON(chat_invite_link_1);
	printf("chat_invite_link :\n%s\n", cJSON_Print(jsonchat_invite_link_1));
	chat_invite_link_t* chat_invite_link_2 = chat_invite_link_parseFromJSON(jsonchat_invite_link_1);
	cJSON* jsonchat_invite_link_2 = chat_invite_link_convertToJSON(chat_invite_link_2);
	printf("repeating chat_invite_link:\n%s\n", cJSON_Print(jsonchat_invite_link_2));
}

int main() {
  test_chat_invite_link(1);
  test_chat_invite_link(0);

  printf("Hello world \n");
  return 0;
}

#endif // chat_invite_link_MAIN
#endif // chat_invite_link_TEST
