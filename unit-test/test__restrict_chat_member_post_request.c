#ifndef _restrict_chat_member_post_request_TEST
#define _restrict_chat_member_post_request_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define _restrict_chat_member_post_request_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/_restrict_chat_member_post_request.h"
_restrict_chat_member_post_request_t* instantiate__restrict_chat_member_post_request(int include_optional);

#include "test__restrict_chat_member_post_request_chat_id.c"
#include "test_chat_permissions.c"


_restrict_chat_member_post_request_t* instantiate__restrict_chat_member_post_request(int include_optional) {
  _restrict_chat_member_post_request_t* _restrict_chat_member_post_request = NULL;
  if (include_optional) {
    _restrict_chat_member_post_request = _restrict_chat_member_post_request_create(
      null,
      56,
       // false, not to have infinite recursion
      instantiate_chat_permissions(0),
      1,
      56
    );
  } else {
    _restrict_chat_member_post_request = _restrict_chat_member_post_request_create(
      null,
      56,
      NULL,
      1,
      56
    );
  }

  return _restrict_chat_member_post_request;
}


#ifdef _restrict_chat_member_post_request_MAIN

void test__restrict_chat_member_post_request(int include_optional) {
    _restrict_chat_member_post_request_t* _restrict_chat_member_post_request_1 = instantiate__restrict_chat_member_post_request(include_optional);

	cJSON* json_restrict_chat_member_post_request_1 = _restrict_chat_member_post_request_convertToJSON(_restrict_chat_member_post_request_1);
	printf("_restrict_chat_member_post_request :\n%s\n", cJSON_Print(json_restrict_chat_member_post_request_1));
	_restrict_chat_member_post_request_t* _restrict_chat_member_post_request_2 = _restrict_chat_member_post_request_parseFromJSON(json_restrict_chat_member_post_request_1);
	cJSON* json_restrict_chat_member_post_request_2 = _restrict_chat_member_post_request_convertToJSON(_restrict_chat_member_post_request_2);
	printf("repeating _restrict_chat_member_post_request:\n%s\n", cJSON_Print(json_restrict_chat_member_post_request_2));
}

int main() {
  test__restrict_chat_member_post_request(1);
  test__restrict_chat_member_post_request(0);

  printf("Hello world \n");
  return 0;
}

#endif // _restrict_chat_member_post_request_MAIN
#endif // _restrict_chat_member_post_request_TEST
