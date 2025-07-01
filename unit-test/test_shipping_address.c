#ifndef shipping_address_TEST
#define shipping_address_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define shipping_address_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/shipping_address.h"
shipping_address_t* instantiate_shipping_address(int include_optional);



shipping_address_t* instantiate_shipping_address(int include_optional) {
  shipping_address_t* shipping_address = NULL;
  if (include_optional) {
    shipping_address = shipping_address_create(
      "0",
      "0",
      "0",
      "0",
      "0",
      "0"
    );
  } else {
    shipping_address = shipping_address_create(
      "0",
      "0",
      "0",
      "0",
      "0",
      "0"
    );
  }

  return shipping_address;
}


#ifdef shipping_address_MAIN

void test_shipping_address(int include_optional) {
    shipping_address_t* shipping_address_1 = instantiate_shipping_address(include_optional);

	cJSON* jsonshipping_address_1 = shipping_address_convertToJSON(shipping_address_1);
	printf("shipping_address :\n%s\n", cJSON_Print(jsonshipping_address_1));
	shipping_address_t* shipping_address_2 = shipping_address_parseFromJSON(jsonshipping_address_1);
	cJSON* jsonshipping_address_2 = shipping_address_convertToJSON(shipping_address_2);
	printf("repeating shipping_address:\n%s\n", cJSON_Print(jsonshipping_address_2));
}

int main() {
  test_shipping_address(1);
  test_shipping_address(0);

  printf("Hello world \n");
  return 0;
}

#endif // shipping_address_MAIN
#endif // shipping_address_TEST
