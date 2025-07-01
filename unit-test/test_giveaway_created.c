#ifndef giveaway_created_TEST
#define giveaway_created_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define giveaway_created_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/giveaway_created.h"
giveaway_created_t* instantiate_giveaway_created(int include_optional);



giveaway_created_t* instantiate_giveaway_created(int include_optional) {
  giveaway_created_t* giveaway_created = NULL;
  if (include_optional) {
    giveaway_created = giveaway_created_create(
      56
    );
  } else {
    giveaway_created = giveaway_created_create(
      56
    );
  }

  return giveaway_created;
}


#ifdef giveaway_created_MAIN

void test_giveaway_created(int include_optional) {
    giveaway_created_t* giveaway_created_1 = instantiate_giveaway_created(include_optional);

	cJSON* jsongiveaway_created_1 = giveaway_created_convertToJSON(giveaway_created_1);
	printf("giveaway_created :\n%s\n", cJSON_Print(jsongiveaway_created_1));
	giveaway_created_t* giveaway_created_2 = giveaway_created_parseFromJSON(jsongiveaway_created_1);
	cJSON* jsongiveaway_created_2 = giveaway_created_convertToJSON(giveaway_created_2);
	printf("repeating giveaway_created:\n%s\n", cJSON_Print(jsongiveaway_created_2));
}

int main() {
  test_giveaway_created(1);
  test_giveaway_created(0);

  printf("Hello world \n");
  return 0;
}

#endif // giveaway_created_MAIN
#endif // giveaway_created_TEST
