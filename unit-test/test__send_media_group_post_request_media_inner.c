#ifndef _send_media_group_post_request_media_inner_TEST
#define _send_media_group_post_request_media_inner_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define _send_media_group_post_request_media_inner_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/_send_media_group_post_request_media_inner.h"
_send_media_group_post_request_media_inner_t* instantiate__send_media_group_post_request_media_inner(int include_optional);



_send_media_group_post_request_media_inner_t* instantiate__send_media_group_post_request_media_inner(int include_optional) {
  _send_media_group_post_request_media_inner_t* _send_media_group_post_request_media_inner = NULL;
  if (include_optional) {
    _send_media_group_post_request_media_inner = _send_media_group_post_request_media_inner_create(
      "video",
      "0",
      "0",
      "0",
      "0",
      list_createList(),
      56,
      "0",
      "0",
      1,
      1,
      1,
      "0",
      56,
      56,
      56,
      1
    );
  } else {
    _send_media_group_post_request_media_inner = _send_media_group_post_request_media_inner_create(
      "video",
      "0",
      "0",
      "0",
      "0",
      list_createList(),
      56,
      "0",
      "0",
      1,
      1,
      1,
      "0",
      56,
      56,
      56,
      1
    );
  }

  return _send_media_group_post_request_media_inner;
}


#ifdef _send_media_group_post_request_media_inner_MAIN

void test__send_media_group_post_request_media_inner(int include_optional) {
    _send_media_group_post_request_media_inner_t* _send_media_group_post_request_media_inner_1 = instantiate__send_media_group_post_request_media_inner(include_optional);

	cJSON* json_send_media_group_post_request_media_inner_1 = _send_media_group_post_request_media_inner_convertToJSON(_send_media_group_post_request_media_inner_1);
	printf("_send_media_group_post_request_media_inner :\n%s\n", cJSON_Print(json_send_media_group_post_request_media_inner_1));
	_send_media_group_post_request_media_inner_t* _send_media_group_post_request_media_inner_2 = _send_media_group_post_request_media_inner_parseFromJSON(json_send_media_group_post_request_media_inner_1);
	cJSON* json_send_media_group_post_request_media_inner_2 = _send_media_group_post_request_media_inner_convertToJSON(_send_media_group_post_request_media_inner_2);
	printf("repeating _send_media_group_post_request_media_inner:\n%s\n", cJSON_Print(json_send_media_group_post_request_media_inner_2));
}

int main() {
  test__send_media_group_post_request_media_inner(1);
  test__send_media_group_post_request_media_inner(0);

  printf("Hello world \n");
  return 0;
}

#endif // _send_media_group_post_request_media_inner_MAIN
#endif // _send_media_group_post_request_media_inner_TEST
