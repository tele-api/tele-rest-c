#ifndef _set_user_emoji_status_post_request_TEST
#define _set_user_emoji_status_post_request_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define _set_user_emoji_status_post_request_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/_set_user_emoji_status_post_request.h"
_set_user_emoji_status_post_request_t* instantiate__set_user_emoji_status_post_request(int include_optional);



_set_user_emoji_status_post_request_t* instantiate__set_user_emoji_status_post_request(int include_optional) {
  _set_user_emoji_status_post_request_t* _set_user_emoji_status_post_request = NULL;
  if (include_optional) {
    _set_user_emoji_status_post_request = _set_user_emoji_status_post_request_create(
      56,
      "0",
      56
    );
  } else {
    _set_user_emoji_status_post_request = _set_user_emoji_status_post_request_create(
      56,
      "0",
      56
    );
  }

  return _set_user_emoji_status_post_request;
}


#ifdef _set_user_emoji_status_post_request_MAIN

void test__set_user_emoji_status_post_request(int include_optional) {
    _set_user_emoji_status_post_request_t* _set_user_emoji_status_post_request_1 = instantiate__set_user_emoji_status_post_request(include_optional);

	cJSON* json_set_user_emoji_status_post_request_1 = _set_user_emoji_status_post_request_convertToJSON(_set_user_emoji_status_post_request_1);
	printf("_set_user_emoji_status_post_request :\n%s\n", cJSON_Print(json_set_user_emoji_status_post_request_1));
	_set_user_emoji_status_post_request_t* _set_user_emoji_status_post_request_2 = _set_user_emoji_status_post_request_parseFromJSON(json_set_user_emoji_status_post_request_1);
	cJSON* json_set_user_emoji_status_post_request_2 = _set_user_emoji_status_post_request_convertToJSON(_set_user_emoji_status_post_request_2);
	printf("repeating _set_user_emoji_status_post_request:\n%s\n", cJSON_Print(json_set_user_emoji_status_post_request_2));
}

int main() {
  test__set_user_emoji_status_post_request(1);
  test__set_user_emoji_status_post_request(0);

  printf("Hello world \n");
  return 0;
}

#endif // _set_user_emoji_status_post_request_MAIN
#endif // _set_user_emoji_status_post_request_TEST
