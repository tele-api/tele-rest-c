#ifndef post_send_video_note_request_video_note_TEST
#define post_send_video_note_request_video_note_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define post_send_video_note_request_video_note_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/post_send_video_note_request_video_note.h"
post_send_video_note_request_video_note_t* instantiate_post_send_video_note_request_video_note(int include_optional);



post_send_video_note_request_video_note_t* instantiate_post_send_video_note_request_video_note(int include_optional) {
  post_send_video_note_request_video_note_t* post_send_video_note_request_video_note = NULL;
  if (include_optional) {
    post_send_video_note_request_video_note = post_send_video_note_request_video_note_create(
    );
  } else {
    post_send_video_note_request_video_note = post_send_video_note_request_video_note_create(
    );
  }

  return post_send_video_note_request_video_note;
}


#ifdef post_send_video_note_request_video_note_MAIN

void test_post_send_video_note_request_video_note(int include_optional) {
    post_send_video_note_request_video_note_t* post_send_video_note_request_video_note_1 = instantiate_post_send_video_note_request_video_note(include_optional);

	cJSON* jsonpost_send_video_note_request_video_note_1 = post_send_video_note_request_video_note_convertToJSON(post_send_video_note_request_video_note_1);
	printf("post_send_video_note_request_video_note :\n%s\n", cJSON_Print(jsonpost_send_video_note_request_video_note_1));
	post_send_video_note_request_video_note_t* post_send_video_note_request_video_note_2 = post_send_video_note_request_video_note_parseFromJSON(jsonpost_send_video_note_request_video_note_1);
	cJSON* jsonpost_send_video_note_request_video_note_2 = post_send_video_note_request_video_note_convertToJSON(post_send_video_note_request_video_note_2);
	printf("repeating post_send_video_note_request_video_note:\n%s\n", cJSON_Print(jsonpost_send_video_note_request_video_note_2));
}

int main() {
  test_post_send_video_note_request_video_note(1);
  test_post_send_video_note_request_video_note(0);

  printf("Hello world \n");
  return 0;
}

#endif // post_send_video_note_request_video_note_MAIN
#endif // post_send_video_note_request_video_note_TEST
