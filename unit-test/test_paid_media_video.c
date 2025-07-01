#ifndef paid_media_video_TEST
#define paid_media_video_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define paid_media_video_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/paid_media_video.h"
paid_media_video_t* instantiate_paid_media_video(int include_optional);

#include "test_video.c"


paid_media_video_t* instantiate_paid_media_video(int include_optional) {
  paid_media_video_t* paid_media_video = NULL;
  if (include_optional) {
    paid_media_video = paid_media_video_create(
      "video",
       // false, not to have infinite recursion
      instantiate_video(0)
    );
  } else {
    paid_media_video = paid_media_video_create(
      "video",
      NULL
    );
  }

  return paid_media_video;
}


#ifdef paid_media_video_MAIN

void test_paid_media_video(int include_optional) {
    paid_media_video_t* paid_media_video_1 = instantiate_paid_media_video(include_optional);

	cJSON* jsonpaid_media_video_1 = paid_media_video_convertToJSON(paid_media_video_1);
	printf("paid_media_video :\n%s\n", cJSON_Print(jsonpaid_media_video_1));
	paid_media_video_t* paid_media_video_2 = paid_media_video_parseFromJSON(jsonpaid_media_video_1);
	cJSON* jsonpaid_media_video_2 = paid_media_video_convertToJSON(paid_media_video_2);
	printf("repeating paid_media_video:\n%s\n", cJSON_Print(jsonpaid_media_video_2));
}

int main() {
  test_paid_media_video(1);
  test_paid_media_video(0);

  printf("Hello world \n");
  return 0;
}

#endif // paid_media_video_MAIN
#endif // paid_media_video_TEST
