#ifndef unique_gift_info_TEST
#define unique_gift_info_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define unique_gift_info_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/unique_gift_info.h"
unique_gift_info_t* instantiate_unique_gift_info(int include_optional);

#include "test_unique_gift.c"


unique_gift_info_t* instantiate_unique_gift_info(int include_optional) {
  unique_gift_info_t* unique_gift_info = NULL;
  if (include_optional) {
    unique_gift_info = unique_gift_info_create(
       // false, not to have infinite recursion
      instantiate_unique_gift(0),
      telegram_bot_api_unique_gift_info_ORIGIN_upgrade,
      "0",
      56
    );
  } else {
    unique_gift_info = unique_gift_info_create(
      NULL,
      telegram_bot_api_unique_gift_info_ORIGIN_upgrade,
      "0",
      56
    );
  }

  return unique_gift_info;
}


#ifdef unique_gift_info_MAIN

void test_unique_gift_info(int include_optional) {
    unique_gift_info_t* unique_gift_info_1 = instantiate_unique_gift_info(include_optional);

	cJSON* jsonunique_gift_info_1 = unique_gift_info_convertToJSON(unique_gift_info_1);
	printf("unique_gift_info :\n%s\n", cJSON_Print(jsonunique_gift_info_1));
	unique_gift_info_t* unique_gift_info_2 = unique_gift_info_parseFromJSON(jsonunique_gift_info_1);
	cJSON* jsonunique_gift_info_2 = unique_gift_info_convertToJSON(unique_gift_info_2);
	printf("repeating unique_gift_info:\n%s\n", cJSON_Print(jsonunique_gift_info_2));
}

int main() {
  test_unique_gift_info(1);
  test_unique_gift_info(0);

  printf("Hello world \n");
  return 0;
}

#endif // unique_gift_info_MAIN
#endif // unique_gift_info_TEST
