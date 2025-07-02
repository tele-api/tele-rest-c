#ifndef verify_user_request_TEST
#define verify_user_request_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define verify_user_request_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/verify_user_request.h"
verify_user_request_t* instantiate_verify_user_request(int include_optional);



verify_user_request_t* instantiate_verify_user_request(int include_optional) {
  verify_user_request_t* verify_user_request = NULL;
  if (include_optional) {
    verify_user_request = verify_user_request_create(
      56,
      "0"
    );
  } else {
    verify_user_request = verify_user_request_create(
      56,
      "0"
    );
  }

  return verify_user_request;
}


#ifdef verify_user_request_MAIN

void test_verify_user_request(int include_optional) {
    verify_user_request_t* verify_user_request_1 = instantiate_verify_user_request(include_optional);

	cJSON* jsonverify_user_request_1 = verify_user_request_convertToJSON(verify_user_request_1);
	printf("verify_user_request :\n%s\n", cJSON_Print(jsonverify_user_request_1));
	verify_user_request_t* verify_user_request_2 = verify_user_request_parseFromJSON(jsonverify_user_request_1);
	cJSON* jsonverify_user_request_2 = verify_user_request_convertToJSON(verify_user_request_2);
	printf("repeating verify_user_request:\n%s\n", cJSON_Print(jsonverify_user_request_2));
}

int main() {
  test_verify_user_request(1);
  test_verify_user_request(0);

  printf("Hello world \n");
  return 0;
}

#endif // verify_user_request_MAIN
#endif // verify_user_request_TEST
