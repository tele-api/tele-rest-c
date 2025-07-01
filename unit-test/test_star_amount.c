#ifndef star_amount_TEST
#define star_amount_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define star_amount_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/star_amount.h"
star_amount_t* instantiate_star_amount(int include_optional);



star_amount_t* instantiate_star_amount(int include_optional) {
  star_amount_t* star_amount = NULL;
  if (include_optional) {
    star_amount = star_amount_create(
      56,
      56
    );
  } else {
    star_amount = star_amount_create(
      56,
      56
    );
  }

  return star_amount;
}


#ifdef star_amount_MAIN

void test_star_amount(int include_optional) {
    star_amount_t* star_amount_1 = instantiate_star_amount(include_optional);

	cJSON* jsonstar_amount_1 = star_amount_convertToJSON(star_amount_1);
	printf("star_amount :\n%s\n", cJSON_Print(jsonstar_amount_1));
	star_amount_t* star_amount_2 = star_amount_parseFromJSON(jsonstar_amount_1);
	cJSON* jsonstar_amount_2 = star_amount_convertToJSON(star_amount_2);
	printf("repeating star_amount:\n%s\n", cJSON_Print(jsonstar_amount_2));
}

int main() {
  test_star_amount(1);
  test_star_amount(0);

  printf("Hello world \n");
  return 0;
}

#endif // star_amount_MAIN
#endif // star_amount_TEST
