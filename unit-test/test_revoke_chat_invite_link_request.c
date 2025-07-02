#ifndef revoke_chat_invite_link_request_TEST
#define revoke_chat_invite_link_request_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define revoke_chat_invite_link_request_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/revoke_chat_invite_link_request.h"
revoke_chat_invite_link_request_t* instantiate_revoke_chat_invite_link_request(int include_optional);

#include "test_revoke_chat_invite_link_request_chat_id.c"


revoke_chat_invite_link_request_t* instantiate_revoke_chat_invite_link_request(int include_optional) {
  revoke_chat_invite_link_request_t* revoke_chat_invite_link_request = NULL;
  if (include_optional) {
    revoke_chat_invite_link_request = revoke_chat_invite_link_request_create(
      null,
      "0"
    );
  } else {
    revoke_chat_invite_link_request = revoke_chat_invite_link_request_create(
      null,
      "0"
    );
  }

  return revoke_chat_invite_link_request;
}


#ifdef revoke_chat_invite_link_request_MAIN

void test_revoke_chat_invite_link_request(int include_optional) {
    revoke_chat_invite_link_request_t* revoke_chat_invite_link_request_1 = instantiate_revoke_chat_invite_link_request(include_optional);

	cJSON* jsonrevoke_chat_invite_link_request_1 = revoke_chat_invite_link_request_convertToJSON(revoke_chat_invite_link_request_1);
	printf("revoke_chat_invite_link_request :\n%s\n", cJSON_Print(jsonrevoke_chat_invite_link_request_1));
	revoke_chat_invite_link_request_t* revoke_chat_invite_link_request_2 = revoke_chat_invite_link_request_parseFromJSON(jsonrevoke_chat_invite_link_request_1);
	cJSON* jsonrevoke_chat_invite_link_request_2 = revoke_chat_invite_link_request_convertToJSON(revoke_chat_invite_link_request_2);
	printf("repeating revoke_chat_invite_link_request:\n%s\n", cJSON_Print(jsonrevoke_chat_invite_link_request_2));
}

int main() {
  test_revoke_chat_invite_link_request(1);
  test_revoke_chat_invite_link_request(0);

  printf("Hello world \n");
  return 0;
}

#endif // revoke_chat_invite_link_request_MAIN
#endif // revoke_chat_invite_link_request_TEST
