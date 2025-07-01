#ifndef affiliate_info_TEST
#define affiliate_info_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define affiliate_info_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/affiliate_info.h"
affiliate_info_t* instantiate_affiliate_info(int include_optional);

#include "test_user.c"
#include "test_chat.c"


affiliate_info_t* instantiate_affiliate_info(int include_optional) {
  affiliate_info_t* affiliate_info = NULL;
  if (include_optional) {
    affiliate_info = affiliate_info_create(
      56,
      56,
       // false, not to have infinite recursion
      instantiate_user(0),
       // false, not to have infinite recursion
      instantiate_chat(0),
      56
    );
  } else {
    affiliate_info = affiliate_info_create(
      56,
      56,
      NULL,
      NULL,
      56
    );
  }

  return affiliate_info;
}


#ifdef affiliate_info_MAIN

void test_affiliate_info(int include_optional) {
    affiliate_info_t* affiliate_info_1 = instantiate_affiliate_info(include_optional);

	cJSON* jsonaffiliate_info_1 = affiliate_info_convertToJSON(affiliate_info_1);
	printf("affiliate_info :\n%s\n", cJSON_Print(jsonaffiliate_info_1));
	affiliate_info_t* affiliate_info_2 = affiliate_info_parseFromJSON(jsonaffiliate_info_1);
	cJSON* jsonaffiliate_info_2 = affiliate_info_convertToJSON(affiliate_info_2);
	printf("repeating affiliate_info:\n%s\n", cJSON_Print(jsonaffiliate_info_2));
}

int main() {
  test_affiliate_info(1);
  test_affiliate_info(0);

  printf("Hello world \n");
  return 0;
}

#endif // affiliate_info_MAIN
#endif // affiliate_info_TEST
