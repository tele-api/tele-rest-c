#ifndef post_send_sticker_request_sticker_TEST
#define post_send_sticker_request_sticker_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define post_send_sticker_request_sticker_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/post_send_sticker_request_sticker.h"
post_send_sticker_request_sticker_t* instantiate_post_send_sticker_request_sticker(int include_optional);



post_send_sticker_request_sticker_t* instantiate_post_send_sticker_request_sticker(int include_optional) {
  post_send_sticker_request_sticker_t* post_send_sticker_request_sticker = NULL;
  if (include_optional) {
    post_send_sticker_request_sticker = post_send_sticker_request_sticker_create(
    );
  } else {
    post_send_sticker_request_sticker = post_send_sticker_request_sticker_create(
    );
  }

  return post_send_sticker_request_sticker;
}


#ifdef post_send_sticker_request_sticker_MAIN

void test_post_send_sticker_request_sticker(int include_optional) {
    post_send_sticker_request_sticker_t* post_send_sticker_request_sticker_1 = instantiate_post_send_sticker_request_sticker(include_optional);

	cJSON* jsonpost_send_sticker_request_sticker_1 = post_send_sticker_request_sticker_convertToJSON(post_send_sticker_request_sticker_1);
	printf("post_send_sticker_request_sticker :\n%s\n", cJSON_Print(jsonpost_send_sticker_request_sticker_1));
	post_send_sticker_request_sticker_t* post_send_sticker_request_sticker_2 = post_send_sticker_request_sticker_parseFromJSON(jsonpost_send_sticker_request_sticker_1);
	cJSON* jsonpost_send_sticker_request_sticker_2 = post_send_sticker_request_sticker_convertToJSON(post_send_sticker_request_sticker_2);
	printf("repeating post_send_sticker_request_sticker:\n%s\n", cJSON_Print(jsonpost_send_sticker_request_sticker_2));
}

int main() {
  test_post_send_sticker_request_sticker(1);
  test_post_send_sticker_request_sticker(0);

  printf("Hello world \n");
  return 0;
}

#endif // post_send_sticker_request_sticker_MAIN
#endif // post_send_sticker_request_sticker_TEST
