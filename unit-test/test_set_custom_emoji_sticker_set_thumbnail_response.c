#ifndef set_custom_emoji_sticker_set_thumbnail_response_TEST
#define set_custom_emoji_sticker_set_thumbnail_response_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define set_custom_emoji_sticker_set_thumbnail_response_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/set_custom_emoji_sticker_set_thumbnail_response.h"
set_custom_emoji_sticker_set_thumbnail_response_t* instantiate_set_custom_emoji_sticker_set_thumbnail_response(int include_optional);



set_custom_emoji_sticker_set_thumbnail_response_t* instantiate_set_custom_emoji_sticker_set_thumbnail_response(int include_optional) {
  set_custom_emoji_sticker_set_thumbnail_response_t* set_custom_emoji_sticker_set_thumbnail_response = NULL;
  if (include_optional) {
    set_custom_emoji_sticker_set_thumbnail_response = set_custom_emoji_sticker_set_thumbnail_response_create(
      1,
      1
    );
  } else {
    set_custom_emoji_sticker_set_thumbnail_response = set_custom_emoji_sticker_set_thumbnail_response_create(
      1,
      1
    );
  }

  return set_custom_emoji_sticker_set_thumbnail_response;
}


#ifdef set_custom_emoji_sticker_set_thumbnail_response_MAIN

void test_set_custom_emoji_sticker_set_thumbnail_response(int include_optional) {
    set_custom_emoji_sticker_set_thumbnail_response_t* set_custom_emoji_sticker_set_thumbnail_response_1 = instantiate_set_custom_emoji_sticker_set_thumbnail_response(include_optional);

	cJSON* jsonset_custom_emoji_sticker_set_thumbnail_response_1 = set_custom_emoji_sticker_set_thumbnail_response_convertToJSON(set_custom_emoji_sticker_set_thumbnail_response_1);
	printf("set_custom_emoji_sticker_set_thumbnail_response :\n%s\n", cJSON_Print(jsonset_custom_emoji_sticker_set_thumbnail_response_1));
	set_custom_emoji_sticker_set_thumbnail_response_t* set_custom_emoji_sticker_set_thumbnail_response_2 = set_custom_emoji_sticker_set_thumbnail_response_parseFromJSON(jsonset_custom_emoji_sticker_set_thumbnail_response_1);
	cJSON* jsonset_custom_emoji_sticker_set_thumbnail_response_2 = set_custom_emoji_sticker_set_thumbnail_response_convertToJSON(set_custom_emoji_sticker_set_thumbnail_response_2);
	printf("repeating set_custom_emoji_sticker_set_thumbnail_response:\n%s\n", cJSON_Print(jsonset_custom_emoji_sticker_set_thumbnail_response_2));
}

int main() {
  test_set_custom_emoji_sticker_set_thumbnail_response(1);
  test_set_custom_emoji_sticker_set_thumbnail_response(0);

  printf("Hello world \n");
  return 0;
}

#endif // set_custom_emoji_sticker_set_thumbnail_response_MAIN
#endif // set_custom_emoji_sticker_set_thumbnail_response_TEST
