#ifndef input_story_content_video_TEST
#define input_story_content_video_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define input_story_content_video_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/input_story_content_video.h"
input_story_content_video_t* instantiate_input_story_content_video(int include_optional);



input_story_content_video_t* instantiate_input_story_content_video(int include_optional) {
  input_story_content_video_t* input_story_content_video = NULL;
  if (include_optional) {
    input_story_content_video = input_story_content_video_create(
      "video",
      "0",
      1.337,
      1.337,
      1
    );
  } else {
    input_story_content_video = input_story_content_video_create(
      "video",
      "0",
      1.337,
      1.337,
      1
    );
  }

  return input_story_content_video;
}


#ifdef input_story_content_video_MAIN

void test_input_story_content_video(int include_optional) {
    input_story_content_video_t* input_story_content_video_1 = instantiate_input_story_content_video(include_optional);

	cJSON* jsoninput_story_content_video_1 = input_story_content_video_convertToJSON(input_story_content_video_1);
	printf("input_story_content_video :\n%s\n", cJSON_Print(jsoninput_story_content_video_1));
	input_story_content_video_t* input_story_content_video_2 = input_story_content_video_parseFromJSON(jsoninput_story_content_video_1);
	cJSON* jsoninput_story_content_video_2 = input_story_content_video_convertToJSON(input_story_content_video_2);
	printf("repeating input_story_content_video:\n%s\n", cJSON_Print(jsoninput_story_content_video_2));
}

int main() {
  test_input_story_content_video(1);
  test_input_story_content_video(0);

  printf("Hello world \n");
  return 0;
}

#endif // input_story_content_video_MAIN
#endif // input_story_content_video_TEST
