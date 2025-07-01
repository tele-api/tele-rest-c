#ifndef gift_info_TEST
#define gift_info_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define gift_info_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/gift_info.h"
gift_info_t* instantiate_gift_info(int include_optional);

#include "test_gift.c"


gift_info_t* instantiate_gift_info(int include_optional) {
  gift_info_t* gift_info = NULL;
  if (include_optional) {
    gift_info = gift_info_create(
       // false, not to have infinite recursion
      instantiate_gift(0),
      "0",
      56,
      56,
      1,
      "0",
      list_createList(),
      1
    );
  } else {
    gift_info = gift_info_create(
      NULL,
      "0",
      56,
      56,
      1,
      "0",
      list_createList(),
      1
    );
  }

  return gift_info;
}


#ifdef gift_info_MAIN

void test_gift_info(int include_optional) {
    gift_info_t* gift_info_1 = instantiate_gift_info(include_optional);

	cJSON* jsongift_info_1 = gift_info_convertToJSON(gift_info_1);
	printf("gift_info :\n%s\n", cJSON_Print(jsongift_info_1));
	gift_info_t* gift_info_2 = gift_info_parseFromJSON(jsongift_info_1);
	cJSON* jsongift_info_2 = gift_info_convertToJSON(gift_info_2);
	printf("repeating gift_info:\n%s\n", cJSON_Print(jsongift_info_2));
}

int main() {
  test_gift_info(1);
  test_gift_info(0);

  printf("Hello world \n");
  return 0;
}

#endif // gift_info_MAIN
#endif // gift_info_TEST
