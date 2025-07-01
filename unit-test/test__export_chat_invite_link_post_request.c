#ifndef _export_chat_invite_link_post_request_TEST
#define _export_chat_invite_link_post_request_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define _export_chat_invite_link_post_request_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/_export_chat_invite_link_post_request.h"
_export_chat_invite_link_post_request_t* instantiate__export_chat_invite_link_post_request(int include_optional);

#include "test__send_message_post_request_chat_id.c"


_export_chat_invite_link_post_request_t* instantiate__export_chat_invite_link_post_request(int include_optional) {
  _export_chat_invite_link_post_request_t* _export_chat_invite_link_post_request = NULL;
  if (include_optional) {
    _export_chat_invite_link_post_request = _export_chat_invite_link_post_request_create(
      null
    );
  } else {
    _export_chat_invite_link_post_request = _export_chat_invite_link_post_request_create(
      null
    );
  }

  return _export_chat_invite_link_post_request;
}


#ifdef _export_chat_invite_link_post_request_MAIN

void test__export_chat_invite_link_post_request(int include_optional) {
    _export_chat_invite_link_post_request_t* _export_chat_invite_link_post_request_1 = instantiate__export_chat_invite_link_post_request(include_optional);

	cJSON* json_export_chat_invite_link_post_request_1 = _export_chat_invite_link_post_request_convertToJSON(_export_chat_invite_link_post_request_1);
	printf("_export_chat_invite_link_post_request :\n%s\n", cJSON_Print(json_export_chat_invite_link_post_request_1));
	_export_chat_invite_link_post_request_t* _export_chat_invite_link_post_request_2 = _export_chat_invite_link_post_request_parseFromJSON(json_export_chat_invite_link_post_request_1);
	cJSON* json_export_chat_invite_link_post_request_2 = _export_chat_invite_link_post_request_convertToJSON(_export_chat_invite_link_post_request_2);
	printf("repeating _export_chat_invite_link_post_request:\n%s\n", cJSON_Print(json_export_chat_invite_link_post_request_2));
}

int main() {
  test__export_chat_invite_link_post_request(1);
  test__export_chat_invite_link_post_request(0);

  printf("Hello world \n");
  return 0;
}

#endif // _export_chat_invite_link_post_request_MAIN
#endif // _export_chat_invite_link_post_request_TEST
