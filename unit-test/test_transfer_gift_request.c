#ifndef transfer_gift_request_TEST
#define transfer_gift_request_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define transfer_gift_request_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/transfer_gift_request.h"
transfer_gift_request_t* instantiate_transfer_gift_request(int include_optional);



transfer_gift_request_t* instantiate_transfer_gift_request(int include_optional) {
  transfer_gift_request_t* transfer_gift_request = NULL;
  if (include_optional) {
    transfer_gift_request = transfer_gift_request_create(
      "0",
      "0",
      56,
      56
    );
  } else {
    transfer_gift_request = transfer_gift_request_create(
      "0",
      "0",
      56,
      56
    );
  }

  return transfer_gift_request;
}


#ifdef transfer_gift_request_MAIN

void test_transfer_gift_request(int include_optional) {
    transfer_gift_request_t* transfer_gift_request_1 = instantiate_transfer_gift_request(include_optional);

	cJSON* jsontransfer_gift_request_1 = transfer_gift_request_convertToJSON(transfer_gift_request_1);
	printf("transfer_gift_request :\n%s\n", cJSON_Print(jsontransfer_gift_request_1));
	transfer_gift_request_t* transfer_gift_request_2 = transfer_gift_request_parseFromJSON(jsontransfer_gift_request_1);
	cJSON* jsontransfer_gift_request_2 = transfer_gift_request_convertToJSON(transfer_gift_request_2);
	printf("repeating transfer_gift_request:\n%s\n", cJSON_Print(jsontransfer_gift_request_2));
}

int main() {
  test_transfer_gift_request(1);
  test_transfer_gift_request(0);

  printf("Hello world \n");
  return 0;
}

#endif // transfer_gift_request_MAIN
#endif // transfer_gift_request_TEST
