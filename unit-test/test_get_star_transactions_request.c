#ifndef get_star_transactions_request_TEST
#define get_star_transactions_request_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define get_star_transactions_request_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/get_star_transactions_request.h"
get_star_transactions_request_t* instantiate_get_star_transactions_request(int include_optional);



get_star_transactions_request_t* instantiate_get_star_transactions_request(int include_optional) {
  get_star_transactions_request_t* get_star_transactions_request = NULL;
  if (include_optional) {
    get_star_transactions_request = get_star_transactions_request_create(
      56,
      1
    );
  } else {
    get_star_transactions_request = get_star_transactions_request_create(
      56,
      1
    );
  }

  return get_star_transactions_request;
}


#ifdef get_star_transactions_request_MAIN

void test_get_star_transactions_request(int include_optional) {
    get_star_transactions_request_t* get_star_transactions_request_1 = instantiate_get_star_transactions_request(include_optional);

	cJSON* jsonget_star_transactions_request_1 = get_star_transactions_request_convertToJSON(get_star_transactions_request_1);
	printf("get_star_transactions_request :\n%s\n", cJSON_Print(jsonget_star_transactions_request_1));
	get_star_transactions_request_t* get_star_transactions_request_2 = get_star_transactions_request_parseFromJSON(jsonget_star_transactions_request_1);
	cJSON* jsonget_star_transactions_request_2 = get_star_transactions_request_convertToJSON(get_star_transactions_request_2);
	printf("repeating get_star_transactions_request:\n%s\n", cJSON_Print(jsonget_star_transactions_request_2));
}

int main() {
  test_get_star_transactions_request(1);
  test_get_star_transactions_request(0);

  printf("Hello world \n");
  return 0;
}

#endif // get_star_transactions_request_MAIN
#endif // get_star_transactions_request_TEST
