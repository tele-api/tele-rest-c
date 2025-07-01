#ifndef unique_gift_symbol_TEST
#define unique_gift_symbol_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define unique_gift_symbol_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/unique_gift_symbol.h"
unique_gift_symbol_t* instantiate_unique_gift_symbol(int include_optional);

#include "test_sticker.c"


unique_gift_symbol_t* instantiate_unique_gift_symbol(int include_optional) {
  unique_gift_symbol_t* unique_gift_symbol = NULL;
  if (include_optional) {
    unique_gift_symbol = unique_gift_symbol_create(
      "0",
       // false, not to have infinite recursion
      instantiate_sticker(0),
      56
    );
  } else {
    unique_gift_symbol = unique_gift_symbol_create(
      "0",
      NULL,
      56
    );
  }

  return unique_gift_symbol;
}


#ifdef unique_gift_symbol_MAIN

void test_unique_gift_symbol(int include_optional) {
    unique_gift_symbol_t* unique_gift_symbol_1 = instantiate_unique_gift_symbol(include_optional);

	cJSON* jsonunique_gift_symbol_1 = unique_gift_symbol_convertToJSON(unique_gift_symbol_1);
	printf("unique_gift_symbol :\n%s\n", cJSON_Print(jsonunique_gift_symbol_1));
	unique_gift_symbol_t* unique_gift_symbol_2 = unique_gift_symbol_parseFromJSON(jsonunique_gift_symbol_1);
	cJSON* jsonunique_gift_symbol_2 = unique_gift_symbol_convertToJSON(unique_gift_symbol_2);
	printf("repeating unique_gift_symbol:\n%s\n", cJSON_Print(jsonunique_gift_symbol_2));
}

int main() {
  test_unique_gift_symbol(1);
  test_unique_gift_symbol(0);

  printf("Hello world \n");
  return 0;
}

#endif // unique_gift_symbol_MAIN
#endif // unique_gift_symbol_TEST
