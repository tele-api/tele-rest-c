#ifndef owned_gift_unique_TEST
#define owned_gift_unique_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define owned_gift_unique_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/owned_gift_unique.h"
owned_gift_unique_t* instantiate_owned_gift_unique(int include_optional);

#include "test_unique_gift.c"
#include "test_user.c"


owned_gift_unique_t* instantiate_owned_gift_unique(int include_optional) {
  owned_gift_unique_t* owned_gift_unique = NULL;
  if (include_optional) {
    owned_gift_unique = owned_gift_unique_create(
      "unique",
       // false, not to have infinite recursion
      instantiate_unique_gift(0),
      56,
      "0",
       // false, not to have infinite recursion
      instantiate_user(0),
      1,
      1,
      56
    );
  } else {
    owned_gift_unique = owned_gift_unique_create(
      "unique",
      NULL,
      56,
      "0",
      NULL,
      1,
      1,
      56
    );
  }

  return owned_gift_unique;
}


#ifdef owned_gift_unique_MAIN

void test_owned_gift_unique(int include_optional) {
    owned_gift_unique_t* owned_gift_unique_1 = instantiate_owned_gift_unique(include_optional);

	cJSON* jsonowned_gift_unique_1 = owned_gift_unique_convertToJSON(owned_gift_unique_1);
	printf("owned_gift_unique :\n%s\n", cJSON_Print(jsonowned_gift_unique_1));
	owned_gift_unique_t* owned_gift_unique_2 = owned_gift_unique_parseFromJSON(jsonowned_gift_unique_1);
	cJSON* jsonowned_gift_unique_2 = owned_gift_unique_convertToJSON(owned_gift_unique_2);
	printf("repeating owned_gift_unique:\n%s\n", cJSON_Print(jsonowned_gift_unique_2));
}

int main() {
  test_owned_gift_unique(1);
  test_owned_gift_unique(0);

  printf("Hello world \n");
  return 0;
}

#endif // owned_gift_unique_MAIN
#endif // owned_gift_unique_TEST
