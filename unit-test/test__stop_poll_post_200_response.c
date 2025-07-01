#ifndef _stop_poll_post_200_response_TEST
#define _stop_poll_post_200_response_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define _stop_poll_post_200_response_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/_stop_poll_post_200_response.h"
_stop_poll_post_200_response_t* instantiate__stop_poll_post_200_response(int include_optional);

#include "test_poll.c"


_stop_poll_post_200_response_t* instantiate__stop_poll_post_200_response(int include_optional) {
  _stop_poll_post_200_response_t* _stop_poll_post_200_response = NULL;
  if (include_optional) {
    _stop_poll_post_200_response = _stop_poll_post_200_response_create(
      1,
       // false, not to have infinite recursion
      instantiate_poll(0)
    );
  } else {
    _stop_poll_post_200_response = _stop_poll_post_200_response_create(
      1,
      NULL
    );
  }

  return _stop_poll_post_200_response;
}


#ifdef _stop_poll_post_200_response_MAIN

void test__stop_poll_post_200_response(int include_optional) {
    _stop_poll_post_200_response_t* _stop_poll_post_200_response_1 = instantiate__stop_poll_post_200_response(include_optional);

	cJSON* json_stop_poll_post_200_response_1 = _stop_poll_post_200_response_convertToJSON(_stop_poll_post_200_response_1);
	printf("_stop_poll_post_200_response :\n%s\n", cJSON_Print(json_stop_poll_post_200_response_1));
	_stop_poll_post_200_response_t* _stop_poll_post_200_response_2 = _stop_poll_post_200_response_parseFromJSON(json_stop_poll_post_200_response_1);
	cJSON* json_stop_poll_post_200_response_2 = _stop_poll_post_200_response_convertToJSON(_stop_poll_post_200_response_2);
	printf("repeating _stop_poll_post_200_response:\n%s\n", cJSON_Print(json_stop_poll_post_200_response_2));
}

int main() {
  test__stop_poll_post_200_response(1);
  test__stop_poll_post_200_response(0);

  printf("Hello world \n");
  return 0;
}

#endif // _stop_poll_post_200_response_MAIN
#endif // _stop_poll_post_200_response_TEST
