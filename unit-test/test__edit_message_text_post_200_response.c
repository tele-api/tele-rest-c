#ifndef _edit_message_text_post_200_response_TEST
#define _edit_message_text_post_200_response_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define _edit_message_text_post_200_response_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/_edit_message_text_post_200_response.h"
_edit_message_text_post_200_response_t* instantiate__edit_message_text_post_200_response(int include_optional);

#include "test__edit_message_text_post_200_response_result.c"


_edit_message_text_post_200_response_t* instantiate__edit_message_text_post_200_response(int include_optional) {
  _edit_message_text_post_200_response_t* _edit_message_text_post_200_response = NULL;
  if (include_optional) {
    _edit_message_text_post_200_response = _edit_message_text_post_200_response_create(
      1,
      null
    );
  } else {
    _edit_message_text_post_200_response = _edit_message_text_post_200_response_create(
      1,
      null
    );
  }

  return _edit_message_text_post_200_response;
}


#ifdef _edit_message_text_post_200_response_MAIN

void test__edit_message_text_post_200_response(int include_optional) {
    _edit_message_text_post_200_response_t* _edit_message_text_post_200_response_1 = instantiate__edit_message_text_post_200_response(include_optional);

	cJSON* json_edit_message_text_post_200_response_1 = _edit_message_text_post_200_response_convertToJSON(_edit_message_text_post_200_response_1);
	printf("_edit_message_text_post_200_response :\n%s\n", cJSON_Print(json_edit_message_text_post_200_response_1));
	_edit_message_text_post_200_response_t* _edit_message_text_post_200_response_2 = _edit_message_text_post_200_response_parseFromJSON(json_edit_message_text_post_200_response_1);
	cJSON* json_edit_message_text_post_200_response_2 = _edit_message_text_post_200_response_convertToJSON(_edit_message_text_post_200_response_2);
	printf("repeating _edit_message_text_post_200_response:\n%s\n", cJSON_Print(json_edit_message_text_post_200_response_2));
}

int main() {
  test__edit_message_text_post_200_response(1);
  test__edit_message_text_post_200_response(0);

  printf("Hello world \n");
  return 0;
}

#endif // _edit_message_text_post_200_response_MAIN
#endif // _edit_message_text_post_200_response_TEST
