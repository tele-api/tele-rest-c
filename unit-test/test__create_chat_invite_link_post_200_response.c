#ifndef _create_chat_invite_link_post_200_response_TEST
#define _create_chat_invite_link_post_200_response_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define _create_chat_invite_link_post_200_response_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/_create_chat_invite_link_post_200_response.h"
_create_chat_invite_link_post_200_response_t* instantiate__create_chat_invite_link_post_200_response(int include_optional);

#include "test_chat_invite_link.c"


_create_chat_invite_link_post_200_response_t* instantiate__create_chat_invite_link_post_200_response(int include_optional) {
  _create_chat_invite_link_post_200_response_t* _create_chat_invite_link_post_200_response = NULL;
  if (include_optional) {
    _create_chat_invite_link_post_200_response = _create_chat_invite_link_post_200_response_create(
      1,
       // false, not to have infinite recursion
      instantiate_chat_invite_link(0)
    );
  } else {
    _create_chat_invite_link_post_200_response = _create_chat_invite_link_post_200_response_create(
      1,
      NULL
    );
  }

  return _create_chat_invite_link_post_200_response;
}


#ifdef _create_chat_invite_link_post_200_response_MAIN

void test__create_chat_invite_link_post_200_response(int include_optional) {
    _create_chat_invite_link_post_200_response_t* _create_chat_invite_link_post_200_response_1 = instantiate__create_chat_invite_link_post_200_response(include_optional);

	cJSON* json_create_chat_invite_link_post_200_response_1 = _create_chat_invite_link_post_200_response_convertToJSON(_create_chat_invite_link_post_200_response_1);
	printf("_create_chat_invite_link_post_200_response :\n%s\n", cJSON_Print(json_create_chat_invite_link_post_200_response_1));
	_create_chat_invite_link_post_200_response_t* _create_chat_invite_link_post_200_response_2 = _create_chat_invite_link_post_200_response_parseFromJSON(json_create_chat_invite_link_post_200_response_1);
	cJSON* json_create_chat_invite_link_post_200_response_2 = _create_chat_invite_link_post_200_response_convertToJSON(_create_chat_invite_link_post_200_response_2);
	printf("repeating _create_chat_invite_link_post_200_response:\n%s\n", cJSON_Print(json_create_chat_invite_link_post_200_response_2));
}

int main() {
  test__create_chat_invite_link_post_200_response(1);
  test__create_chat_invite_link_post_200_response(0);

  printf("Hello world \n");
  return 0;
}

#endif // _create_chat_invite_link_post_200_response_MAIN
#endif // _create_chat_invite_link_post_200_response_TEST
