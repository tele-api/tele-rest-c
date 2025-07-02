#ifndef get_star_transactions_response_TEST
#define get_star_transactions_response_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define get_star_transactions_response_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/get_star_transactions_response.h"
get_star_transactions_response_t* instantiate_get_star_transactions_response(int include_optional);

#include "test_star_transactions.c"


get_star_transactions_response_t* instantiate_get_star_transactions_response(int include_optional) {
  get_star_transactions_response_t* get_star_transactions_response = NULL;
  if (include_optional) {
    get_star_transactions_response = get_star_transactions_response_create(
      1,
       // false, not to have infinite recursion
      instantiate_star_transactions(0)
    );
  } else {
    get_star_transactions_response = get_star_transactions_response_create(
      1,
      NULL
    );
  }

  return get_star_transactions_response;
}


#ifdef get_star_transactions_response_MAIN

void test_get_star_transactions_response(int include_optional) {
    get_star_transactions_response_t* get_star_transactions_response_1 = instantiate_get_star_transactions_response(include_optional);

	cJSON* jsonget_star_transactions_response_1 = get_star_transactions_response_convertToJSON(get_star_transactions_response_1);
	printf("get_star_transactions_response :\n%s\n", cJSON_Print(jsonget_star_transactions_response_1));
	get_star_transactions_response_t* get_star_transactions_response_2 = get_star_transactions_response_parseFromJSON(jsonget_star_transactions_response_1);
	cJSON* jsonget_star_transactions_response_2 = get_star_transactions_response_convertToJSON(get_star_transactions_response_2);
	printf("repeating get_star_transactions_response:\n%s\n", cJSON_Print(jsonget_star_transactions_response_2));
}

int main() {
  test_get_star_transactions_response(1);
  test_get_star_transactions_response(0);

  printf("Hello world \n");
  return 0;
}

#endif // get_star_transactions_response_MAIN
#endif // get_star_transactions_response_TEST
