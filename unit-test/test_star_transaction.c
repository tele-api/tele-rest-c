#ifndef star_transaction_TEST
#define star_transaction_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define star_transaction_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/star_transaction.h"
star_transaction_t* instantiate_star_transaction(int include_optional);

#include "test_transaction_partner.c"
#include "test_transaction_partner.c"


star_transaction_t* instantiate_star_transaction(int include_optional) {
  star_transaction_t* star_transaction = NULL;
  if (include_optional) {
    star_transaction = star_transaction_create(
      "0",
      56,
      56,
      56,
      null,
      null
    );
  } else {
    star_transaction = star_transaction_create(
      "0",
      56,
      56,
      56,
      null,
      null
    );
  }

  return star_transaction;
}


#ifdef star_transaction_MAIN

void test_star_transaction(int include_optional) {
    star_transaction_t* star_transaction_1 = instantiate_star_transaction(include_optional);

	cJSON* jsonstar_transaction_1 = star_transaction_convertToJSON(star_transaction_1);
	printf("star_transaction :\n%s\n", cJSON_Print(jsonstar_transaction_1));
	star_transaction_t* star_transaction_2 = star_transaction_parseFromJSON(jsonstar_transaction_1);
	cJSON* jsonstar_transaction_2 = star_transaction_convertToJSON(star_transaction_2);
	printf("repeating star_transaction:\n%s\n", cJSON_Print(jsonstar_transaction_2));
}

int main() {
  test_star_transaction(1);
  test_star_transaction(0);

  printf("Hello world \n");
  return 0;
}

#endif // star_transaction_MAIN
#endif // star_transaction_TEST
