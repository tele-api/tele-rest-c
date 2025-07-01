#ifndef input_paid_media_video_TEST
#define input_paid_media_video_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define input_paid_media_video_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/input_paid_media_video.h"
input_paid_media_video_t* instantiate_input_paid_media_video(int include_optional);



input_paid_media_video_t* instantiate_input_paid_media_video(int include_optional) {
  input_paid_media_video_t* input_paid_media_video = NULL;
  if (include_optional) {
    input_paid_media_video = input_paid_media_video_create(
      "video",
      "0",
      "0",
      "0",
      56,
      56,
      56,
      56,
      1
    );
  } else {
    input_paid_media_video = input_paid_media_video_create(
      "video",
      "0",
      "0",
      "0",
      56,
      56,
      56,
      56,
      1
    );
  }

  return input_paid_media_video;
}


#ifdef input_paid_media_video_MAIN

void test_input_paid_media_video(int include_optional) {
    input_paid_media_video_t* input_paid_media_video_1 = instantiate_input_paid_media_video(include_optional);

	cJSON* jsoninput_paid_media_video_1 = input_paid_media_video_convertToJSON(input_paid_media_video_1);
	printf("input_paid_media_video :\n%s\n", cJSON_Print(jsoninput_paid_media_video_1));
	input_paid_media_video_t* input_paid_media_video_2 = input_paid_media_video_parseFromJSON(jsoninput_paid_media_video_1);
	cJSON* jsoninput_paid_media_video_2 = input_paid_media_video_convertToJSON(input_paid_media_video_2);
	printf("repeating input_paid_media_video:\n%s\n", cJSON_Print(jsoninput_paid_media_video_2));
}

int main() {
  test_input_paid_media_video(1);
  test_input_paid_media_video(0);

  printf("Hello world \n");
  return 0;
}

#endif // input_paid_media_video_MAIN
#endif // input_paid_media_video_TEST
