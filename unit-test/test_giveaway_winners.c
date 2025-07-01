#ifndef giveaway_winners_TEST
#define giveaway_winners_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define giveaway_winners_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/giveaway_winners.h"
giveaway_winners_t* instantiate_giveaway_winners(int include_optional);

#include "test_chat.c"


giveaway_winners_t* instantiate_giveaway_winners(int include_optional) {
  giveaway_winners_t* giveaway_winners = NULL;
  if (include_optional) {
    giveaway_winners = giveaway_winners_create(
       // false, not to have infinite recursion
      instantiate_chat(0),
      56,
      56,
      56,
      list_createList(),
      56,
      56,
      56,
      56,
      1,
      1,
      "0"
    );
  } else {
    giveaway_winners = giveaway_winners_create(
      NULL,
      56,
      56,
      56,
      list_createList(),
      56,
      56,
      56,
      56,
      1,
      1,
      "0"
    );
  }

  return giveaway_winners;
}


#ifdef giveaway_winners_MAIN

void test_giveaway_winners(int include_optional) {
    giveaway_winners_t* giveaway_winners_1 = instantiate_giveaway_winners(include_optional);

	cJSON* jsongiveaway_winners_1 = giveaway_winners_convertToJSON(giveaway_winners_1);
	printf("giveaway_winners :\n%s\n", cJSON_Print(jsongiveaway_winners_1));
	giveaway_winners_t* giveaway_winners_2 = giveaway_winners_parseFromJSON(jsongiveaway_winners_1);
	cJSON* jsongiveaway_winners_2 = giveaway_winners_convertToJSON(giveaway_winners_2);
	printf("repeating giveaway_winners:\n%s\n", cJSON_Print(jsongiveaway_winners_2));
}

int main() {
  test_giveaway_winners(1);
  test_giveaway_winners(0);

  printf("Hello world \n");
  return 0;
}

#endif // giveaway_winners_MAIN
#endif // giveaway_winners_TEST
