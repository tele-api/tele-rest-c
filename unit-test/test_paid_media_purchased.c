#ifndef paid_media_purchased_TEST
#define paid_media_purchased_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define paid_media_purchased_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/paid_media_purchased.h"
paid_media_purchased_t* instantiate_paid_media_purchased(int include_optional);

#include "test_user.c"


paid_media_purchased_t* instantiate_paid_media_purchased(int include_optional) {
  paid_media_purchased_t* paid_media_purchased = NULL;
  if (include_optional) {
    paid_media_purchased = paid_media_purchased_create(
       // false, not to have infinite recursion
      instantiate_user(0),
      "0"
    );
  } else {
    paid_media_purchased = paid_media_purchased_create(
      NULL,
      "0"
    );
  }

  return paid_media_purchased;
}


#ifdef paid_media_purchased_MAIN

void test_paid_media_purchased(int include_optional) {
    paid_media_purchased_t* paid_media_purchased_1 = instantiate_paid_media_purchased(include_optional);

	cJSON* jsonpaid_media_purchased_1 = paid_media_purchased_convertToJSON(paid_media_purchased_1);
	printf("paid_media_purchased :\n%s\n", cJSON_Print(jsonpaid_media_purchased_1));
	paid_media_purchased_t* paid_media_purchased_2 = paid_media_purchased_parseFromJSON(jsonpaid_media_purchased_1);
	cJSON* jsonpaid_media_purchased_2 = paid_media_purchased_convertToJSON(paid_media_purchased_2);
	printf("repeating paid_media_purchased:\n%s\n", cJSON_Print(jsonpaid_media_purchased_2));
}

int main() {
  test_paid_media_purchased(1);
  test_paid_media_purchased(0);

  printf("Hello world \n");
  return 0;
}

#endif // paid_media_purchased_MAIN
#endif // paid_media_purchased_TEST
