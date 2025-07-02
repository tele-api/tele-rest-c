#ifndef transfer_gift_response_TEST
#define transfer_gift_response_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define transfer_gift_response_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/transfer_gift_response.h"
transfer_gift_response_t* instantiate_transfer_gift_response(int include_optional);



transfer_gift_response_t* instantiate_transfer_gift_response(int include_optional) {
  transfer_gift_response_t* transfer_gift_response = NULL;
  if (include_optional) {
    transfer_gift_response = transfer_gift_response_create(
      1,
      1
    );
  } else {
    transfer_gift_response = transfer_gift_response_create(
      1,
      1
    );
  }

  return transfer_gift_response;
}


#ifdef transfer_gift_response_MAIN

void test_transfer_gift_response(int include_optional) {
    transfer_gift_response_t* transfer_gift_response_1 = instantiate_transfer_gift_response(include_optional);

	cJSON* jsontransfer_gift_response_1 = transfer_gift_response_convertToJSON(transfer_gift_response_1);
	printf("transfer_gift_response :\n%s\n", cJSON_Print(jsontransfer_gift_response_1));
	transfer_gift_response_t* transfer_gift_response_2 = transfer_gift_response_parseFromJSON(jsontransfer_gift_response_1);
	cJSON* jsontransfer_gift_response_2 = transfer_gift_response_convertToJSON(transfer_gift_response_2);
	printf("repeating transfer_gift_response:\n%s\n", cJSON_Print(jsontransfer_gift_response_2));
}

int main() {
  test_transfer_gift_response(1);
  test_transfer_gift_response(0);

  printf("Hello world \n");
  return 0;
}

#endif // transfer_gift_response_MAIN
#endif // transfer_gift_response_TEST
