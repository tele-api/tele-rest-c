#ifndef owned_gift_regular_TEST
#define owned_gift_regular_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define owned_gift_regular_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/owned_gift_regular.h"
owned_gift_regular_t* instantiate_owned_gift_regular(int include_optional);

#include "test_gift.c"
#include "test_user.c"


owned_gift_regular_t* instantiate_owned_gift_regular(int include_optional) {
  owned_gift_regular_t* owned_gift_regular = NULL;
  if (include_optional) {
    owned_gift_regular = owned_gift_regular_create(
      "regular",
       // false, not to have infinite recursion
      instantiate_gift(0),
      56,
      "0",
       // false, not to have infinite recursion
      instantiate_user(0),
      "0",
      list_createList(),
      1,
      1,
      1,
      1,
      56,
      56
    );
  } else {
    owned_gift_regular = owned_gift_regular_create(
      "regular",
      NULL,
      56,
      "0",
      NULL,
      "0",
      list_createList(),
      1,
      1,
      1,
      1,
      56,
      56
    );
  }

  return owned_gift_regular;
}


#ifdef owned_gift_regular_MAIN

void test_owned_gift_regular(int include_optional) {
    owned_gift_regular_t* owned_gift_regular_1 = instantiate_owned_gift_regular(include_optional);

	cJSON* jsonowned_gift_regular_1 = owned_gift_regular_convertToJSON(owned_gift_regular_1);
	printf("owned_gift_regular :\n%s\n", cJSON_Print(jsonowned_gift_regular_1));
	owned_gift_regular_t* owned_gift_regular_2 = owned_gift_regular_parseFromJSON(jsonowned_gift_regular_1);
	cJSON* jsonowned_gift_regular_2 = owned_gift_regular_convertToJSON(owned_gift_regular_2);
	printf("repeating owned_gift_regular:\n%s\n", cJSON_Print(jsonowned_gift_regular_2));
}

int main() {
  test_owned_gift_regular(1);
  test_owned_gift_regular(0);

  printf("Hello world \n");
  return 0;
}

#endif // owned_gift_regular_MAIN
#endif // owned_gift_regular_TEST
