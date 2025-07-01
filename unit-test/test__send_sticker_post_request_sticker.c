#ifndef _send_sticker_post_request_sticker_TEST
#define _send_sticker_post_request_sticker_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define _send_sticker_post_request_sticker_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/_send_sticker_post_request_sticker.h"
_send_sticker_post_request_sticker_t* instantiate__send_sticker_post_request_sticker(int include_optional);



_send_sticker_post_request_sticker_t* instantiate__send_sticker_post_request_sticker(int include_optional) {
  _send_sticker_post_request_sticker_t* _send_sticker_post_request_sticker = NULL;
  if (include_optional) {
    _send_sticker_post_request_sticker = _send_sticker_post_request_sticker_create(
    );
  } else {
    _send_sticker_post_request_sticker = _send_sticker_post_request_sticker_create(
    );
  }

  return _send_sticker_post_request_sticker;
}


#ifdef _send_sticker_post_request_sticker_MAIN

void test__send_sticker_post_request_sticker(int include_optional) {
    _send_sticker_post_request_sticker_t* _send_sticker_post_request_sticker_1 = instantiate__send_sticker_post_request_sticker(include_optional);

	cJSON* json_send_sticker_post_request_sticker_1 = _send_sticker_post_request_sticker_convertToJSON(_send_sticker_post_request_sticker_1);
	printf("_send_sticker_post_request_sticker :\n%s\n", cJSON_Print(json_send_sticker_post_request_sticker_1));
	_send_sticker_post_request_sticker_t* _send_sticker_post_request_sticker_2 = _send_sticker_post_request_sticker_parseFromJSON(json_send_sticker_post_request_sticker_1);
	cJSON* json_send_sticker_post_request_sticker_2 = _send_sticker_post_request_sticker_convertToJSON(_send_sticker_post_request_sticker_2);
	printf("repeating _send_sticker_post_request_sticker:\n%s\n", cJSON_Print(json_send_sticker_post_request_sticker_2));
}

int main() {
  test__send_sticker_post_request_sticker(1);
  test__send_sticker_post_request_sticker(0);

  printf("Hello world \n");
  return 0;
}

#endif // _send_sticker_post_request_sticker_MAIN
#endif // _send_sticker_post_request_sticker_TEST
