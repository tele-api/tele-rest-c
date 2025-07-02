#ifndef remove_business_account_profile_photo_response_TEST
#define remove_business_account_profile_photo_response_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define remove_business_account_profile_photo_response_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/remove_business_account_profile_photo_response.h"
remove_business_account_profile_photo_response_t* instantiate_remove_business_account_profile_photo_response(int include_optional);



remove_business_account_profile_photo_response_t* instantiate_remove_business_account_profile_photo_response(int include_optional) {
  remove_business_account_profile_photo_response_t* remove_business_account_profile_photo_response = NULL;
  if (include_optional) {
    remove_business_account_profile_photo_response = remove_business_account_profile_photo_response_create(
      1,
      1
    );
  } else {
    remove_business_account_profile_photo_response = remove_business_account_profile_photo_response_create(
      1,
      1
    );
  }

  return remove_business_account_profile_photo_response;
}


#ifdef remove_business_account_profile_photo_response_MAIN

void test_remove_business_account_profile_photo_response(int include_optional) {
    remove_business_account_profile_photo_response_t* remove_business_account_profile_photo_response_1 = instantiate_remove_business_account_profile_photo_response(include_optional);

	cJSON* jsonremove_business_account_profile_photo_response_1 = remove_business_account_profile_photo_response_convertToJSON(remove_business_account_profile_photo_response_1);
	printf("remove_business_account_profile_photo_response :\n%s\n", cJSON_Print(jsonremove_business_account_profile_photo_response_1));
	remove_business_account_profile_photo_response_t* remove_business_account_profile_photo_response_2 = remove_business_account_profile_photo_response_parseFromJSON(jsonremove_business_account_profile_photo_response_1);
	cJSON* jsonremove_business_account_profile_photo_response_2 = remove_business_account_profile_photo_response_convertToJSON(remove_business_account_profile_photo_response_2);
	printf("repeating remove_business_account_profile_photo_response:\n%s\n", cJSON_Print(jsonremove_business_account_profile_photo_response_2));
}

int main() {
  test_remove_business_account_profile_photo_response(1);
  test_remove_business_account_profile_photo_response(0);

  printf("Hello world \n");
  return 0;
}

#endif // remove_business_account_profile_photo_response_MAIN
#endif // remove_business_account_profile_photo_response_TEST
