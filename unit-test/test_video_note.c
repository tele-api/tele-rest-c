#ifndef video_note_TEST
#define video_note_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define video_note_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/video_note.h"
video_note_t* instantiate_video_note(int include_optional);

#include "test_photo_size.c"


video_note_t* instantiate_video_note(int include_optional) {
  video_note_t* video_note = NULL;
  if (include_optional) {
    video_note = video_note_create(
      "0",
      "0",
      56,
      56,
       // false, not to have infinite recursion
      instantiate_photo_size(0),
      56
    );
  } else {
    video_note = video_note_create(
      "0",
      "0",
      56,
      56,
      NULL,
      56
    );
  }

  return video_note;
}


#ifdef video_note_MAIN

void test_video_note(int include_optional) {
    video_note_t* video_note_1 = instantiate_video_note(include_optional);

	cJSON* jsonvideo_note_1 = video_note_convertToJSON(video_note_1);
	printf("video_note :\n%s\n", cJSON_Print(jsonvideo_note_1));
	video_note_t* video_note_2 = video_note_parseFromJSON(jsonvideo_note_1);
	cJSON* jsonvideo_note_2 = video_note_convertToJSON(video_note_2);
	printf("repeating video_note:\n%s\n", cJSON_Print(jsonvideo_note_2));
}

int main() {
  test_video_note(1);
  test_video_note(0);

  printf("Hello world \n");
  return 0;
}

#endif // video_note_MAIN
#endif // video_note_TEST
