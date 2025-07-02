#ifndef post_send_video_request_video_TEST
#define post_send_video_request_video_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define post_send_video_request_video_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/post_send_video_request_video.h"
post_send_video_request_video_t* instantiate_post_send_video_request_video(int include_optional);



post_send_video_request_video_t* instantiate_post_send_video_request_video(int include_optional) {
  post_send_video_request_video_t* post_send_video_request_video = NULL;
  if (include_optional) {
    post_send_video_request_video = post_send_video_request_video_create(
    );
  } else {
    post_send_video_request_video = post_send_video_request_video_create(
    );
  }

  return post_send_video_request_video;
}


#ifdef post_send_video_request_video_MAIN

void test_post_send_video_request_video(int include_optional) {
    post_send_video_request_video_t* post_send_video_request_video_1 = instantiate_post_send_video_request_video(include_optional);

	cJSON* jsonpost_send_video_request_video_1 = post_send_video_request_video_convertToJSON(post_send_video_request_video_1);
	printf("post_send_video_request_video :\n%s\n", cJSON_Print(jsonpost_send_video_request_video_1));
	post_send_video_request_video_t* post_send_video_request_video_2 = post_send_video_request_video_parseFromJSON(jsonpost_send_video_request_video_1);
	cJSON* jsonpost_send_video_request_video_2 = post_send_video_request_video_convertToJSON(post_send_video_request_video_2);
	printf("repeating post_send_video_request_video:\n%s\n", cJSON_Print(jsonpost_send_video_request_video_2));
}

int main() {
  test_post_send_video_request_video(1);
  test_post_send_video_request_video(0);

  printf("Hello world \n");
  return 0;
}

#endif // post_send_video_request_video_MAIN
#endif // post_send_video_request_video_TEST
