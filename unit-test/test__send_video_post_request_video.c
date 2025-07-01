#ifndef _send_video_post_request_video_TEST
#define _send_video_post_request_video_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define _send_video_post_request_video_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/_send_video_post_request_video.h"
_send_video_post_request_video_t* instantiate__send_video_post_request_video(int include_optional);



_send_video_post_request_video_t* instantiate__send_video_post_request_video(int include_optional) {
  _send_video_post_request_video_t* _send_video_post_request_video = NULL;
  if (include_optional) {
    _send_video_post_request_video = _send_video_post_request_video_create(
    );
  } else {
    _send_video_post_request_video = _send_video_post_request_video_create(
    );
  }

  return _send_video_post_request_video;
}


#ifdef _send_video_post_request_video_MAIN

void test__send_video_post_request_video(int include_optional) {
    _send_video_post_request_video_t* _send_video_post_request_video_1 = instantiate__send_video_post_request_video(include_optional);

	cJSON* json_send_video_post_request_video_1 = _send_video_post_request_video_convertToJSON(_send_video_post_request_video_1);
	printf("_send_video_post_request_video :\n%s\n", cJSON_Print(json_send_video_post_request_video_1));
	_send_video_post_request_video_t* _send_video_post_request_video_2 = _send_video_post_request_video_parseFromJSON(json_send_video_post_request_video_1);
	cJSON* json_send_video_post_request_video_2 = _send_video_post_request_video_convertToJSON(_send_video_post_request_video_2);
	printf("repeating _send_video_post_request_video:\n%s\n", cJSON_Print(json_send_video_post_request_video_2));
}

int main() {
  test__send_video_post_request_video(1);
  test__send_video_post_request_video(0);

  printf("Hello world \n");
  return 0;
}

#endif // _send_video_post_request_video_MAIN
#endif // _send_video_post_request_video_TEST
