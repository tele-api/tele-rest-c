#ifndef _send_video_note_post_request_video_note_TEST
#define _send_video_note_post_request_video_note_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define _send_video_note_post_request_video_note_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/_send_video_note_post_request_video_note.h"
_send_video_note_post_request_video_note_t* instantiate__send_video_note_post_request_video_note(int include_optional);



_send_video_note_post_request_video_note_t* instantiate__send_video_note_post_request_video_note(int include_optional) {
  _send_video_note_post_request_video_note_t* _send_video_note_post_request_video_note = NULL;
  if (include_optional) {
    _send_video_note_post_request_video_note = _send_video_note_post_request_video_note_create(
    );
  } else {
    _send_video_note_post_request_video_note = _send_video_note_post_request_video_note_create(
    );
  }

  return _send_video_note_post_request_video_note;
}


#ifdef _send_video_note_post_request_video_note_MAIN

void test__send_video_note_post_request_video_note(int include_optional) {
    _send_video_note_post_request_video_note_t* _send_video_note_post_request_video_note_1 = instantiate__send_video_note_post_request_video_note(include_optional);

	cJSON* json_send_video_note_post_request_video_note_1 = _send_video_note_post_request_video_note_convertToJSON(_send_video_note_post_request_video_note_1);
	printf("_send_video_note_post_request_video_note :\n%s\n", cJSON_Print(json_send_video_note_post_request_video_note_1));
	_send_video_note_post_request_video_note_t* _send_video_note_post_request_video_note_2 = _send_video_note_post_request_video_note_parseFromJSON(json_send_video_note_post_request_video_note_1);
	cJSON* json_send_video_note_post_request_video_note_2 = _send_video_note_post_request_video_note_convertToJSON(_send_video_note_post_request_video_note_2);
	printf("repeating _send_video_note_post_request_video_note:\n%s\n", cJSON_Print(json_send_video_note_post_request_video_note_2));
}

int main() {
  test__send_video_note_post_request_video_note(1);
  test__send_video_note_post_request_video_note(0);

  printf("Hello world \n");
  return 0;
}

#endif // _send_video_note_post_request_video_note_MAIN
#endif // _send_video_note_post_request_video_note_TEST
