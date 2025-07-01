#ifndef _save_prepared_inline_message_post_200_response_TEST
#define _save_prepared_inline_message_post_200_response_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define _save_prepared_inline_message_post_200_response_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/_save_prepared_inline_message_post_200_response.h"
_save_prepared_inline_message_post_200_response_t* instantiate__save_prepared_inline_message_post_200_response(int include_optional);

#include "test_prepared_inline_message.c"


_save_prepared_inline_message_post_200_response_t* instantiate__save_prepared_inline_message_post_200_response(int include_optional) {
  _save_prepared_inline_message_post_200_response_t* _save_prepared_inline_message_post_200_response = NULL;
  if (include_optional) {
    _save_prepared_inline_message_post_200_response = _save_prepared_inline_message_post_200_response_create(
      1,
       // false, not to have infinite recursion
      instantiate_prepared_inline_message(0)
    );
  } else {
    _save_prepared_inline_message_post_200_response = _save_prepared_inline_message_post_200_response_create(
      1,
      NULL
    );
  }

  return _save_prepared_inline_message_post_200_response;
}


#ifdef _save_prepared_inline_message_post_200_response_MAIN

void test__save_prepared_inline_message_post_200_response(int include_optional) {
    _save_prepared_inline_message_post_200_response_t* _save_prepared_inline_message_post_200_response_1 = instantiate__save_prepared_inline_message_post_200_response(include_optional);

	cJSON* json_save_prepared_inline_message_post_200_response_1 = _save_prepared_inline_message_post_200_response_convertToJSON(_save_prepared_inline_message_post_200_response_1);
	printf("_save_prepared_inline_message_post_200_response :\n%s\n", cJSON_Print(json_save_prepared_inline_message_post_200_response_1));
	_save_prepared_inline_message_post_200_response_t* _save_prepared_inline_message_post_200_response_2 = _save_prepared_inline_message_post_200_response_parseFromJSON(json_save_prepared_inline_message_post_200_response_1);
	cJSON* json_save_prepared_inline_message_post_200_response_2 = _save_prepared_inline_message_post_200_response_convertToJSON(_save_prepared_inline_message_post_200_response_2);
	printf("repeating _save_prepared_inline_message_post_200_response:\n%s\n", cJSON_Print(json_save_prepared_inline_message_post_200_response_2));
}

int main() {
  test__save_prepared_inline_message_post_200_response(1);
  test__save_prepared_inline_message_post_200_response(0);

  printf("Hello world \n");
  return 0;
}

#endif // _save_prepared_inline_message_post_200_response_MAIN
#endif // _save_prepared_inline_message_post_200_response_TEST
