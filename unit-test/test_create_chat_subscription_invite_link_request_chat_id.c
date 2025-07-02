#ifndef create_chat_subscription_invite_link_request_chat_id_TEST
#define create_chat_subscription_invite_link_request_chat_id_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define create_chat_subscription_invite_link_request_chat_id_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/create_chat_subscription_invite_link_request_chat_id.h"
create_chat_subscription_invite_link_request_chat_id_t* instantiate_create_chat_subscription_invite_link_request_chat_id(int include_optional);



create_chat_subscription_invite_link_request_chat_id_t* instantiate_create_chat_subscription_invite_link_request_chat_id(int include_optional) {
  create_chat_subscription_invite_link_request_chat_id_t* create_chat_subscription_invite_link_request_chat_id = NULL;
  if (include_optional) {
    create_chat_subscription_invite_link_request_chat_id = create_chat_subscription_invite_link_request_chat_id_create(
    );
  } else {
    create_chat_subscription_invite_link_request_chat_id = create_chat_subscription_invite_link_request_chat_id_create(
    );
  }

  return create_chat_subscription_invite_link_request_chat_id;
}


#ifdef create_chat_subscription_invite_link_request_chat_id_MAIN

void test_create_chat_subscription_invite_link_request_chat_id(int include_optional) {
    create_chat_subscription_invite_link_request_chat_id_t* create_chat_subscription_invite_link_request_chat_id_1 = instantiate_create_chat_subscription_invite_link_request_chat_id(include_optional);

	cJSON* jsoncreate_chat_subscription_invite_link_request_chat_id_1 = create_chat_subscription_invite_link_request_chat_id_convertToJSON(create_chat_subscription_invite_link_request_chat_id_1);
	printf("create_chat_subscription_invite_link_request_chat_id :\n%s\n", cJSON_Print(jsoncreate_chat_subscription_invite_link_request_chat_id_1));
	create_chat_subscription_invite_link_request_chat_id_t* create_chat_subscription_invite_link_request_chat_id_2 = create_chat_subscription_invite_link_request_chat_id_parseFromJSON(jsoncreate_chat_subscription_invite_link_request_chat_id_1);
	cJSON* jsoncreate_chat_subscription_invite_link_request_chat_id_2 = create_chat_subscription_invite_link_request_chat_id_convertToJSON(create_chat_subscription_invite_link_request_chat_id_2);
	printf("repeating create_chat_subscription_invite_link_request_chat_id:\n%s\n", cJSON_Print(jsoncreate_chat_subscription_invite_link_request_chat_id_2));
}

int main() {
  test_create_chat_subscription_invite_link_request_chat_id(1);
  test_create_chat_subscription_invite_link_request_chat_id(0);

  printf("Hello world \n");
  return 0;
}

#endif // create_chat_subscription_invite_link_request_chat_id_MAIN
#endif // create_chat_subscription_invite_link_request_chat_id_TEST
