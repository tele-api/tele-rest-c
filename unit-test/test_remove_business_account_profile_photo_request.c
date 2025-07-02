#ifndef remove_business_account_profile_photo_request_TEST
#define remove_business_account_profile_photo_request_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define remove_business_account_profile_photo_request_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/remove_business_account_profile_photo_request.h"
remove_business_account_profile_photo_request_t* instantiate_remove_business_account_profile_photo_request(int include_optional);



remove_business_account_profile_photo_request_t* instantiate_remove_business_account_profile_photo_request(int include_optional) {
  remove_business_account_profile_photo_request_t* remove_business_account_profile_photo_request = NULL;
  if (include_optional) {
    remove_business_account_profile_photo_request = remove_business_account_profile_photo_request_create(
      "0",
      1
    );
  } else {
    remove_business_account_profile_photo_request = remove_business_account_profile_photo_request_create(
      "0",
      1
    );
  }

  return remove_business_account_profile_photo_request;
}


#ifdef remove_business_account_profile_photo_request_MAIN

void test_remove_business_account_profile_photo_request(int include_optional) {
    remove_business_account_profile_photo_request_t* remove_business_account_profile_photo_request_1 = instantiate_remove_business_account_profile_photo_request(include_optional);

	cJSON* jsonremove_business_account_profile_photo_request_1 = remove_business_account_profile_photo_request_convertToJSON(remove_business_account_profile_photo_request_1);
	printf("remove_business_account_profile_photo_request :\n%s\n", cJSON_Print(jsonremove_business_account_profile_photo_request_1));
	remove_business_account_profile_photo_request_t* remove_business_account_profile_photo_request_2 = remove_business_account_profile_photo_request_parseFromJSON(jsonremove_business_account_profile_photo_request_1);
	cJSON* jsonremove_business_account_profile_photo_request_2 = remove_business_account_profile_photo_request_convertToJSON(remove_business_account_profile_photo_request_2);
	printf("repeating remove_business_account_profile_photo_request:\n%s\n", cJSON_Print(jsonremove_business_account_profile_photo_request_2));
}

int main() {
  test_remove_business_account_profile_photo_request(1);
  test_remove_business_account_profile_photo_request(0);

  printf("Hello world \n");
  return 0;
}

#endif // remove_business_account_profile_photo_request_MAIN
#endif // remove_business_account_profile_photo_request_TEST
