#ifndef order_info_TEST
#define order_info_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define order_info_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/order_info.h"
order_info_t* instantiate_order_info(int include_optional);

#include "test_shipping_address.c"


order_info_t* instantiate_order_info(int include_optional) {
  order_info_t* order_info = NULL;
  if (include_optional) {
    order_info = order_info_create(
      "0",
      "0",
      "0",
       // false, not to have infinite recursion
      instantiate_shipping_address(0)
    );
  } else {
    order_info = order_info_create(
      "0",
      "0",
      "0",
      NULL
    );
  }

  return order_info;
}


#ifdef order_info_MAIN

void test_order_info(int include_optional) {
    order_info_t* order_info_1 = instantiate_order_info(include_optional);

	cJSON* jsonorder_info_1 = order_info_convertToJSON(order_info_1);
	printf("order_info :\n%s\n", cJSON_Print(jsonorder_info_1));
	order_info_t* order_info_2 = order_info_parseFromJSON(jsonorder_info_1);
	cJSON* jsonorder_info_2 = order_info_convertToJSON(order_info_2);
	printf("repeating order_info:\n%s\n", cJSON_Print(jsonorder_info_2));
}

int main() {
  test_order_info(1);
  test_order_info(0);

  printf("Hello world \n");
  return 0;
}

#endif // order_info_MAIN
#endif // order_info_TEST
