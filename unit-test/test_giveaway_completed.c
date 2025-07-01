#ifndef giveaway_completed_TEST
#define giveaway_completed_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define giveaway_completed_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/giveaway_completed.h"
giveaway_completed_t* instantiate_giveaway_completed(int include_optional);

#include "test_message.c"


giveaway_completed_t* instantiate_giveaway_completed(int include_optional) {
  giveaway_completed_t* giveaway_completed = NULL;
  if (include_optional) {
    giveaway_completed = giveaway_completed_create(
      56,
      56,
       // false, not to have infinite recursion
      instantiate_message(0),
      1
    );
  } else {
    giveaway_completed = giveaway_completed_create(
      56,
      56,
      NULL,
      1
    );
  }

  return giveaway_completed;
}


#ifdef giveaway_completed_MAIN

void test_giveaway_completed(int include_optional) {
    giveaway_completed_t* giveaway_completed_1 = instantiate_giveaway_completed(include_optional);

	cJSON* jsongiveaway_completed_1 = giveaway_completed_convertToJSON(giveaway_completed_1);
	printf("giveaway_completed :\n%s\n", cJSON_Print(jsongiveaway_completed_1));
	giveaway_completed_t* giveaway_completed_2 = giveaway_completed_parseFromJSON(jsongiveaway_completed_1);
	cJSON* jsongiveaway_completed_2 = giveaway_completed_convertToJSON(giveaway_completed_2);
	printf("repeating giveaway_completed:\n%s\n", cJSON_Print(jsongiveaway_completed_2));
}

int main() {
  test_giveaway_completed(1);
  test_giveaway_completed(0);

  printf("Hello world \n");
  return 0;
}

#endif // giveaway_completed_MAIN
#endif // giveaway_completed_TEST
