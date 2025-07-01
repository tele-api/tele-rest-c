#ifndef giveaway_TEST
#define giveaway_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define giveaway_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/giveaway.h"
giveaway_t* instantiate_giveaway(int include_optional);



giveaway_t* instantiate_giveaway(int include_optional) {
  giveaway_t* giveaway = NULL;
  if (include_optional) {
    giveaway = giveaway_create(
      list_createList(),
      56,
      56,
      1,
      1,
      "0",
      list_createList(),
      56,
      56
    );
  } else {
    giveaway = giveaway_create(
      list_createList(),
      56,
      56,
      1,
      1,
      "0",
      list_createList(),
      56,
      56
    );
  }

  return giveaway;
}


#ifdef giveaway_MAIN

void test_giveaway(int include_optional) {
    giveaway_t* giveaway_1 = instantiate_giveaway(include_optional);

	cJSON* jsongiveaway_1 = giveaway_convertToJSON(giveaway_1);
	printf("giveaway :\n%s\n", cJSON_Print(jsongiveaway_1));
	giveaway_t* giveaway_2 = giveaway_parseFromJSON(jsongiveaway_1);
	cJSON* jsongiveaway_2 = giveaway_convertToJSON(giveaway_2);
	printf("repeating giveaway:\n%s\n", cJSON_Print(jsongiveaway_2));
}

int main() {
  test_giveaway(1);
  test_giveaway(0);

  printf("Hello world \n");
  return 0;
}

#endif // giveaway_MAIN
#endif // giveaway_TEST
