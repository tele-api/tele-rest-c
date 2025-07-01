#ifndef _revoke_chat_invite_link_post_request_chat_id_TEST
#define _revoke_chat_invite_link_post_request_chat_id_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define _revoke_chat_invite_link_post_request_chat_id_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/_revoke_chat_invite_link_post_request_chat_id.h"
_revoke_chat_invite_link_post_request_chat_id_t* instantiate__revoke_chat_invite_link_post_request_chat_id(int include_optional);



_revoke_chat_invite_link_post_request_chat_id_t* instantiate__revoke_chat_invite_link_post_request_chat_id(int include_optional) {
  _revoke_chat_invite_link_post_request_chat_id_t* _revoke_chat_invite_link_post_request_chat_id = NULL;
  if (include_optional) {
    _revoke_chat_invite_link_post_request_chat_id = _revoke_chat_invite_link_post_request_chat_id_create(
    );
  } else {
    _revoke_chat_invite_link_post_request_chat_id = _revoke_chat_invite_link_post_request_chat_id_create(
    );
  }

  return _revoke_chat_invite_link_post_request_chat_id;
}


#ifdef _revoke_chat_invite_link_post_request_chat_id_MAIN

void test__revoke_chat_invite_link_post_request_chat_id(int include_optional) {
    _revoke_chat_invite_link_post_request_chat_id_t* _revoke_chat_invite_link_post_request_chat_id_1 = instantiate__revoke_chat_invite_link_post_request_chat_id(include_optional);

	cJSON* json_revoke_chat_invite_link_post_request_chat_id_1 = _revoke_chat_invite_link_post_request_chat_id_convertToJSON(_revoke_chat_invite_link_post_request_chat_id_1);
	printf("_revoke_chat_invite_link_post_request_chat_id :\n%s\n", cJSON_Print(json_revoke_chat_invite_link_post_request_chat_id_1));
	_revoke_chat_invite_link_post_request_chat_id_t* _revoke_chat_invite_link_post_request_chat_id_2 = _revoke_chat_invite_link_post_request_chat_id_parseFromJSON(json_revoke_chat_invite_link_post_request_chat_id_1);
	cJSON* json_revoke_chat_invite_link_post_request_chat_id_2 = _revoke_chat_invite_link_post_request_chat_id_convertToJSON(_revoke_chat_invite_link_post_request_chat_id_2);
	printf("repeating _revoke_chat_invite_link_post_request_chat_id:\n%s\n", cJSON_Print(json_revoke_chat_invite_link_post_request_chat_id_2));
}

int main() {
  test__revoke_chat_invite_link_post_request_chat_id(1);
  test__revoke_chat_invite_link_post_request_chat_id(0);

  printf("Hello world \n");
  return 0;
}

#endif // _revoke_chat_invite_link_post_request_chat_id_MAIN
#endif // _revoke_chat_invite_link_post_request_chat_id_TEST
