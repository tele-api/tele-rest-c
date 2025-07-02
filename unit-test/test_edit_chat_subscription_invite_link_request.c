#ifndef edit_chat_subscription_invite_link_request_TEST
#define edit_chat_subscription_invite_link_request_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define edit_chat_subscription_invite_link_request_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/edit_chat_subscription_invite_link_request.h"
edit_chat_subscription_invite_link_request_t* instantiate_edit_chat_subscription_invite_link_request(int include_optional);

#include "test_send_message_request_chat_id.c"


edit_chat_subscription_invite_link_request_t* instantiate_edit_chat_subscription_invite_link_request(int include_optional) {
  edit_chat_subscription_invite_link_request_t* edit_chat_subscription_invite_link_request = NULL;
  if (include_optional) {
    edit_chat_subscription_invite_link_request = edit_chat_subscription_invite_link_request_create(
      null,
      "0",
      "0"
    );
  } else {
    edit_chat_subscription_invite_link_request = edit_chat_subscription_invite_link_request_create(
      null,
      "0",
      "0"
    );
  }

  return edit_chat_subscription_invite_link_request;
}


#ifdef edit_chat_subscription_invite_link_request_MAIN

void test_edit_chat_subscription_invite_link_request(int include_optional) {
    edit_chat_subscription_invite_link_request_t* edit_chat_subscription_invite_link_request_1 = instantiate_edit_chat_subscription_invite_link_request(include_optional);

	cJSON* jsonedit_chat_subscription_invite_link_request_1 = edit_chat_subscription_invite_link_request_convertToJSON(edit_chat_subscription_invite_link_request_1);
	printf("edit_chat_subscription_invite_link_request :\n%s\n", cJSON_Print(jsonedit_chat_subscription_invite_link_request_1));
	edit_chat_subscription_invite_link_request_t* edit_chat_subscription_invite_link_request_2 = edit_chat_subscription_invite_link_request_parseFromJSON(jsonedit_chat_subscription_invite_link_request_1);
	cJSON* jsonedit_chat_subscription_invite_link_request_2 = edit_chat_subscription_invite_link_request_convertToJSON(edit_chat_subscription_invite_link_request_2);
	printf("repeating edit_chat_subscription_invite_link_request:\n%s\n", cJSON_Print(jsonedit_chat_subscription_invite_link_request_2));
}

int main() {
  test_edit_chat_subscription_invite_link_request(1);
  test_edit_chat_subscription_invite_link_request(0);

  printf("Hello world \n");
  return 0;
}

#endif // edit_chat_subscription_invite_link_request_MAIN
#endif // edit_chat_subscription_invite_link_request_TEST
