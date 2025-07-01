#ifndef sticker_TEST
#define sticker_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define sticker_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/sticker.h"
sticker_t* instantiate_sticker(int include_optional);

#include "test_photo_size.c"
#include "test_binary_t*.c"
#include "test_mask_position.c"


sticker_t* instantiate_sticker(int include_optional) {
  sticker_t* sticker = NULL;
  if (include_optional) {
    sticker = sticker_create(
      "0",
      "0",
      telegram_bot_api_sticker_TYPE_regular,
      56,
      56,
      1,
      1,
       // false, not to have infinite recursion
      instantiate_photo_size(0),
      "0",
      "0",
       // false, not to have infinite recursion
      instantiate_binary_t*(0),
       // false, not to have infinite recursion
      instantiate_mask_position(0),
      "0",
      1,
      56
    );
  } else {
    sticker = sticker_create(
      "0",
      "0",
      telegram_bot_api_sticker_TYPE_regular,
      56,
      56,
      1,
      1,
      NULL,
      "0",
      "0",
      NULL,
      NULL,
      "0",
      1,
      56
    );
  }

  return sticker;
}


#ifdef sticker_MAIN

void test_sticker(int include_optional) {
    sticker_t* sticker_1 = instantiate_sticker(include_optional);

	cJSON* jsonsticker_1 = sticker_convertToJSON(sticker_1);
	printf("sticker :\n%s\n", cJSON_Print(jsonsticker_1));
	sticker_t* sticker_2 = sticker_parseFromJSON(jsonsticker_1);
	cJSON* jsonsticker_2 = sticker_convertToJSON(sticker_2);
	printf("repeating sticker:\n%s\n", cJSON_Print(jsonsticker_2));
}

int main() {
  test_sticker(1);
  test_sticker(0);

  printf("Hello world \n");
  return 0;
}

#endif // sticker_MAIN
#endif // sticker_TEST
