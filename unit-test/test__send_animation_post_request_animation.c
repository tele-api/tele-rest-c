#ifndef _send_animation_post_request_animation_TEST
#define _send_animation_post_request_animation_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define _send_animation_post_request_animation_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/_send_animation_post_request_animation.h"
_send_animation_post_request_animation_t* instantiate__send_animation_post_request_animation(int include_optional);



_send_animation_post_request_animation_t* instantiate__send_animation_post_request_animation(int include_optional) {
  _send_animation_post_request_animation_t* _send_animation_post_request_animation = NULL;
  if (include_optional) {
    _send_animation_post_request_animation = _send_animation_post_request_animation_create(
    );
  } else {
    _send_animation_post_request_animation = _send_animation_post_request_animation_create(
    );
  }

  return _send_animation_post_request_animation;
}


#ifdef _send_animation_post_request_animation_MAIN

void test__send_animation_post_request_animation(int include_optional) {
    _send_animation_post_request_animation_t* _send_animation_post_request_animation_1 = instantiate__send_animation_post_request_animation(include_optional);

	cJSON* json_send_animation_post_request_animation_1 = _send_animation_post_request_animation_convertToJSON(_send_animation_post_request_animation_1);
	printf("_send_animation_post_request_animation :\n%s\n", cJSON_Print(json_send_animation_post_request_animation_1));
	_send_animation_post_request_animation_t* _send_animation_post_request_animation_2 = _send_animation_post_request_animation_parseFromJSON(json_send_animation_post_request_animation_1);
	cJSON* json_send_animation_post_request_animation_2 = _send_animation_post_request_animation_convertToJSON(_send_animation_post_request_animation_2);
	printf("repeating _send_animation_post_request_animation:\n%s\n", cJSON_Print(json_send_animation_post_request_animation_2));
}

int main() {
  test__send_animation_post_request_animation(1);
  test__send_animation_post_request_animation(0);

  printf("Hello world \n");
  return 0;
}

#endif // _send_animation_post_request_animation_MAIN
#endif // _send_animation_post_request_animation_TEST
