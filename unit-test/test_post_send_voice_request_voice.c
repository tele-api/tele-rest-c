#ifndef post_send_voice_request_voice_TEST
#define post_send_voice_request_voice_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define post_send_voice_request_voice_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/post_send_voice_request_voice.h"
post_send_voice_request_voice_t* instantiate_post_send_voice_request_voice(int include_optional);



post_send_voice_request_voice_t* instantiate_post_send_voice_request_voice(int include_optional) {
  post_send_voice_request_voice_t* post_send_voice_request_voice = NULL;
  if (include_optional) {
    post_send_voice_request_voice = post_send_voice_request_voice_create(
    );
  } else {
    post_send_voice_request_voice = post_send_voice_request_voice_create(
    );
  }

  return post_send_voice_request_voice;
}


#ifdef post_send_voice_request_voice_MAIN

void test_post_send_voice_request_voice(int include_optional) {
    post_send_voice_request_voice_t* post_send_voice_request_voice_1 = instantiate_post_send_voice_request_voice(include_optional);

	cJSON* jsonpost_send_voice_request_voice_1 = post_send_voice_request_voice_convertToJSON(post_send_voice_request_voice_1);
	printf("post_send_voice_request_voice :\n%s\n", cJSON_Print(jsonpost_send_voice_request_voice_1));
	post_send_voice_request_voice_t* post_send_voice_request_voice_2 = post_send_voice_request_voice_parseFromJSON(jsonpost_send_voice_request_voice_1);
	cJSON* jsonpost_send_voice_request_voice_2 = post_send_voice_request_voice_convertToJSON(post_send_voice_request_voice_2);
	printf("repeating post_send_voice_request_voice:\n%s\n", cJSON_Print(jsonpost_send_voice_request_voice_2));
}

int main() {
  test_post_send_voice_request_voice(1);
  test_post_send_voice_request_voice(0);

  printf("Hello world \n");
  return 0;
}

#endif // post_send_voice_request_voice_MAIN
#endif // post_send_voice_request_voice_TEST
