#ifndef _get_chat_member_post_200_response_TEST
#define _get_chat_member_post_200_response_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define _get_chat_member_post_200_response_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/_get_chat_member_post_200_response.h"
_get_chat_member_post_200_response_t* instantiate__get_chat_member_post_200_response(int include_optional);

#include "test_chat_member.c"


_get_chat_member_post_200_response_t* instantiate__get_chat_member_post_200_response(int include_optional) {
  _get_chat_member_post_200_response_t* _get_chat_member_post_200_response = NULL;
  if (include_optional) {
    _get_chat_member_post_200_response = _get_chat_member_post_200_response_create(
      1,
      null
    );
  } else {
    _get_chat_member_post_200_response = _get_chat_member_post_200_response_create(
      1,
      null
    );
  }

  return _get_chat_member_post_200_response;
}


#ifdef _get_chat_member_post_200_response_MAIN

void test__get_chat_member_post_200_response(int include_optional) {
    _get_chat_member_post_200_response_t* _get_chat_member_post_200_response_1 = instantiate__get_chat_member_post_200_response(include_optional);

	cJSON* json_get_chat_member_post_200_response_1 = _get_chat_member_post_200_response_convertToJSON(_get_chat_member_post_200_response_1);
	printf("_get_chat_member_post_200_response :\n%s\n", cJSON_Print(json_get_chat_member_post_200_response_1));
	_get_chat_member_post_200_response_t* _get_chat_member_post_200_response_2 = _get_chat_member_post_200_response_parseFromJSON(json_get_chat_member_post_200_response_1);
	cJSON* json_get_chat_member_post_200_response_2 = _get_chat_member_post_200_response_convertToJSON(_get_chat_member_post_200_response_2);
	printf("repeating _get_chat_member_post_200_response:\n%s\n", cJSON_Print(json_get_chat_member_post_200_response_2));
}

int main() {
  test__get_chat_member_post_200_response(1);
  test__get_chat_member_post_200_response(0);

  printf("Hello world \n");
  return 0;
}

#endif // _get_chat_member_post_200_response_MAIN
#endif // _get_chat_member_post_200_response_TEST
