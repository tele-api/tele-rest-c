#ifndef _send_video_post_request_cover_TEST
#define _send_video_post_request_cover_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define _send_video_post_request_cover_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/_send_video_post_request_cover.h"
_send_video_post_request_cover_t* instantiate__send_video_post_request_cover(int include_optional);



_send_video_post_request_cover_t* instantiate__send_video_post_request_cover(int include_optional) {
  _send_video_post_request_cover_t* _send_video_post_request_cover = NULL;
  if (include_optional) {
    _send_video_post_request_cover = _send_video_post_request_cover_create(
    );
  } else {
    _send_video_post_request_cover = _send_video_post_request_cover_create(
    );
  }

  return _send_video_post_request_cover;
}


#ifdef _send_video_post_request_cover_MAIN

void test__send_video_post_request_cover(int include_optional) {
    _send_video_post_request_cover_t* _send_video_post_request_cover_1 = instantiate__send_video_post_request_cover(include_optional);

	cJSON* json_send_video_post_request_cover_1 = _send_video_post_request_cover_convertToJSON(_send_video_post_request_cover_1);
	printf("_send_video_post_request_cover :\n%s\n", cJSON_Print(json_send_video_post_request_cover_1));
	_send_video_post_request_cover_t* _send_video_post_request_cover_2 = _send_video_post_request_cover_parseFromJSON(json_send_video_post_request_cover_1);
	cJSON* json_send_video_post_request_cover_2 = _send_video_post_request_cover_convertToJSON(_send_video_post_request_cover_2);
	printf("repeating _send_video_post_request_cover:\n%s\n", cJSON_Print(json_send_video_post_request_cover_2));
}

int main() {
  test__send_video_post_request_cover(1);
  test__send_video_post_request_cover(0);

  printf("Hello world \n");
  return 0;
}

#endif // _send_video_post_request_cover_MAIN
#endif // _send_video_post_request_cover_TEST
