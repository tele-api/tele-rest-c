#ifndef owned_gifts_TEST
#define owned_gifts_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define owned_gifts_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/owned_gifts.h"
owned_gifts_t* instantiate_owned_gifts(int include_optional);



owned_gifts_t* instantiate_owned_gifts(int include_optional) {
  owned_gifts_t* owned_gifts = NULL;
  if (include_optional) {
    owned_gifts = owned_gifts_create(
      56,
      list_createList(),
      "0"
    );
  } else {
    owned_gifts = owned_gifts_create(
      56,
      list_createList(),
      "0"
    );
  }

  return owned_gifts;
}


#ifdef owned_gifts_MAIN

void test_owned_gifts(int include_optional) {
    owned_gifts_t* owned_gifts_1 = instantiate_owned_gifts(include_optional);

	cJSON* jsonowned_gifts_1 = owned_gifts_convertToJSON(owned_gifts_1);
	printf("owned_gifts :\n%s\n", cJSON_Print(jsonowned_gifts_1));
	owned_gifts_t* owned_gifts_2 = owned_gifts_parseFromJSON(jsonowned_gifts_1);
	cJSON* jsonowned_gifts_2 = owned_gifts_convertToJSON(owned_gifts_2);
	printf("repeating owned_gifts:\n%s\n", cJSON_Print(jsonowned_gifts_2));
}

int main() {
  test_owned_gifts(1);
  test_owned_gifts(0);

  printf("Hello world \n");
  return 0;
}

#endif // owned_gifts_MAIN
#endif // owned_gifts_TEST
