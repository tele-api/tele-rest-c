#ifndef remove_user_verification_request_TEST
#define remove_user_verification_request_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define remove_user_verification_request_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/remove_user_verification_request.h"
remove_user_verification_request_t* instantiate_remove_user_verification_request(int include_optional);



remove_user_verification_request_t* instantiate_remove_user_verification_request(int include_optional) {
  remove_user_verification_request_t* remove_user_verification_request = NULL;
  if (include_optional) {
    remove_user_verification_request = remove_user_verification_request_create(
      56
    );
  } else {
    remove_user_verification_request = remove_user_verification_request_create(
      56
    );
  }

  return remove_user_verification_request;
}


#ifdef remove_user_verification_request_MAIN

void test_remove_user_verification_request(int include_optional) {
    remove_user_verification_request_t* remove_user_verification_request_1 = instantiate_remove_user_verification_request(include_optional);

	cJSON* jsonremove_user_verification_request_1 = remove_user_verification_request_convertToJSON(remove_user_verification_request_1);
	printf("remove_user_verification_request :\n%s\n", cJSON_Print(jsonremove_user_verification_request_1));
	remove_user_verification_request_t* remove_user_verification_request_2 = remove_user_verification_request_parseFromJSON(jsonremove_user_verification_request_1);
	cJSON* jsonremove_user_verification_request_2 = remove_user_verification_request_convertToJSON(remove_user_verification_request_2);
	printf("repeating remove_user_verification_request:\n%s\n", cJSON_Print(jsonremove_user_verification_request_2));
}

int main() {
  test_remove_user_verification_request(1);
  test_remove_user_verification_request(0);

  printf("Hello world \n");
  return 0;
}

#endif // remove_user_verification_request_MAIN
#endif // remove_user_verification_request_TEST
