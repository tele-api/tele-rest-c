#ifndef chat_join_request_TEST
#define chat_join_request_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define chat_join_request_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/chat_join_request.h"
chat_join_request_t* instantiate_chat_join_request(int include_optional);

#include "test_chat.c"
#include "test_user.c"
#include "test_chat_invite_link.c"


chat_join_request_t* instantiate_chat_join_request(int include_optional) {
  chat_join_request_t* chat_join_request = NULL;
  if (include_optional) {
    chat_join_request = chat_join_request_create(
       // false, not to have infinite recursion
      instantiate_chat(0),
       // false, not to have infinite recursion
      instantiate_user(0),
      56,
      56,
      "0",
       // false, not to have infinite recursion
      instantiate_chat_invite_link(0)
    );
  } else {
    chat_join_request = chat_join_request_create(
      NULL,
      NULL,
      56,
      56,
      "0",
      NULL
    );
  }

  return chat_join_request;
}


#ifdef chat_join_request_MAIN

void test_chat_join_request(int include_optional) {
    chat_join_request_t* chat_join_request_1 = instantiate_chat_join_request(include_optional);

	cJSON* jsonchat_join_request_1 = chat_join_request_convertToJSON(chat_join_request_1);
	printf("chat_join_request :\n%s\n", cJSON_Print(jsonchat_join_request_1));
	chat_join_request_t* chat_join_request_2 = chat_join_request_parseFromJSON(jsonchat_join_request_1);
	cJSON* jsonchat_join_request_2 = chat_join_request_convertToJSON(chat_join_request_2);
	printf("repeating chat_join_request:\n%s\n", cJSON_Print(jsonchat_join_request_2));
}

int main() {
  test_chat_join_request(1);
  test_chat_join_request(0);

  printf("Hello world \n");
  return 0;
}

#endif // chat_join_request_MAIN
#endif // chat_join_request_TEST
