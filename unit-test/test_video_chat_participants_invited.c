#ifndef video_chat_participants_invited_TEST
#define video_chat_participants_invited_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define video_chat_participants_invited_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/video_chat_participants_invited.h"
video_chat_participants_invited_t* instantiate_video_chat_participants_invited(int include_optional);



video_chat_participants_invited_t* instantiate_video_chat_participants_invited(int include_optional) {
  video_chat_participants_invited_t* video_chat_participants_invited = NULL;
  if (include_optional) {
    video_chat_participants_invited = video_chat_participants_invited_create(
      list_createList()
    );
  } else {
    video_chat_participants_invited = video_chat_participants_invited_create(
      list_createList()
    );
  }

  return video_chat_participants_invited;
}


#ifdef video_chat_participants_invited_MAIN

void test_video_chat_participants_invited(int include_optional) {
    video_chat_participants_invited_t* video_chat_participants_invited_1 = instantiate_video_chat_participants_invited(include_optional);

	cJSON* jsonvideo_chat_participants_invited_1 = video_chat_participants_invited_convertToJSON(video_chat_participants_invited_1);
	printf("video_chat_participants_invited :\n%s\n", cJSON_Print(jsonvideo_chat_participants_invited_1));
	video_chat_participants_invited_t* video_chat_participants_invited_2 = video_chat_participants_invited_parseFromJSON(jsonvideo_chat_participants_invited_1);
	cJSON* jsonvideo_chat_participants_invited_2 = video_chat_participants_invited_convertToJSON(video_chat_participants_invited_2);
	printf("repeating video_chat_participants_invited:\n%s\n", cJSON_Print(jsonvideo_chat_participants_invited_2));
}

int main() {
  test_video_chat_participants_invited(1);
  test_video_chat_participants_invited(0);

  printf("Hello world \n");
  return 0;
}

#endif // video_chat_participants_invited_MAIN
#endif // video_chat_participants_invited_TEST
