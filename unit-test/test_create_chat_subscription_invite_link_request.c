#ifndef create_chat_subscription_invite_link_request_TEST
#define create_chat_subscription_invite_link_request_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define create_chat_subscription_invite_link_request_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/create_chat_subscription_invite_link_request.h"
create_chat_subscription_invite_link_request_t* instantiate_create_chat_subscription_invite_link_request(int include_optional);

#include "test_create_chat_subscription_invite_link_request_chat_id.c"


create_chat_subscription_invite_link_request_t* instantiate_create_chat_subscription_invite_link_request(int include_optional) {
  create_chat_subscription_invite_link_request_t* create_chat_subscription_invite_link_request = NULL;
  if (include_optional) {
    create_chat_subscription_invite_link_request = create_chat_subscription_invite_link_request_create(
      null,
      56,
      56,
      "0"
    );
  } else {
    create_chat_subscription_invite_link_request = create_chat_subscription_invite_link_request_create(
      null,
      56,
      56,
      "0"
    );
  }

  return create_chat_subscription_invite_link_request;
}


#ifdef create_chat_subscription_invite_link_request_MAIN

void test_create_chat_subscription_invite_link_request(int include_optional) {
    create_chat_subscription_invite_link_request_t* create_chat_subscription_invite_link_request_1 = instantiate_create_chat_subscription_invite_link_request(include_optional);

	cJSON* jsoncreate_chat_subscription_invite_link_request_1 = create_chat_subscription_invite_link_request_convertToJSON(create_chat_subscription_invite_link_request_1);
	printf("create_chat_subscription_invite_link_request :\n%s\n", cJSON_Print(jsoncreate_chat_subscription_invite_link_request_1));
	create_chat_subscription_invite_link_request_t* create_chat_subscription_invite_link_request_2 = create_chat_subscription_invite_link_request_parseFromJSON(jsoncreate_chat_subscription_invite_link_request_1);
	cJSON* jsoncreate_chat_subscription_invite_link_request_2 = create_chat_subscription_invite_link_request_convertToJSON(create_chat_subscription_invite_link_request_2);
	printf("repeating create_chat_subscription_invite_link_request:\n%s\n", cJSON_Print(jsoncreate_chat_subscription_invite_link_request_2));
}

int main() {
  test_create_chat_subscription_invite_link_request(1);
  test_create_chat_subscription_invite_link_request(0);

  printf("Hello world \n");
  return 0;
}

#endif // create_chat_subscription_invite_link_request_MAIN
#endif // create_chat_subscription_invite_link_request_TEST
