#ifndef post_send_audio_request_audio_TEST
#define post_send_audio_request_audio_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define post_send_audio_request_audio_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/post_send_audio_request_audio.h"
post_send_audio_request_audio_t* instantiate_post_send_audio_request_audio(int include_optional);



post_send_audio_request_audio_t* instantiate_post_send_audio_request_audio(int include_optional) {
  post_send_audio_request_audio_t* post_send_audio_request_audio = NULL;
  if (include_optional) {
    post_send_audio_request_audio = post_send_audio_request_audio_create(
    );
  } else {
    post_send_audio_request_audio = post_send_audio_request_audio_create(
    );
  }

  return post_send_audio_request_audio;
}


#ifdef post_send_audio_request_audio_MAIN

void test_post_send_audio_request_audio(int include_optional) {
    post_send_audio_request_audio_t* post_send_audio_request_audio_1 = instantiate_post_send_audio_request_audio(include_optional);

	cJSON* jsonpost_send_audio_request_audio_1 = post_send_audio_request_audio_convertToJSON(post_send_audio_request_audio_1);
	printf("post_send_audio_request_audio :\n%s\n", cJSON_Print(jsonpost_send_audio_request_audio_1));
	post_send_audio_request_audio_t* post_send_audio_request_audio_2 = post_send_audio_request_audio_parseFromJSON(jsonpost_send_audio_request_audio_1);
	cJSON* jsonpost_send_audio_request_audio_2 = post_send_audio_request_audio_convertToJSON(post_send_audio_request_audio_2);
	printf("repeating post_send_audio_request_audio:\n%s\n", cJSON_Print(jsonpost_send_audio_request_audio_2));
}

int main() {
  test_post_send_audio_request_audio(1);
  test_post_send_audio_request_audio(0);

  printf("Hello world \n");
  return 0;
}

#endif // post_send_audio_request_audio_MAIN
#endif // post_send_audio_request_audio_TEST
