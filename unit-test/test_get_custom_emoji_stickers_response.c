#ifndef get_custom_emoji_stickers_response_TEST
#define get_custom_emoji_stickers_response_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define get_custom_emoji_stickers_response_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/get_custom_emoji_stickers_response.h"
get_custom_emoji_stickers_response_t* instantiate_get_custom_emoji_stickers_response(int include_optional);



get_custom_emoji_stickers_response_t* instantiate_get_custom_emoji_stickers_response(int include_optional) {
  get_custom_emoji_stickers_response_t* get_custom_emoji_stickers_response = NULL;
  if (include_optional) {
    get_custom_emoji_stickers_response = get_custom_emoji_stickers_response_create(
      1,
      list_createList()
    );
  } else {
    get_custom_emoji_stickers_response = get_custom_emoji_stickers_response_create(
      1,
      list_createList()
    );
  }

  return get_custom_emoji_stickers_response;
}


#ifdef get_custom_emoji_stickers_response_MAIN

void test_get_custom_emoji_stickers_response(int include_optional) {
    get_custom_emoji_stickers_response_t* get_custom_emoji_stickers_response_1 = instantiate_get_custom_emoji_stickers_response(include_optional);

	cJSON* jsonget_custom_emoji_stickers_response_1 = get_custom_emoji_stickers_response_convertToJSON(get_custom_emoji_stickers_response_1);
	printf("get_custom_emoji_stickers_response :\n%s\n", cJSON_Print(jsonget_custom_emoji_stickers_response_1));
	get_custom_emoji_stickers_response_t* get_custom_emoji_stickers_response_2 = get_custom_emoji_stickers_response_parseFromJSON(jsonget_custom_emoji_stickers_response_1);
	cJSON* jsonget_custom_emoji_stickers_response_2 = get_custom_emoji_stickers_response_convertToJSON(get_custom_emoji_stickers_response_2);
	printf("repeating get_custom_emoji_stickers_response:\n%s\n", cJSON_Print(jsonget_custom_emoji_stickers_response_2));
}

int main() {
  test_get_custom_emoji_stickers_response(1);
  test_get_custom_emoji_stickers_response(0);

  printf("Hello world \n");
  return 0;
}

#endif // get_custom_emoji_stickers_response_MAIN
#endif // get_custom_emoji_stickers_response_TEST
