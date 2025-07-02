#ifndef set_sticker_emoji_list_response_TEST
#define set_sticker_emoji_list_response_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define set_sticker_emoji_list_response_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/set_sticker_emoji_list_response.h"
set_sticker_emoji_list_response_t* instantiate_set_sticker_emoji_list_response(int include_optional);



set_sticker_emoji_list_response_t* instantiate_set_sticker_emoji_list_response(int include_optional) {
  set_sticker_emoji_list_response_t* set_sticker_emoji_list_response = NULL;
  if (include_optional) {
    set_sticker_emoji_list_response = set_sticker_emoji_list_response_create(
      1,
      1
    );
  } else {
    set_sticker_emoji_list_response = set_sticker_emoji_list_response_create(
      1,
      1
    );
  }

  return set_sticker_emoji_list_response;
}


#ifdef set_sticker_emoji_list_response_MAIN

void test_set_sticker_emoji_list_response(int include_optional) {
    set_sticker_emoji_list_response_t* set_sticker_emoji_list_response_1 = instantiate_set_sticker_emoji_list_response(include_optional);

	cJSON* jsonset_sticker_emoji_list_response_1 = set_sticker_emoji_list_response_convertToJSON(set_sticker_emoji_list_response_1);
	printf("set_sticker_emoji_list_response :\n%s\n", cJSON_Print(jsonset_sticker_emoji_list_response_1));
	set_sticker_emoji_list_response_t* set_sticker_emoji_list_response_2 = set_sticker_emoji_list_response_parseFromJSON(jsonset_sticker_emoji_list_response_1);
	cJSON* jsonset_sticker_emoji_list_response_2 = set_sticker_emoji_list_response_convertToJSON(set_sticker_emoji_list_response_2);
	printf("repeating set_sticker_emoji_list_response:\n%s\n", cJSON_Print(jsonset_sticker_emoji_list_response_2));
}

int main() {
  test_set_sticker_emoji_list_response(1);
  test_set_sticker_emoji_list_response(0);

  printf("Hello world \n");
  return 0;
}

#endif // set_sticker_emoji_list_response_MAIN
#endif // set_sticker_emoji_list_response_TEST
