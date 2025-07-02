#ifndef revoke_chat_invite_link_request_chat_id_TEST
#define revoke_chat_invite_link_request_chat_id_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define revoke_chat_invite_link_request_chat_id_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/revoke_chat_invite_link_request_chat_id.h"
revoke_chat_invite_link_request_chat_id_t* instantiate_revoke_chat_invite_link_request_chat_id(int include_optional);



revoke_chat_invite_link_request_chat_id_t* instantiate_revoke_chat_invite_link_request_chat_id(int include_optional) {
  revoke_chat_invite_link_request_chat_id_t* revoke_chat_invite_link_request_chat_id = NULL;
  if (include_optional) {
    revoke_chat_invite_link_request_chat_id = revoke_chat_invite_link_request_chat_id_create(
    );
  } else {
    revoke_chat_invite_link_request_chat_id = revoke_chat_invite_link_request_chat_id_create(
    );
  }

  return revoke_chat_invite_link_request_chat_id;
}


#ifdef revoke_chat_invite_link_request_chat_id_MAIN

void test_revoke_chat_invite_link_request_chat_id(int include_optional) {
    revoke_chat_invite_link_request_chat_id_t* revoke_chat_invite_link_request_chat_id_1 = instantiate_revoke_chat_invite_link_request_chat_id(include_optional);

	cJSON* jsonrevoke_chat_invite_link_request_chat_id_1 = revoke_chat_invite_link_request_chat_id_convertToJSON(revoke_chat_invite_link_request_chat_id_1);
	printf("revoke_chat_invite_link_request_chat_id :\n%s\n", cJSON_Print(jsonrevoke_chat_invite_link_request_chat_id_1));
	revoke_chat_invite_link_request_chat_id_t* revoke_chat_invite_link_request_chat_id_2 = revoke_chat_invite_link_request_chat_id_parseFromJSON(jsonrevoke_chat_invite_link_request_chat_id_1);
	cJSON* jsonrevoke_chat_invite_link_request_chat_id_2 = revoke_chat_invite_link_request_chat_id_convertToJSON(revoke_chat_invite_link_request_chat_id_2);
	printf("repeating revoke_chat_invite_link_request_chat_id:\n%s\n", cJSON_Print(jsonrevoke_chat_invite_link_request_chat_id_2));
}

int main() {
  test_revoke_chat_invite_link_request_chat_id(1);
  test_revoke_chat_invite_link_request_chat_id(0);

  printf("Hello world \n");
  return 0;
}

#endif // revoke_chat_invite_link_request_chat_id_MAIN
#endif // revoke_chat_invite_link_request_chat_id_TEST
