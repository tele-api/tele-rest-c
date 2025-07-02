#ifndef transfer_business_account_stars_request_TEST
#define transfer_business_account_stars_request_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define transfer_business_account_stars_request_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/transfer_business_account_stars_request.h"
transfer_business_account_stars_request_t* instantiate_transfer_business_account_stars_request(int include_optional);



transfer_business_account_stars_request_t* instantiate_transfer_business_account_stars_request(int include_optional) {
  transfer_business_account_stars_request_t* transfer_business_account_stars_request = NULL;
  if (include_optional) {
    transfer_business_account_stars_request = transfer_business_account_stars_request_create(
      "0",
      56
    );
  } else {
    transfer_business_account_stars_request = transfer_business_account_stars_request_create(
      "0",
      56
    );
  }

  return transfer_business_account_stars_request;
}


#ifdef transfer_business_account_stars_request_MAIN

void test_transfer_business_account_stars_request(int include_optional) {
    transfer_business_account_stars_request_t* transfer_business_account_stars_request_1 = instantiate_transfer_business_account_stars_request(include_optional);

	cJSON* jsontransfer_business_account_stars_request_1 = transfer_business_account_stars_request_convertToJSON(transfer_business_account_stars_request_1);
	printf("transfer_business_account_stars_request :\n%s\n", cJSON_Print(jsontransfer_business_account_stars_request_1));
	transfer_business_account_stars_request_t* transfer_business_account_stars_request_2 = transfer_business_account_stars_request_parseFromJSON(jsontransfer_business_account_stars_request_1);
	cJSON* jsontransfer_business_account_stars_request_2 = transfer_business_account_stars_request_convertToJSON(transfer_business_account_stars_request_2);
	printf("repeating transfer_business_account_stars_request:\n%s\n", cJSON_Print(jsontransfer_business_account_stars_request_2));
}

int main() {
  test_transfer_business_account_stars_request(1);
  test_transfer_business_account_stars_request(0);

  printf("Hello world \n");
  return 0;
}

#endif // transfer_business_account_stars_request_MAIN
#endif // transfer_business_account_stars_request_TEST
