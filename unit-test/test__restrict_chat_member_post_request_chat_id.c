#ifndef _restrict_chat_member_post_request_chat_id_TEST
#define _restrict_chat_member_post_request_chat_id_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define _restrict_chat_member_post_request_chat_id_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/_restrict_chat_member_post_request_chat_id.h"
_restrict_chat_member_post_request_chat_id_t* instantiate__restrict_chat_member_post_request_chat_id(int include_optional);



_restrict_chat_member_post_request_chat_id_t* instantiate__restrict_chat_member_post_request_chat_id(int include_optional) {
  _restrict_chat_member_post_request_chat_id_t* _restrict_chat_member_post_request_chat_id = NULL;
  if (include_optional) {
    _restrict_chat_member_post_request_chat_id = _restrict_chat_member_post_request_chat_id_create(
    );
  } else {
    _restrict_chat_member_post_request_chat_id = _restrict_chat_member_post_request_chat_id_create(
    );
  }

  return _restrict_chat_member_post_request_chat_id;
}


#ifdef _restrict_chat_member_post_request_chat_id_MAIN

void test__restrict_chat_member_post_request_chat_id(int include_optional) {
    _restrict_chat_member_post_request_chat_id_t* _restrict_chat_member_post_request_chat_id_1 = instantiate__restrict_chat_member_post_request_chat_id(include_optional);

	cJSON* json_restrict_chat_member_post_request_chat_id_1 = _restrict_chat_member_post_request_chat_id_convertToJSON(_restrict_chat_member_post_request_chat_id_1);
	printf("_restrict_chat_member_post_request_chat_id :\n%s\n", cJSON_Print(json_restrict_chat_member_post_request_chat_id_1));
	_restrict_chat_member_post_request_chat_id_t* _restrict_chat_member_post_request_chat_id_2 = _restrict_chat_member_post_request_chat_id_parseFromJSON(json_restrict_chat_member_post_request_chat_id_1);
	cJSON* json_restrict_chat_member_post_request_chat_id_2 = _restrict_chat_member_post_request_chat_id_convertToJSON(_restrict_chat_member_post_request_chat_id_2);
	printf("repeating _restrict_chat_member_post_request_chat_id:\n%s\n", cJSON_Print(json_restrict_chat_member_post_request_chat_id_2));
}

int main() {
  test__restrict_chat_member_post_request_chat_id(1);
  test__restrict_chat_member_post_request_chat_id(0);

  printf("Hello world \n");
  return 0;
}

#endif // _restrict_chat_member_post_request_chat_id_MAIN
#endif // _restrict_chat_member_post_request_chat_id_TEST
