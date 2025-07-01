#ifndef unique_gift_TEST
#define unique_gift_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define unique_gift_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/unique_gift.h"
unique_gift_t* instantiate_unique_gift(int include_optional);

#include "test_unique_gift_model.c"
#include "test_unique_gift_symbol.c"
#include "test_unique_gift_backdrop.c"


unique_gift_t* instantiate_unique_gift(int include_optional) {
  unique_gift_t* unique_gift = NULL;
  if (include_optional) {
    unique_gift = unique_gift_create(
      "0",
      "0",
      56,
       // false, not to have infinite recursion
      instantiate_unique_gift_model(0),
       // false, not to have infinite recursion
      instantiate_unique_gift_symbol(0),
       // false, not to have infinite recursion
      instantiate_unique_gift_backdrop(0)
    );
  } else {
    unique_gift = unique_gift_create(
      "0",
      "0",
      56,
      NULL,
      NULL,
      NULL
    );
  }

  return unique_gift;
}


#ifdef unique_gift_MAIN

void test_unique_gift(int include_optional) {
    unique_gift_t* unique_gift_1 = instantiate_unique_gift(include_optional);

	cJSON* jsonunique_gift_1 = unique_gift_convertToJSON(unique_gift_1);
	printf("unique_gift :\n%s\n", cJSON_Print(jsonunique_gift_1));
	unique_gift_t* unique_gift_2 = unique_gift_parseFromJSON(jsonunique_gift_1);
	cJSON* jsonunique_gift_2 = unique_gift_convertToJSON(unique_gift_2);
	printf("repeating unique_gift:\n%s\n", cJSON_Print(jsonunique_gift_2));
}

int main() {
  test_unique_gift(1);
  test_unique_gift(0);

  printf("Hello world \n");
  return 0;
}

#endif // unique_gift_MAIN
#endif // unique_gift_TEST
