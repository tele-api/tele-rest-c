#ifndef post_send_video_request_cover_TEST
#define post_send_video_request_cover_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define post_send_video_request_cover_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/post_send_video_request_cover.h"
post_send_video_request_cover_t* instantiate_post_send_video_request_cover(int include_optional);



post_send_video_request_cover_t* instantiate_post_send_video_request_cover(int include_optional) {
  post_send_video_request_cover_t* post_send_video_request_cover = NULL;
  if (include_optional) {
    post_send_video_request_cover = post_send_video_request_cover_create(
    );
  } else {
    post_send_video_request_cover = post_send_video_request_cover_create(
    );
  }

  return post_send_video_request_cover;
}


#ifdef post_send_video_request_cover_MAIN

void test_post_send_video_request_cover(int include_optional) {
    post_send_video_request_cover_t* post_send_video_request_cover_1 = instantiate_post_send_video_request_cover(include_optional);

	cJSON* jsonpost_send_video_request_cover_1 = post_send_video_request_cover_convertToJSON(post_send_video_request_cover_1);
	printf("post_send_video_request_cover :\n%s\n", cJSON_Print(jsonpost_send_video_request_cover_1));
	post_send_video_request_cover_t* post_send_video_request_cover_2 = post_send_video_request_cover_parseFromJSON(jsonpost_send_video_request_cover_1);
	cJSON* jsonpost_send_video_request_cover_2 = post_send_video_request_cover_convertToJSON(post_send_video_request_cover_2);
	printf("repeating post_send_video_request_cover:\n%s\n", cJSON_Print(jsonpost_send_video_request_cover_2));
}

int main() {
  test_post_send_video_request_cover(1);
  test_post_send_video_request_cover(0);

  printf("Hello world \n");
  return 0;
}

#endif // post_send_video_request_cover_MAIN
#endif // post_send_video_request_cover_TEST
