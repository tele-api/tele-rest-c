#ifndef video_chat_ended_TEST
#define video_chat_ended_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define video_chat_ended_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/video_chat_ended.h"
video_chat_ended_t* instantiate_video_chat_ended(int include_optional);



video_chat_ended_t* instantiate_video_chat_ended(int include_optional) {
  video_chat_ended_t* video_chat_ended = NULL;
  if (include_optional) {
    video_chat_ended = video_chat_ended_create(
      56
    );
  } else {
    video_chat_ended = video_chat_ended_create(
      56
    );
  }

  return video_chat_ended;
}


#ifdef video_chat_ended_MAIN

void test_video_chat_ended(int include_optional) {
    video_chat_ended_t* video_chat_ended_1 = instantiate_video_chat_ended(include_optional);

	cJSON* jsonvideo_chat_ended_1 = video_chat_ended_convertToJSON(video_chat_ended_1);
	printf("video_chat_ended :\n%s\n", cJSON_Print(jsonvideo_chat_ended_1));
	video_chat_ended_t* video_chat_ended_2 = video_chat_ended_parseFromJSON(jsonvideo_chat_ended_1);
	cJSON* jsonvideo_chat_ended_2 = video_chat_ended_convertToJSON(video_chat_ended_2);
	printf("repeating video_chat_ended:\n%s\n", cJSON_Print(jsonvideo_chat_ended_2));
}

int main() {
  test_video_chat_ended(1);
  test_video_chat_ended(0);

  printf("Hello world \n");
  return 0;
}

#endif // video_chat_ended_MAIN
#endif // video_chat_ended_TEST
