#ifndef _copy_message_post_200_response_TEST
#define _copy_message_post_200_response_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define _copy_message_post_200_response_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/_copy_message_post_200_response.h"
_copy_message_post_200_response_t* instantiate__copy_message_post_200_response(int include_optional);

#include "test_message_id.c"


_copy_message_post_200_response_t* instantiate__copy_message_post_200_response(int include_optional) {
  _copy_message_post_200_response_t* _copy_message_post_200_response = NULL;
  if (include_optional) {
    _copy_message_post_200_response = _copy_message_post_200_response_create(
      1,
       // false, not to have infinite recursion
      instantiate_message_id(0)
    );
  } else {
    _copy_message_post_200_response = _copy_message_post_200_response_create(
      1,
      NULL
    );
  }

  return _copy_message_post_200_response;
}


#ifdef _copy_message_post_200_response_MAIN

void test__copy_message_post_200_response(int include_optional) {
    _copy_message_post_200_response_t* _copy_message_post_200_response_1 = instantiate__copy_message_post_200_response(include_optional);

	cJSON* json_copy_message_post_200_response_1 = _copy_message_post_200_response_convertToJSON(_copy_message_post_200_response_1);
	printf("_copy_message_post_200_response :\n%s\n", cJSON_Print(json_copy_message_post_200_response_1));
	_copy_message_post_200_response_t* _copy_message_post_200_response_2 = _copy_message_post_200_response_parseFromJSON(json_copy_message_post_200_response_1);
	cJSON* json_copy_message_post_200_response_2 = _copy_message_post_200_response_convertToJSON(_copy_message_post_200_response_2);
	printf("repeating _copy_message_post_200_response:\n%s\n", cJSON_Print(json_copy_message_post_200_response_2));
}

int main() {
  test__copy_message_post_200_response(1);
  test__copy_message_post_200_response(0);

  printf("Hello world \n");
  return 0;
}

#endif // _copy_message_post_200_response_MAIN
#endif // _copy_message_post_200_response_TEST
