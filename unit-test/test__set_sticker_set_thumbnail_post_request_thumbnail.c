#ifndef _set_sticker_set_thumbnail_post_request_thumbnail_TEST
#define _set_sticker_set_thumbnail_post_request_thumbnail_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define _set_sticker_set_thumbnail_post_request_thumbnail_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/_set_sticker_set_thumbnail_post_request_thumbnail.h"
_set_sticker_set_thumbnail_post_request_thumbnail_t* instantiate__set_sticker_set_thumbnail_post_request_thumbnail(int include_optional);



_set_sticker_set_thumbnail_post_request_thumbnail_t* instantiate__set_sticker_set_thumbnail_post_request_thumbnail(int include_optional) {
  _set_sticker_set_thumbnail_post_request_thumbnail_t* _set_sticker_set_thumbnail_post_request_thumbnail = NULL;
  if (include_optional) {
    _set_sticker_set_thumbnail_post_request_thumbnail = _set_sticker_set_thumbnail_post_request_thumbnail_create(
    );
  } else {
    _set_sticker_set_thumbnail_post_request_thumbnail = _set_sticker_set_thumbnail_post_request_thumbnail_create(
    );
  }

  return _set_sticker_set_thumbnail_post_request_thumbnail;
}


#ifdef _set_sticker_set_thumbnail_post_request_thumbnail_MAIN

void test__set_sticker_set_thumbnail_post_request_thumbnail(int include_optional) {
    _set_sticker_set_thumbnail_post_request_thumbnail_t* _set_sticker_set_thumbnail_post_request_thumbnail_1 = instantiate__set_sticker_set_thumbnail_post_request_thumbnail(include_optional);

	cJSON* json_set_sticker_set_thumbnail_post_request_thumbnail_1 = _set_sticker_set_thumbnail_post_request_thumbnail_convertToJSON(_set_sticker_set_thumbnail_post_request_thumbnail_1);
	printf("_set_sticker_set_thumbnail_post_request_thumbnail :\n%s\n", cJSON_Print(json_set_sticker_set_thumbnail_post_request_thumbnail_1));
	_set_sticker_set_thumbnail_post_request_thumbnail_t* _set_sticker_set_thumbnail_post_request_thumbnail_2 = _set_sticker_set_thumbnail_post_request_thumbnail_parseFromJSON(json_set_sticker_set_thumbnail_post_request_thumbnail_1);
	cJSON* json_set_sticker_set_thumbnail_post_request_thumbnail_2 = _set_sticker_set_thumbnail_post_request_thumbnail_convertToJSON(_set_sticker_set_thumbnail_post_request_thumbnail_2);
	printf("repeating _set_sticker_set_thumbnail_post_request_thumbnail:\n%s\n", cJSON_Print(json_set_sticker_set_thumbnail_post_request_thumbnail_2));
}

int main() {
  test__set_sticker_set_thumbnail_post_request_thumbnail(1);
  test__set_sticker_set_thumbnail_post_request_thumbnail(0);

  printf("Hello world \n");
  return 0;
}

#endif // _set_sticker_set_thumbnail_post_request_thumbnail_MAIN
#endif // _set_sticker_set_thumbnail_post_request_thumbnail_TEST
