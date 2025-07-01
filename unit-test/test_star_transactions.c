#ifndef star_transactions_TEST
#define star_transactions_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define star_transactions_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/star_transactions.h"
star_transactions_t* instantiate_star_transactions(int include_optional);



star_transactions_t* instantiate_star_transactions(int include_optional) {
  star_transactions_t* star_transactions = NULL;
  if (include_optional) {
    star_transactions = star_transactions_create(
      list_createList()
    );
  } else {
    star_transactions = star_transactions_create(
      list_createList()
    );
  }

  return star_transactions;
}


#ifdef star_transactions_MAIN

void test_star_transactions(int include_optional) {
    star_transactions_t* star_transactions_1 = instantiate_star_transactions(include_optional);

	cJSON* jsonstar_transactions_1 = star_transactions_convertToJSON(star_transactions_1);
	printf("star_transactions :\n%s\n", cJSON_Print(jsonstar_transactions_1));
	star_transactions_t* star_transactions_2 = star_transactions_parseFromJSON(jsonstar_transactions_1);
	cJSON* jsonstar_transactions_2 = star_transactions_convertToJSON(star_transactions_2);
	printf("repeating star_transactions:\n%s\n", cJSON_Print(jsonstar_transactions_2));
}

int main() {
  test_star_transactions(1);
  test_star_transactions(0);

  printf("Hello world \n");
  return 0;
}

#endif // star_transactions_MAIN
#endif // star_transactions_TEST
