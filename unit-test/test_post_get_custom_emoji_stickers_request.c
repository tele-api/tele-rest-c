#ifndef post_get_custom_emoji_stickers_request_TEST
#define post_get_custom_emoji_stickers_request_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define post_get_custom_emoji_stickers_request_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/post_get_custom_emoji_stickers_request.h"
post_get_custom_emoji_stickers_request_t* instantiate_post_get_custom_emoji_stickers_request(int include_optional);



post_get_custom_emoji_stickers_request_t* instantiate_post_get_custom_emoji_stickers_request(int include_optional) {
  post_get_custom_emoji_stickers_request_t* post_get_custom_emoji_stickers_request = NULL;
  if (include_optional) {
    post_get_custom_emoji_stickers_request = post_get_custom_emoji_stickers_request_create(
      list_createList()
    );
  } else {
    post_get_custom_emoji_stickers_request = post_get_custom_emoji_stickers_request_create(
      list_createList()
    );
  }

  return post_get_custom_emoji_stickers_request;
}


#ifdef post_get_custom_emoji_stickers_request_MAIN

void test_post_get_custom_emoji_stickers_request(int include_optional) {
    post_get_custom_emoji_stickers_request_t* post_get_custom_emoji_stickers_request_1 = instantiate_post_get_custom_emoji_stickers_request(include_optional);

	cJSON* jsonpost_get_custom_emoji_stickers_request_1 = post_get_custom_emoji_stickers_request_convertToJSON(post_get_custom_emoji_stickers_request_1);
	printf("post_get_custom_emoji_stickers_request :\n%s\n", cJSON_Print(jsonpost_get_custom_emoji_stickers_request_1));
	post_get_custom_emoji_stickers_request_t* post_get_custom_emoji_stickers_request_2 = post_get_custom_emoji_stickers_request_parseFromJSON(jsonpost_get_custom_emoji_stickers_request_1);
	cJSON* jsonpost_get_custom_emoji_stickers_request_2 = post_get_custom_emoji_stickers_request_convertToJSON(post_get_custom_emoji_stickers_request_2);
	printf("repeating post_get_custom_emoji_stickers_request:\n%s\n", cJSON_Print(jsonpost_get_custom_emoji_stickers_request_2));
}

int main() {
  test_post_get_custom_emoji_stickers_request(1);
  test_post_get_custom_emoji_stickers_request(0);

  printf("Hello world \n");
  return 0;
}

#endif // post_get_custom_emoji_stickers_request_MAIN
#endif // post_get_custom_emoji_stickers_request_TEST
