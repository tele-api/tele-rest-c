#ifndef post_send_media_group_request_media_inner_TEST
#define post_send_media_group_request_media_inner_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define post_send_media_group_request_media_inner_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/post_send_media_group_request_media_inner.h"
post_send_media_group_request_media_inner_t* instantiate_post_send_media_group_request_media_inner(int include_optional);



post_send_media_group_request_media_inner_t* instantiate_post_send_media_group_request_media_inner(int include_optional) {
  post_send_media_group_request_media_inner_t* post_send_media_group_request_media_inner = NULL;
  if (include_optional) {
    post_send_media_group_request_media_inner = post_send_media_group_request_media_inner_create(
      "video",
      "0",
      "0",
      "0",
      "0",
      list_createList(),
      56,
      "0",
      "0",
      1,
      1,
      1,
      "0",
      56,
      56,
      56,
      1
    );
  } else {
    post_send_media_group_request_media_inner = post_send_media_group_request_media_inner_create(
      "video",
      "0",
      "0",
      "0",
      "0",
      list_createList(),
      56,
      "0",
      "0",
      1,
      1,
      1,
      "0",
      56,
      56,
      56,
      1
    );
  }

  return post_send_media_group_request_media_inner;
}


#ifdef post_send_media_group_request_media_inner_MAIN

void test_post_send_media_group_request_media_inner(int include_optional) {
    post_send_media_group_request_media_inner_t* post_send_media_group_request_media_inner_1 = instantiate_post_send_media_group_request_media_inner(include_optional);

	cJSON* jsonpost_send_media_group_request_media_inner_1 = post_send_media_group_request_media_inner_convertToJSON(post_send_media_group_request_media_inner_1);
	printf("post_send_media_group_request_media_inner :\n%s\n", cJSON_Print(jsonpost_send_media_group_request_media_inner_1));
	post_send_media_group_request_media_inner_t* post_send_media_group_request_media_inner_2 = post_send_media_group_request_media_inner_parseFromJSON(jsonpost_send_media_group_request_media_inner_1);
	cJSON* jsonpost_send_media_group_request_media_inner_2 = post_send_media_group_request_media_inner_convertToJSON(post_send_media_group_request_media_inner_2);
	printf("repeating post_send_media_group_request_media_inner:\n%s\n", cJSON_Print(jsonpost_send_media_group_request_media_inner_2));
}

int main() {
  test_post_send_media_group_request_media_inner(1);
  test_post_send_media_group_request_media_inner(0);

  printf("Hello world \n");
  return 0;
}

#endif // post_send_media_group_request_media_inner_MAIN
#endif // post_send_media_group_request_media_inner_TEST
