#ifndef video_chat_scheduled_TEST
#define video_chat_scheduled_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define video_chat_scheduled_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/video_chat_scheduled.h"
video_chat_scheduled_t* instantiate_video_chat_scheduled(int include_optional);



video_chat_scheduled_t* instantiate_video_chat_scheduled(int include_optional) {
  video_chat_scheduled_t* video_chat_scheduled = NULL;
  if (include_optional) {
    video_chat_scheduled = video_chat_scheduled_create(
      56
    );
  } else {
    video_chat_scheduled = video_chat_scheduled_create(
      56
    );
  }

  return video_chat_scheduled;
}


#ifdef video_chat_scheduled_MAIN

void test_video_chat_scheduled(int include_optional) {
    video_chat_scheduled_t* video_chat_scheduled_1 = instantiate_video_chat_scheduled(include_optional);

	cJSON* jsonvideo_chat_scheduled_1 = video_chat_scheduled_convertToJSON(video_chat_scheduled_1);
	printf("video_chat_scheduled :\n%s\n", cJSON_Print(jsonvideo_chat_scheduled_1));
	video_chat_scheduled_t* video_chat_scheduled_2 = video_chat_scheduled_parseFromJSON(jsonvideo_chat_scheduled_1);
	cJSON* jsonvideo_chat_scheduled_2 = video_chat_scheduled_convertToJSON(video_chat_scheduled_2);
	printf("repeating video_chat_scheduled:\n%s\n", cJSON_Print(jsonvideo_chat_scheduled_2));
}

int main() {
  test_video_chat_scheduled(1);
  test_video_chat_scheduled(0);

  printf("Hello world \n");
  return 0;
}

#endif // video_chat_scheduled_MAIN
#endif // video_chat_scheduled_TEST
