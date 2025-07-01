#ifndef gift_TEST
#define gift_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define gift_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/gift.h"
gift_t* instantiate_gift(int include_optional);

#include "test_sticker.c"


gift_t* instantiate_gift(int include_optional) {
  gift_t* gift = NULL;
  if (include_optional) {
    gift = gift_create(
      "0",
       // false, not to have infinite recursion
      instantiate_sticker(0),
      56,
      56,
      56,
      56
    );
  } else {
    gift = gift_create(
      "0",
      NULL,
      56,
      56,
      56,
      56
    );
  }

  return gift;
}


#ifdef gift_MAIN

void test_gift(int include_optional) {
    gift_t* gift_1 = instantiate_gift(include_optional);

	cJSON* jsongift_1 = gift_convertToJSON(gift_1);
	printf("gift :\n%s\n", cJSON_Print(jsongift_1));
	gift_t* gift_2 = gift_parseFromJSON(jsongift_1);
	cJSON* jsongift_2 = gift_convertToJSON(gift_2);
	printf("repeating gift:\n%s\n", cJSON_Print(jsongift_2));
}

int main() {
  test_gift(1);
  test_gift(0);

  printf("Hello world \n");
  return 0;
}

#endif // gift_MAIN
#endif // gift_TEST
