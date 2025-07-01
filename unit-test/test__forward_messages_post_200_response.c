#ifndef _forward_messages_post_200_response_TEST
#define _forward_messages_post_200_response_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define _forward_messages_post_200_response_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/_forward_messages_post_200_response.h"
_forward_messages_post_200_response_t* instantiate__forward_messages_post_200_response(int include_optional);



_forward_messages_post_200_response_t* instantiate__forward_messages_post_200_response(int include_optional) {
  _forward_messages_post_200_response_t* _forward_messages_post_200_response = NULL;
  if (include_optional) {
    _forward_messages_post_200_response = _forward_messages_post_200_response_create(
      1,
      list_createList()
    );
  } else {
    _forward_messages_post_200_response = _forward_messages_post_200_response_create(
      1,
      list_createList()
    );
  }

  return _forward_messages_post_200_response;
}


#ifdef _forward_messages_post_200_response_MAIN

void test__forward_messages_post_200_response(int include_optional) {
    _forward_messages_post_200_response_t* _forward_messages_post_200_response_1 = instantiate__forward_messages_post_200_response(include_optional);

	cJSON* json_forward_messages_post_200_response_1 = _forward_messages_post_200_response_convertToJSON(_forward_messages_post_200_response_1);
	printf("_forward_messages_post_200_response :\n%s\n", cJSON_Print(json_forward_messages_post_200_response_1));
	_forward_messages_post_200_response_t* _forward_messages_post_200_response_2 = _forward_messages_post_200_response_parseFromJSON(json_forward_messages_post_200_response_1);
	cJSON* json_forward_messages_post_200_response_2 = _forward_messages_post_200_response_convertToJSON(_forward_messages_post_200_response_2);
	printf("repeating _forward_messages_post_200_response:\n%s\n", cJSON_Print(json_forward_messages_post_200_response_2));
}

int main() {
  test__forward_messages_post_200_response(1);
  test__forward_messages_post_200_response(0);

  printf("Hello world \n");
  return 0;
}

#endif // _forward_messages_post_200_response_MAIN
#endif // _forward_messages_post_200_response_TEST
