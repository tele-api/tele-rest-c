#ifndef unique_gift_backdrop_TEST
#define unique_gift_backdrop_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define unique_gift_backdrop_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/unique_gift_backdrop.h"
unique_gift_backdrop_t* instantiate_unique_gift_backdrop(int include_optional);

#include "test_unique_gift_backdrop_colors.c"


unique_gift_backdrop_t* instantiate_unique_gift_backdrop(int include_optional) {
  unique_gift_backdrop_t* unique_gift_backdrop = NULL;
  if (include_optional) {
    unique_gift_backdrop = unique_gift_backdrop_create(
      "0",
       // false, not to have infinite recursion
      instantiate_unique_gift_backdrop_colors(0),
      56
    );
  } else {
    unique_gift_backdrop = unique_gift_backdrop_create(
      "0",
      NULL,
      56
    );
  }

  return unique_gift_backdrop;
}


#ifdef unique_gift_backdrop_MAIN

void test_unique_gift_backdrop(int include_optional) {
    unique_gift_backdrop_t* unique_gift_backdrop_1 = instantiate_unique_gift_backdrop(include_optional);

	cJSON* jsonunique_gift_backdrop_1 = unique_gift_backdrop_convertToJSON(unique_gift_backdrop_1);
	printf("unique_gift_backdrop :\n%s\n", cJSON_Print(jsonunique_gift_backdrop_1));
	unique_gift_backdrop_t* unique_gift_backdrop_2 = unique_gift_backdrop_parseFromJSON(jsonunique_gift_backdrop_1);
	cJSON* jsonunique_gift_backdrop_2 = unique_gift_backdrop_convertToJSON(unique_gift_backdrop_2);
	printf("repeating unique_gift_backdrop:\n%s\n", cJSON_Print(jsonunique_gift_backdrop_2));
}

int main() {
  test_unique_gift_backdrop(1);
  test_unique_gift_backdrop(0);

  printf("Hello world \n");
  return 0;
}

#endif // unique_gift_backdrop_MAIN
#endif // unique_gift_backdrop_TEST
