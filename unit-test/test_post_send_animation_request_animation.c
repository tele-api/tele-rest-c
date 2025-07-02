#ifndef post_send_animation_request_animation_TEST
#define post_send_animation_request_animation_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define post_send_animation_request_animation_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/post_send_animation_request_animation.h"
post_send_animation_request_animation_t* instantiate_post_send_animation_request_animation(int include_optional);



post_send_animation_request_animation_t* instantiate_post_send_animation_request_animation(int include_optional) {
  post_send_animation_request_animation_t* post_send_animation_request_animation = NULL;
  if (include_optional) {
    post_send_animation_request_animation = post_send_animation_request_animation_create(
    );
  } else {
    post_send_animation_request_animation = post_send_animation_request_animation_create(
    );
  }

  return post_send_animation_request_animation;
}


#ifdef post_send_animation_request_animation_MAIN

void test_post_send_animation_request_animation(int include_optional) {
    post_send_animation_request_animation_t* post_send_animation_request_animation_1 = instantiate_post_send_animation_request_animation(include_optional);

	cJSON* jsonpost_send_animation_request_animation_1 = post_send_animation_request_animation_convertToJSON(post_send_animation_request_animation_1);
	printf("post_send_animation_request_animation :\n%s\n", cJSON_Print(jsonpost_send_animation_request_animation_1));
	post_send_animation_request_animation_t* post_send_animation_request_animation_2 = post_send_animation_request_animation_parseFromJSON(jsonpost_send_animation_request_animation_1);
	cJSON* jsonpost_send_animation_request_animation_2 = post_send_animation_request_animation_convertToJSON(post_send_animation_request_animation_2);
	printf("repeating post_send_animation_request_animation:\n%s\n", cJSON_Print(jsonpost_send_animation_request_animation_2));
}

int main() {
  test_post_send_animation_request_animation(1);
  test_post_send_animation_request_animation(0);

  printf("Hello world \n");
  return 0;
}

#endif // post_send_animation_request_animation_MAIN
#endif // post_send_animation_request_animation_TEST
