#ifndef revoke_chat_invite_link_response_TEST
#define revoke_chat_invite_link_response_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define revoke_chat_invite_link_response_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/revoke_chat_invite_link_response.h"
revoke_chat_invite_link_response_t* instantiate_revoke_chat_invite_link_response(int include_optional);

#include "test_chat_invite_link.c"


revoke_chat_invite_link_response_t* instantiate_revoke_chat_invite_link_response(int include_optional) {
  revoke_chat_invite_link_response_t* revoke_chat_invite_link_response = NULL;
  if (include_optional) {
    revoke_chat_invite_link_response = revoke_chat_invite_link_response_create(
      1,
       // false, not to have infinite recursion
      instantiate_chat_invite_link(0)
    );
  } else {
    revoke_chat_invite_link_response = revoke_chat_invite_link_response_create(
      1,
      NULL
    );
  }

  return revoke_chat_invite_link_response;
}


#ifdef revoke_chat_invite_link_response_MAIN

void test_revoke_chat_invite_link_response(int include_optional) {
    revoke_chat_invite_link_response_t* revoke_chat_invite_link_response_1 = instantiate_revoke_chat_invite_link_response(include_optional);

	cJSON* jsonrevoke_chat_invite_link_response_1 = revoke_chat_invite_link_response_convertToJSON(revoke_chat_invite_link_response_1);
	printf("revoke_chat_invite_link_response :\n%s\n", cJSON_Print(jsonrevoke_chat_invite_link_response_1));
	revoke_chat_invite_link_response_t* revoke_chat_invite_link_response_2 = revoke_chat_invite_link_response_parseFromJSON(jsonrevoke_chat_invite_link_response_1);
	cJSON* jsonrevoke_chat_invite_link_response_2 = revoke_chat_invite_link_response_convertToJSON(revoke_chat_invite_link_response_2);
	printf("repeating revoke_chat_invite_link_response:\n%s\n", cJSON_Print(jsonrevoke_chat_invite_link_response_2));
}

int main() {
  test_revoke_chat_invite_link_response(1);
  test_revoke_chat_invite_link_response(0);

  printf("Hello world \n");
  return 0;
}

#endif // revoke_chat_invite_link_response_MAIN
#endif // revoke_chat_invite_link_response_TEST
