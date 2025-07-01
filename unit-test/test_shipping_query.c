#ifndef shipping_query_TEST
#define shipping_query_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define shipping_query_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/shipping_query.h"
shipping_query_t* instantiate_shipping_query(int include_optional);

#include "test_user.c"
#include "test_shipping_address.c"


shipping_query_t* instantiate_shipping_query(int include_optional) {
  shipping_query_t* shipping_query = NULL;
  if (include_optional) {
    shipping_query = shipping_query_create(
      "0",
       // false, not to have infinite recursion
      instantiate_user(0),
      "0",
       // false, not to have infinite recursion
      instantiate_shipping_address(0)
    );
  } else {
    shipping_query = shipping_query_create(
      "0",
      NULL,
      "0",
      NULL
    );
  }

  return shipping_query;
}


#ifdef shipping_query_MAIN

void test_shipping_query(int include_optional) {
    shipping_query_t* shipping_query_1 = instantiate_shipping_query(include_optional);

	cJSON* jsonshipping_query_1 = shipping_query_convertToJSON(shipping_query_1);
	printf("shipping_query :\n%s\n", cJSON_Print(jsonshipping_query_1));
	shipping_query_t* shipping_query_2 = shipping_query_parseFromJSON(jsonshipping_query_1);
	cJSON* jsonshipping_query_2 = shipping_query_convertToJSON(shipping_query_2);
	printf("repeating shipping_query:\n%s\n", cJSON_Print(jsonshipping_query_2));
}

int main() {
  test_shipping_query(1);
  test_shipping_query(0);

  printf("Hello world \n");
  return 0;
}

#endif // shipping_query_MAIN
#endif // shipping_query_TEST
