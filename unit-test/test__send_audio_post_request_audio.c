#ifndef _send_audio_post_request_audio_TEST
#define _send_audio_post_request_audio_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define _send_audio_post_request_audio_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/_send_audio_post_request_audio.h"
_send_audio_post_request_audio_t* instantiate__send_audio_post_request_audio(int include_optional);



_send_audio_post_request_audio_t* instantiate__send_audio_post_request_audio(int include_optional) {
  _send_audio_post_request_audio_t* _send_audio_post_request_audio = NULL;
  if (include_optional) {
    _send_audio_post_request_audio = _send_audio_post_request_audio_create(
    );
  } else {
    _send_audio_post_request_audio = _send_audio_post_request_audio_create(
    );
  }

  return _send_audio_post_request_audio;
}


#ifdef _send_audio_post_request_audio_MAIN

void test__send_audio_post_request_audio(int include_optional) {
    _send_audio_post_request_audio_t* _send_audio_post_request_audio_1 = instantiate__send_audio_post_request_audio(include_optional);

	cJSON* json_send_audio_post_request_audio_1 = _send_audio_post_request_audio_convertToJSON(_send_audio_post_request_audio_1);
	printf("_send_audio_post_request_audio :\n%s\n", cJSON_Print(json_send_audio_post_request_audio_1));
	_send_audio_post_request_audio_t* _send_audio_post_request_audio_2 = _send_audio_post_request_audio_parseFromJSON(json_send_audio_post_request_audio_1);
	cJSON* json_send_audio_post_request_audio_2 = _send_audio_post_request_audio_convertToJSON(_send_audio_post_request_audio_2);
	printf("repeating _send_audio_post_request_audio:\n%s\n", cJSON_Print(json_send_audio_post_request_audio_2));
}

int main() {
  test__send_audio_post_request_audio(1);
  test__send_audio_post_request_audio(0);

  printf("Hello world \n");
  return 0;
}

#endif // _send_audio_post_request_audio_MAIN
#endif // _send_audio_post_request_audio_TEST
