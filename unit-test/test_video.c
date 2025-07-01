#ifndef video_TEST
#define video_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define video_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/video.h"
video_t* instantiate_video(int include_optional);

#include "test_photo_size.c"


video_t* instantiate_video(int include_optional) {
  video_t* video = NULL;
  if (include_optional) {
    video = video_create(
      "0",
      "0",
      56,
      56,
      56,
       // false, not to have infinite recursion
      instantiate_photo_size(0),
      list_createList(),
      56,
      "0",
      "0",
      56
    );
  } else {
    video = video_create(
      "0",
      "0",
      56,
      56,
      56,
      NULL,
      list_createList(),
      56,
      "0",
      "0",
      56
    );
  }

  return video;
}


#ifdef video_MAIN

void test_video(int include_optional) {
    video_t* video_1 = instantiate_video(include_optional);

	cJSON* jsonvideo_1 = video_convertToJSON(video_1);
	printf("video :\n%s\n", cJSON_Print(jsonvideo_1));
	video_t* video_2 = video_parseFromJSON(jsonvideo_1);
	cJSON* jsonvideo_2 = video_convertToJSON(video_2);
	printf("repeating video:\n%s\n", cJSON_Print(jsonvideo_2));
}

int main() {
  test_video(1);
  test_video(0);

  printf("Hello world \n");
  return 0;
}

#endif // video_MAIN
#endif // video_TEST
