#ifndef shipping_option_TEST
#define shipping_option_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define shipping_option_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/shipping_option.h"
shipping_option_t* instantiate_shipping_option(int include_optional);



shipping_option_t* instantiate_shipping_option(int include_optional) {
  shipping_option_t* shipping_option = NULL;
  if (include_optional) {
    shipping_option = shipping_option_create(
      "0",
      "0",
      list_createList()
    );
  } else {
    shipping_option = shipping_option_create(
      "0",
      "0",
      list_createList()
    );
  }

  return shipping_option;
}


#ifdef shipping_option_MAIN

void test_shipping_option(int include_optional) {
    shipping_option_t* shipping_option_1 = instantiate_shipping_option(include_optional);

	cJSON* jsonshipping_option_1 = shipping_option_convertToJSON(shipping_option_1);
	printf("shipping_option :\n%s\n", cJSON_Print(jsonshipping_option_1));
	shipping_option_t* shipping_option_2 = shipping_option_parseFromJSON(jsonshipping_option_1);
	cJSON* jsonshipping_option_2 = shipping_option_convertToJSON(shipping_option_2);
	printf("repeating shipping_option:\n%s\n", cJSON_Print(jsonshipping_option_2));
}

int main() {
  test_shipping_option(1);
  test_shipping_option(0);

  printf("Hello world \n");
  return 0;
}

#endif // shipping_option_MAIN
#endif // shipping_option_TEST
