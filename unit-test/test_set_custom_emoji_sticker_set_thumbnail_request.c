#ifndef set_custom_emoji_sticker_set_thumbnail_request_TEST
#define set_custom_emoji_sticker_set_thumbnail_request_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define set_custom_emoji_sticker_set_thumbnail_request_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/set_custom_emoji_sticker_set_thumbnail_request.h"
set_custom_emoji_sticker_set_thumbnail_request_t* instantiate_set_custom_emoji_sticker_set_thumbnail_request(int include_optional);



set_custom_emoji_sticker_set_thumbnail_request_t* instantiate_set_custom_emoji_sticker_set_thumbnail_request(int include_optional) {
  set_custom_emoji_sticker_set_thumbnail_request_t* set_custom_emoji_sticker_set_thumbnail_request = NULL;
  if (include_optional) {
    set_custom_emoji_sticker_set_thumbnail_request = set_custom_emoji_sticker_set_thumbnail_request_create(
      "0",
      "0"
    );
  } else {
    set_custom_emoji_sticker_set_thumbnail_request = set_custom_emoji_sticker_set_thumbnail_request_create(
      "0",
      "0"
    );
  }

  return set_custom_emoji_sticker_set_thumbnail_request;
}


#ifdef set_custom_emoji_sticker_set_thumbnail_request_MAIN

void test_set_custom_emoji_sticker_set_thumbnail_request(int include_optional) {
    set_custom_emoji_sticker_set_thumbnail_request_t* set_custom_emoji_sticker_set_thumbnail_request_1 = instantiate_set_custom_emoji_sticker_set_thumbnail_request(include_optional);

	cJSON* jsonset_custom_emoji_sticker_set_thumbnail_request_1 = set_custom_emoji_sticker_set_thumbnail_request_convertToJSON(set_custom_emoji_sticker_set_thumbnail_request_1);
	printf("set_custom_emoji_sticker_set_thumbnail_request :\n%s\n", cJSON_Print(jsonset_custom_emoji_sticker_set_thumbnail_request_1));
	set_custom_emoji_sticker_set_thumbnail_request_t* set_custom_emoji_sticker_set_thumbnail_request_2 = set_custom_emoji_sticker_set_thumbnail_request_parseFromJSON(jsonset_custom_emoji_sticker_set_thumbnail_request_1);
	cJSON* jsonset_custom_emoji_sticker_set_thumbnail_request_2 = set_custom_emoji_sticker_set_thumbnail_request_convertToJSON(set_custom_emoji_sticker_set_thumbnail_request_2);
	printf("repeating set_custom_emoji_sticker_set_thumbnail_request:\n%s\n", cJSON_Print(jsonset_custom_emoji_sticker_set_thumbnail_request_2));
}

int main() {
  test_set_custom_emoji_sticker_set_thumbnail_request(1);
  test_set_custom_emoji_sticker_set_thumbnail_request(0);

  printf("Hello world \n");
  return 0;
}

#endif // set_custom_emoji_sticker_set_thumbnail_request_MAIN
#endif // set_custom_emoji_sticker_set_thumbnail_request_TEST
