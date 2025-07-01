#ifndef owned_gift_TEST
#define owned_gift_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define owned_gift_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/owned_gift.h"
owned_gift_t* instantiate_owned_gift(int include_optional);

#include "test_unique_gift.c"
#include "test_user.c"


owned_gift_t* instantiate_owned_gift(int include_optional) {
  owned_gift_t* owned_gift = NULL;
  if (include_optional) {
    owned_gift = owned_gift_create(
      "unique",
       // false, not to have infinite recursion
      instantiate_unique_gift(0),
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
      56,
      1,
      56
    );
  } else {
    owned_gift = owned_gift_create(
      "unique",
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
      56,
      1,
      56
    );
  }

  return owned_gift;
}


#ifdef owned_gift_MAIN

void test_owned_gift(int include_optional) {
    owned_gift_t* owned_gift_1 = instantiate_owned_gift(include_optional);

	cJSON* jsonowned_gift_1 = owned_gift_convertToJSON(owned_gift_1);
	printf("owned_gift :\n%s\n", cJSON_Print(jsonowned_gift_1));
	owned_gift_t* owned_gift_2 = owned_gift_parseFromJSON(jsonowned_gift_1);
	cJSON* jsonowned_gift_2 = owned_gift_convertToJSON(owned_gift_2);
	printf("repeating owned_gift:\n%s\n", cJSON_Print(jsonowned_gift_2));
}

int main() {
  test_owned_gift(1);
  test_owned_gift(0);

  printf("Hello world \n");
  return 0;
}

#endif // owned_gift_MAIN
#endif // owned_gift_TEST
