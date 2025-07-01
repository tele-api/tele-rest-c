#ifndef _revoke_chat_invite_link_post_request_TEST
#define _revoke_chat_invite_link_post_request_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define _revoke_chat_invite_link_post_request_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/_revoke_chat_invite_link_post_request.h"
_revoke_chat_invite_link_post_request_t* instantiate__revoke_chat_invite_link_post_request(int include_optional);

#include "test__revoke_chat_invite_link_post_request_chat_id.c"


_revoke_chat_invite_link_post_request_t* instantiate__revoke_chat_invite_link_post_request(int include_optional) {
  _revoke_chat_invite_link_post_request_t* _revoke_chat_invite_link_post_request = NULL;
  if (include_optional) {
    _revoke_chat_invite_link_post_request = _revoke_chat_invite_link_post_request_create(
      null,
      "0"
    );
  } else {
    _revoke_chat_invite_link_post_request = _revoke_chat_invite_link_post_request_create(
      null,
      "0"
    );
  }

  return _revoke_chat_invite_link_post_request;
}


#ifdef _revoke_chat_invite_link_post_request_MAIN

void test__revoke_chat_invite_link_post_request(int include_optional) {
    _revoke_chat_invite_link_post_request_t* _revoke_chat_invite_link_post_request_1 = instantiate__revoke_chat_invite_link_post_request(include_optional);

	cJSON* json_revoke_chat_invite_link_post_request_1 = _revoke_chat_invite_link_post_request_convertToJSON(_revoke_chat_invite_link_post_request_1);
	printf("_revoke_chat_invite_link_post_request :\n%s\n", cJSON_Print(json_revoke_chat_invite_link_post_request_1));
	_revoke_chat_invite_link_post_request_t* _revoke_chat_invite_link_post_request_2 = _revoke_chat_invite_link_post_request_parseFromJSON(json_revoke_chat_invite_link_post_request_1);
	cJSON* json_revoke_chat_invite_link_post_request_2 = _revoke_chat_invite_link_post_request_convertToJSON(_revoke_chat_invite_link_post_request_2);
	printf("repeating _revoke_chat_invite_link_post_request:\n%s\n", cJSON_Print(json_revoke_chat_invite_link_post_request_2));
}

int main() {
  test__revoke_chat_invite_link_post_request(1);
  test__revoke_chat_invite_link_post_request(0);

  printf("Hello world \n");
  return 0;
}

#endif // _revoke_chat_invite_link_post_request_MAIN
#endif // _revoke_chat_invite_link_post_request_TEST
