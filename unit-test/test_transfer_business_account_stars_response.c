#ifndef transfer_business_account_stars_response_TEST
#define transfer_business_account_stars_response_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define transfer_business_account_stars_response_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/transfer_business_account_stars_response.h"
transfer_business_account_stars_response_t* instantiate_transfer_business_account_stars_response(int include_optional);



transfer_business_account_stars_response_t* instantiate_transfer_business_account_stars_response(int include_optional) {
  transfer_business_account_stars_response_t* transfer_business_account_stars_response = NULL;
  if (include_optional) {
    transfer_business_account_stars_response = transfer_business_account_stars_response_create(
      1,
      1
    );
  } else {
    transfer_business_account_stars_response = transfer_business_account_stars_response_create(
      1,
      1
    );
  }

  return transfer_business_account_stars_response;
}


#ifdef transfer_business_account_stars_response_MAIN

void test_transfer_business_account_stars_response(int include_optional) {
    transfer_business_account_stars_response_t* transfer_business_account_stars_response_1 = instantiate_transfer_business_account_stars_response(include_optional);

	cJSON* jsontransfer_business_account_stars_response_1 = transfer_business_account_stars_response_convertToJSON(transfer_business_account_stars_response_1);
	printf("transfer_business_account_stars_response :\n%s\n", cJSON_Print(jsontransfer_business_account_stars_response_1));
	transfer_business_account_stars_response_t* transfer_business_account_stars_response_2 = transfer_business_account_stars_response_parseFromJSON(jsontransfer_business_account_stars_response_1);
	cJSON* jsontransfer_business_account_stars_response_2 = transfer_business_account_stars_response_convertToJSON(transfer_business_account_stars_response_2);
	printf("repeating transfer_business_account_stars_response:\n%s\n", cJSON_Print(jsontransfer_business_account_stars_response_2));
}

int main() {
  test_transfer_business_account_stars_response(1);
  test_transfer_business_account_stars_response(0);

  printf("Hello world \n");
  return 0;
}

#endif // transfer_business_account_stars_response_MAIN
#endif // transfer_business_account_stars_response_TEST
