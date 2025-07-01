#ifndef venue_TEST
#define venue_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define venue_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/venue.h"
venue_t* instantiate_venue(int include_optional);

#include "test_location.c"


venue_t* instantiate_venue(int include_optional) {
  venue_t* venue = NULL;
  if (include_optional) {
    venue = venue_create(
       // false, not to have infinite recursion
      instantiate_location(0),
      "0",
      "0",
      "0",
      "0",
      "0",
      "0"
    );
  } else {
    venue = venue_create(
      NULL,
      "0",
      "0",
      "0",
      "0",
      "0",
      "0"
    );
  }

  return venue;
}


#ifdef venue_MAIN

void test_venue(int include_optional) {
    venue_t* venue_1 = instantiate_venue(include_optional);

	cJSON* jsonvenue_1 = venue_convertToJSON(venue_1);
	printf("venue :\n%s\n", cJSON_Print(jsonvenue_1));
	venue_t* venue_2 = venue_parseFromJSON(jsonvenue_1);
	cJSON* jsonvenue_2 = venue_convertToJSON(venue_2);
	printf("repeating venue:\n%s\n", cJSON_Print(jsonvenue_2));
}

int main() {
  test_venue(1);
  test_venue(0);

  printf("Hello world \n");
  return 0;
}

#endif // venue_MAIN
#endif // venue_TEST
