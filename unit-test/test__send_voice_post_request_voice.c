#ifndef _send_voice_post_request_voice_TEST
#define _send_voice_post_request_voice_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define _send_voice_post_request_voice_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/_send_voice_post_request_voice.h"
_send_voice_post_request_voice_t* instantiate__send_voice_post_request_voice(int include_optional);



_send_voice_post_request_voice_t* instantiate__send_voice_post_request_voice(int include_optional) {
  _send_voice_post_request_voice_t* _send_voice_post_request_voice = NULL;
  if (include_optional) {
    _send_voice_post_request_voice = _send_voice_post_request_voice_create(
    );
  } else {
    _send_voice_post_request_voice = _send_voice_post_request_voice_create(
    );
  }

  return _send_voice_post_request_voice;
}


#ifdef _send_voice_post_request_voice_MAIN

void test__send_voice_post_request_voice(int include_optional) {
    _send_voice_post_request_voice_t* _send_voice_post_request_voice_1 = instantiate__send_voice_post_request_voice(include_optional);

	cJSON* json_send_voice_post_request_voice_1 = _send_voice_post_request_voice_convertToJSON(_send_voice_post_request_voice_1);
	printf("_send_voice_post_request_voice :\n%s\n", cJSON_Print(json_send_voice_post_request_voice_1));
	_send_voice_post_request_voice_t* _send_voice_post_request_voice_2 = _send_voice_post_request_voice_parseFromJSON(json_send_voice_post_request_voice_1);
	cJSON* json_send_voice_post_request_voice_2 = _send_voice_post_request_voice_convertToJSON(_send_voice_post_request_voice_2);
	printf("repeating _send_voice_post_request_voice:\n%s\n", cJSON_Print(json_send_voice_post_request_voice_2));
}

int main() {
  test__send_voice_post_request_voice(1);
  test__send_voice_post_request_voice(0);

  printf("Hello world \n");
  return 0;
}

#endif // _send_voice_post_request_voice_MAIN
#endif // _send_voice_post_request_voice_TEST
