#ifndef _set_webhook_post_200_response_TEST
#define _set_webhook_post_200_response_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define _set_webhook_post_200_response_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/_set_webhook_post_200_response.h"
_set_webhook_post_200_response_t* instantiate__set_webhook_post_200_response(int include_optional);



_set_webhook_post_200_response_t* instantiate__set_webhook_post_200_response(int include_optional) {
  _set_webhook_post_200_response_t* _set_webhook_post_200_response = NULL;
  if (include_optional) {
    _set_webhook_post_200_response = _set_webhook_post_200_response_create(
      1,
      1
    );
  } else {
    _set_webhook_post_200_response = _set_webhook_post_200_response_create(
      1,
      1
    );
  }

  return _set_webhook_post_200_response;
}


#ifdef _set_webhook_post_200_response_MAIN

void test__set_webhook_post_200_response(int include_optional) {
    _set_webhook_post_200_response_t* _set_webhook_post_200_response_1 = instantiate__set_webhook_post_200_response(include_optional);

	cJSON* json_set_webhook_post_200_response_1 = _set_webhook_post_200_response_convertToJSON(_set_webhook_post_200_response_1);
	printf("_set_webhook_post_200_response :\n%s\n", cJSON_Print(json_set_webhook_post_200_response_1));
	_set_webhook_post_200_response_t* _set_webhook_post_200_response_2 = _set_webhook_post_200_response_parseFromJSON(json_set_webhook_post_200_response_1);
	cJSON* json_set_webhook_post_200_response_2 = _set_webhook_post_200_response_convertToJSON(_set_webhook_post_200_response_2);
	printf("repeating _set_webhook_post_200_response:\n%s\n", cJSON_Print(json_set_webhook_post_200_response_2));
}

int main() {
  test__set_webhook_post_200_response(1);
  test__set_webhook_post_200_response(0);

  printf("Hello world \n");
  return 0;
}

#endif // _set_webhook_post_200_response_MAIN
#endif // _set_webhook_post_200_response_TEST
