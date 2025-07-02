#ifndef verify_user_response_TEST
#define verify_user_response_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define verify_user_response_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/verify_user_response.h"
verify_user_response_t* instantiate_verify_user_response(int include_optional);



verify_user_response_t* instantiate_verify_user_response(int include_optional) {
  verify_user_response_t* verify_user_response = NULL;
  if (include_optional) {
    verify_user_response = verify_user_response_create(
      1,
      1
    );
  } else {
    verify_user_response = verify_user_response_create(
      1,
      1
    );
  }

  return verify_user_response;
}


#ifdef verify_user_response_MAIN

void test_verify_user_response(int include_optional) {
    verify_user_response_t* verify_user_response_1 = instantiate_verify_user_response(include_optional);

	cJSON* jsonverify_user_response_1 = verify_user_response_convertToJSON(verify_user_response_1);
	printf("verify_user_response :\n%s\n", cJSON_Print(jsonverify_user_response_1));
	verify_user_response_t* verify_user_response_2 = verify_user_response_parseFromJSON(jsonverify_user_response_1);
	cJSON* jsonverify_user_response_2 = verify_user_response_convertToJSON(verify_user_response_2);
	printf("repeating verify_user_response:\n%s\n", cJSON_Print(jsonverify_user_response_2));
}

int main() {
  test_verify_user_response(1);
  test_verify_user_response(0);

  printf("Hello world \n");
  return 0;
}

#endif // verify_user_response_MAIN
#endif // verify_user_response_TEST
