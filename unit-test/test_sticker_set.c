#ifndef sticker_set_TEST
#define sticker_set_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define sticker_set_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/sticker_set.h"
sticker_set_t* instantiate_sticker_set(int include_optional);

#include "test_photo_size.c"


sticker_set_t* instantiate_sticker_set(int include_optional) {
  sticker_set_t* sticker_set = NULL;
  if (include_optional) {
    sticker_set = sticker_set_create(
      "0",
      "0",
      telegram_bot_api_sticker_set_STICKERTYPE_regular,
      list_createList(),
       // false, not to have infinite recursion
      instantiate_photo_size(0)
    );
  } else {
    sticker_set = sticker_set_create(
      "0",
      "0",
      telegram_bot_api_sticker_set_STICKERTYPE_regular,
      list_createList(),
      NULL
    );
  }

  return sticker_set;
}


#ifdef sticker_set_MAIN

void test_sticker_set(int include_optional) {
    sticker_set_t* sticker_set_1 = instantiate_sticker_set(include_optional);

	cJSON* jsonsticker_set_1 = sticker_set_convertToJSON(sticker_set_1);
	printf("sticker_set :\n%s\n", cJSON_Print(jsonsticker_set_1));
	sticker_set_t* sticker_set_2 = sticker_set_parseFromJSON(jsonsticker_set_1);
	cJSON* jsonsticker_set_2 = sticker_set_convertToJSON(sticker_set_2);
	printf("repeating sticker_set:\n%s\n", cJSON_Print(jsonsticker_set_2));
}

int main() {
  test_sticker_set(1);
  test_sticker_set(0);

  printf("Hello world \n");
  return 0;
}

#endif // sticker_set_MAIN
#endif // sticker_set_TEST
