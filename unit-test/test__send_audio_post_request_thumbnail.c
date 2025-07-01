#ifndef _send_audio_post_request_thumbnail_TEST
#define _send_audio_post_request_thumbnail_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define _send_audio_post_request_thumbnail_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/_send_audio_post_request_thumbnail.h"
_send_audio_post_request_thumbnail_t* instantiate__send_audio_post_request_thumbnail(int include_optional);



_send_audio_post_request_thumbnail_t* instantiate__send_audio_post_request_thumbnail(int include_optional) {
  _send_audio_post_request_thumbnail_t* _send_audio_post_request_thumbnail = NULL;
  if (include_optional) {
    _send_audio_post_request_thumbnail = _send_audio_post_request_thumbnail_create(
    );
  } else {
    _send_audio_post_request_thumbnail = _send_audio_post_request_thumbnail_create(
    );
  }

  return _send_audio_post_request_thumbnail;
}


#ifdef _send_audio_post_request_thumbnail_MAIN

void test__send_audio_post_request_thumbnail(int include_optional) {
    _send_audio_post_request_thumbnail_t* _send_audio_post_request_thumbnail_1 = instantiate__send_audio_post_request_thumbnail(include_optional);

	cJSON* json_send_audio_post_request_thumbnail_1 = _send_audio_post_request_thumbnail_convertToJSON(_send_audio_post_request_thumbnail_1);
	printf("_send_audio_post_request_thumbnail :\n%s\n", cJSON_Print(json_send_audio_post_request_thumbnail_1));
	_send_audio_post_request_thumbnail_t* _send_audio_post_request_thumbnail_2 = _send_audio_post_request_thumbnail_parseFromJSON(json_send_audio_post_request_thumbnail_1);
	cJSON* json_send_audio_post_request_thumbnail_2 = _send_audio_post_request_thumbnail_convertToJSON(_send_audio_post_request_thumbnail_2);
	printf("repeating _send_audio_post_request_thumbnail:\n%s\n", cJSON_Print(json_send_audio_post_request_thumbnail_2));
}

int main() {
  test__send_audio_post_request_thumbnail(1);
  test__send_audio_post_request_thumbnail(0);

  printf("Hello world \n");
  return 0;
}

#endif // _send_audio_post_request_thumbnail_MAIN
#endif // _send_audio_post_request_thumbnail_TEST
