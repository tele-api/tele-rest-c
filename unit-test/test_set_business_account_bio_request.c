#ifndef set_business_account_bio_request_TEST
#define set_business_account_bio_request_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define set_business_account_bio_request_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/set_business_account_bio_request.h"
set_business_account_bio_request_t* instantiate_set_business_account_bio_request(int include_optional);



set_business_account_bio_request_t* instantiate_set_business_account_bio_request(int include_optional) {
  set_business_account_bio_request_t* set_business_account_bio_request = NULL;
  if (include_optional) {
    set_business_account_bio_request = set_business_account_bio_request_create(
      "0",
      "0"
    );
  } else {
    set_business_account_bio_request = set_business_account_bio_request_create(
      "0",
      "0"
    );
  }

  return set_business_account_bio_request;
}


#ifdef set_business_account_bio_request_MAIN

void test_set_business_account_bio_request(int include_optional) {
    set_business_account_bio_request_t* set_business_account_bio_request_1 = instantiate_set_business_account_bio_request(include_optional);

	cJSON* jsonset_business_account_bio_request_1 = set_business_account_bio_request_convertToJSON(set_business_account_bio_request_1);
	printf("set_business_account_bio_request :\n%s\n", cJSON_Print(jsonset_business_account_bio_request_1));
	set_business_account_bio_request_t* set_business_account_bio_request_2 = set_business_account_bio_request_parseFromJSON(jsonset_business_account_bio_request_1);
	cJSON* jsonset_business_account_bio_request_2 = set_business_account_bio_request_convertToJSON(set_business_account_bio_request_2);
	printf("repeating set_business_account_bio_request:\n%s\n", cJSON_Print(jsonset_business_account_bio_request_2));
}

int main() {
  test_set_business_account_bio_request(1);
  test_set_business_account_bio_request(0);

  printf("Hello world \n");
  return 0;
}

#endif // set_business_account_bio_request_MAIN
#endif // set_business_account_bio_request_TEST
