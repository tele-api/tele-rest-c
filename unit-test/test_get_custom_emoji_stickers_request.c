#ifndef get_custom_emoji_stickers_request_TEST
#define get_custom_emoji_stickers_request_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define get_custom_emoji_stickers_request_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/get_custom_emoji_stickers_request.h"
get_custom_emoji_stickers_request_t* instantiate_get_custom_emoji_stickers_request(int include_optional);



get_custom_emoji_stickers_request_t* instantiate_get_custom_emoji_stickers_request(int include_optional) {
  get_custom_emoji_stickers_request_t* get_custom_emoji_stickers_request = NULL;
  if (include_optional) {
    get_custom_emoji_stickers_request = get_custom_emoji_stickers_request_create(
      list_createList()
    );
  } else {
    get_custom_emoji_stickers_request = get_custom_emoji_stickers_request_create(
      list_createList()
    );
  }

  return get_custom_emoji_stickers_request;
}


#ifdef get_custom_emoji_stickers_request_MAIN

void test_get_custom_emoji_stickers_request(int include_optional) {
    get_custom_emoji_stickers_request_t* get_custom_emoji_stickers_request_1 = instantiate_get_custom_emoji_stickers_request(include_optional);

	cJSON* jsonget_custom_emoji_stickers_request_1 = get_custom_emoji_stickers_request_convertToJSON(get_custom_emoji_stickers_request_1);
	printf("get_custom_emoji_stickers_request :\n%s\n", cJSON_Print(jsonget_custom_emoji_stickers_request_1));
	get_custom_emoji_stickers_request_t* get_custom_emoji_stickers_request_2 = get_custom_emoji_stickers_request_parseFromJSON(jsonget_custom_emoji_stickers_request_1);
	cJSON* jsonget_custom_emoji_stickers_request_2 = get_custom_emoji_stickers_request_convertToJSON(get_custom_emoji_stickers_request_2);
	printf("repeating get_custom_emoji_stickers_request:\n%s\n", cJSON_Print(jsonget_custom_emoji_stickers_request_2));
}

int main() {
  test_get_custom_emoji_stickers_request(1);
  test_get_custom_emoji_stickers_request(0);

  printf("Hello world \n");
  return 0;
}

#endif // get_custom_emoji_stickers_request_MAIN
#endif // get_custom_emoji_stickers_request_TEST
