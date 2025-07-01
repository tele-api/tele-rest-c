#ifndef _ban_chat_member_post_request_chat_id_TEST
#define _ban_chat_member_post_request_chat_id_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define _ban_chat_member_post_request_chat_id_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/_ban_chat_member_post_request_chat_id.h"
_ban_chat_member_post_request_chat_id_t* instantiate__ban_chat_member_post_request_chat_id(int include_optional);



_ban_chat_member_post_request_chat_id_t* instantiate__ban_chat_member_post_request_chat_id(int include_optional) {
  _ban_chat_member_post_request_chat_id_t* _ban_chat_member_post_request_chat_id = NULL;
  if (include_optional) {
    _ban_chat_member_post_request_chat_id = _ban_chat_member_post_request_chat_id_create(
    );
  } else {
    _ban_chat_member_post_request_chat_id = _ban_chat_member_post_request_chat_id_create(
    );
  }

  return _ban_chat_member_post_request_chat_id;
}


#ifdef _ban_chat_member_post_request_chat_id_MAIN

void test__ban_chat_member_post_request_chat_id(int include_optional) {
    _ban_chat_member_post_request_chat_id_t* _ban_chat_member_post_request_chat_id_1 = instantiate__ban_chat_member_post_request_chat_id(include_optional);

	cJSON* json_ban_chat_member_post_request_chat_id_1 = _ban_chat_member_post_request_chat_id_convertToJSON(_ban_chat_member_post_request_chat_id_1);
	printf("_ban_chat_member_post_request_chat_id :\n%s\n", cJSON_Print(json_ban_chat_member_post_request_chat_id_1));
	_ban_chat_member_post_request_chat_id_t* _ban_chat_member_post_request_chat_id_2 = _ban_chat_member_post_request_chat_id_parseFromJSON(json_ban_chat_member_post_request_chat_id_1);
	cJSON* json_ban_chat_member_post_request_chat_id_2 = _ban_chat_member_post_request_chat_id_convertToJSON(_ban_chat_member_post_request_chat_id_2);
	printf("repeating _ban_chat_member_post_request_chat_id:\n%s\n", cJSON_Print(json_ban_chat_member_post_request_chat_id_2));
}

int main() {
  test__ban_chat_member_post_request_chat_id(1);
  test__ban_chat_member_post_request_chat_id(0);

  printf("Hello world \n");
  return 0;
}

#endif // _ban_chat_member_post_request_chat_id_MAIN
#endif // _ban_chat_member_post_request_chat_id_TEST
