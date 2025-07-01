#ifndef _send_photo_post_request_photo_TEST
#define _send_photo_post_request_photo_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define _send_photo_post_request_photo_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/_send_photo_post_request_photo.h"
_send_photo_post_request_photo_t* instantiate__send_photo_post_request_photo(int include_optional);



_send_photo_post_request_photo_t* instantiate__send_photo_post_request_photo(int include_optional) {
  _send_photo_post_request_photo_t* _send_photo_post_request_photo = NULL;
  if (include_optional) {
    _send_photo_post_request_photo = _send_photo_post_request_photo_create(
    );
  } else {
    _send_photo_post_request_photo = _send_photo_post_request_photo_create(
    );
  }

  return _send_photo_post_request_photo;
}


#ifdef _send_photo_post_request_photo_MAIN

void test__send_photo_post_request_photo(int include_optional) {
    _send_photo_post_request_photo_t* _send_photo_post_request_photo_1 = instantiate__send_photo_post_request_photo(include_optional);

	cJSON* json_send_photo_post_request_photo_1 = _send_photo_post_request_photo_convertToJSON(_send_photo_post_request_photo_1);
	printf("_send_photo_post_request_photo :\n%s\n", cJSON_Print(json_send_photo_post_request_photo_1));
	_send_photo_post_request_photo_t* _send_photo_post_request_photo_2 = _send_photo_post_request_photo_parseFromJSON(json_send_photo_post_request_photo_1);
	cJSON* json_send_photo_post_request_photo_2 = _send_photo_post_request_photo_convertToJSON(_send_photo_post_request_photo_2);
	printf("repeating _send_photo_post_request_photo:\n%s\n", cJSON_Print(json_send_photo_post_request_photo_2));
}

int main() {
  test__send_photo_post_request_photo(1);
  test__send_photo_post_request_photo(0);

  printf("Hello world \n");
  return 0;
}

#endif // _send_photo_post_request_photo_MAIN
#endif // _send_photo_post_request_photo_TEST
