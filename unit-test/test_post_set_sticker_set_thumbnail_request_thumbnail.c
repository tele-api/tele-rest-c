#ifndef post_set_sticker_set_thumbnail_request_thumbnail_TEST
#define post_set_sticker_set_thumbnail_request_thumbnail_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define post_set_sticker_set_thumbnail_request_thumbnail_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/post_set_sticker_set_thumbnail_request_thumbnail.h"
post_set_sticker_set_thumbnail_request_thumbnail_t* instantiate_post_set_sticker_set_thumbnail_request_thumbnail(int include_optional);



post_set_sticker_set_thumbnail_request_thumbnail_t* instantiate_post_set_sticker_set_thumbnail_request_thumbnail(int include_optional) {
  post_set_sticker_set_thumbnail_request_thumbnail_t* post_set_sticker_set_thumbnail_request_thumbnail = NULL;
  if (include_optional) {
    post_set_sticker_set_thumbnail_request_thumbnail = post_set_sticker_set_thumbnail_request_thumbnail_create(
    );
  } else {
    post_set_sticker_set_thumbnail_request_thumbnail = post_set_sticker_set_thumbnail_request_thumbnail_create(
    );
  }

  return post_set_sticker_set_thumbnail_request_thumbnail;
}


#ifdef post_set_sticker_set_thumbnail_request_thumbnail_MAIN

void test_post_set_sticker_set_thumbnail_request_thumbnail(int include_optional) {
    post_set_sticker_set_thumbnail_request_thumbnail_t* post_set_sticker_set_thumbnail_request_thumbnail_1 = instantiate_post_set_sticker_set_thumbnail_request_thumbnail(include_optional);

	cJSON* jsonpost_set_sticker_set_thumbnail_request_thumbnail_1 = post_set_sticker_set_thumbnail_request_thumbnail_convertToJSON(post_set_sticker_set_thumbnail_request_thumbnail_1);
	printf("post_set_sticker_set_thumbnail_request_thumbnail :\n%s\n", cJSON_Print(jsonpost_set_sticker_set_thumbnail_request_thumbnail_1));
	post_set_sticker_set_thumbnail_request_thumbnail_t* post_set_sticker_set_thumbnail_request_thumbnail_2 = post_set_sticker_set_thumbnail_request_thumbnail_parseFromJSON(jsonpost_set_sticker_set_thumbnail_request_thumbnail_1);
	cJSON* jsonpost_set_sticker_set_thumbnail_request_thumbnail_2 = post_set_sticker_set_thumbnail_request_thumbnail_convertToJSON(post_set_sticker_set_thumbnail_request_thumbnail_2);
	printf("repeating post_set_sticker_set_thumbnail_request_thumbnail:\n%s\n", cJSON_Print(jsonpost_set_sticker_set_thumbnail_request_thumbnail_2));
}

int main() {
  test_post_set_sticker_set_thumbnail_request_thumbnail(1);
  test_post_set_sticker_set_thumbnail_request_thumbnail(0);

  printf("Hello world \n");
  return 0;
}

#endif // post_set_sticker_set_thumbnail_request_thumbnail_MAIN
#endif // post_set_sticker_set_thumbnail_request_thumbnail_TEST
