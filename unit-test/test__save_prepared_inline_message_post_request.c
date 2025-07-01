#ifndef _save_prepared_inline_message_post_request_TEST
#define _save_prepared_inline_message_post_request_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define _save_prepared_inline_message_post_request_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/_save_prepared_inline_message_post_request.h"
_save_prepared_inline_message_post_request_t* instantiate__save_prepared_inline_message_post_request(int include_optional);

#include "test_inline_query_result.c"


_save_prepared_inline_message_post_request_t* instantiate__save_prepared_inline_message_post_request(int include_optional) {
  _save_prepared_inline_message_post_request_t* _save_prepared_inline_message_post_request = NULL;
  if (include_optional) {
    _save_prepared_inline_message_post_request = _save_prepared_inline_message_post_request_create(
      56,
      null,
      1,
      1,
      1,
      1
    );
  } else {
    _save_prepared_inline_message_post_request = _save_prepared_inline_message_post_request_create(
      56,
      null,
      1,
      1,
      1,
      1
    );
  }

  return _save_prepared_inline_message_post_request;
}


#ifdef _save_prepared_inline_message_post_request_MAIN

void test__save_prepared_inline_message_post_request(int include_optional) {
    _save_prepared_inline_message_post_request_t* _save_prepared_inline_message_post_request_1 = instantiate__save_prepared_inline_message_post_request(include_optional);

	cJSON* json_save_prepared_inline_message_post_request_1 = _save_prepared_inline_message_post_request_convertToJSON(_save_prepared_inline_message_post_request_1);
	printf("_save_prepared_inline_message_post_request :\n%s\n", cJSON_Print(json_save_prepared_inline_message_post_request_1));
	_save_prepared_inline_message_post_request_t* _save_prepared_inline_message_post_request_2 = _save_prepared_inline_message_post_request_parseFromJSON(json_save_prepared_inline_message_post_request_1);
	cJSON* json_save_prepared_inline_message_post_request_2 = _save_prepared_inline_message_post_request_convertToJSON(_save_prepared_inline_message_post_request_2);
	printf("repeating _save_prepared_inline_message_post_request:\n%s\n", cJSON_Print(json_save_prepared_inline_message_post_request_2));
}

int main() {
  test__save_prepared_inline_message_post_request(1);
  test__save_prepared_inline_message_post_request(0);

  printf("Hello world \n");
  return 0;
}

#endif // _save_prepared_inline_message_post_request_MAIN
#endif // _save_prepared_inline_message_post_request_TEST
