#ifndef post_remove_business_account_profile_photo_request_TEST
#define post_remove_business_account_profile_photo_request_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define post_remove_business_account_profile_photo_request_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/post_remove_business_account_profile_photo_request.h"
post_remove_business_account_profile_photo_request_t* instantiate_post_remove_business_account_profile_photo_request(int include_optional);



post_remove_business_account_profile_photo_request_t* instantiate_post_remove_business_account_profile_photo_request(int include_optional) {
  post_remove_business_account_profile_photo_request_t* post_remove_business_account_profile_photo_request = NULL;
  if (include_optional) {
    post_remove_business_account_profile_photo_request = post_remove_business_account_profile_photo_request_create(
      "0",
      1
    );
  } else {
    post_remove_business_account_profile_photo_request = post_remove_business_account_profile_photo_request_create(
      "0",
      1
    );
  }

  return post_remove_business_account_profile_photo_request;
}


#ifdef post_remove_business_account_profile_photo_request_MAIN

void test_post_remove_business_account_profile_photo_request(int include_optional) {
    post_remove_business_account_profile_photo_request_t* post_remove_business_account_profile_photo_request_1 = instantiate_post_remove_business_account_profile_photo_request(include_optional);

	cJSON* jsonpost_remove_business_account_profile_photo_request_1 = post_remove_business_account_profile_photo_request_convertToJSON(post_remove_business_account_profile_photo_request_1);
	printf("post_remove_business_account_profile_photo_request :\n%s\n", cJSON_Print(jsonpost_remove_business_account_profile_photo_request_1));
	post_remove_business_account_profile_photo_request_t* post_remove_business_account_profile_photo_request_2 = post_remove_business_account_profile_photo_request_parseFromJSON(jsonpost_remove_business_account_profile_photo_request_1);
	cJSON* jsonpost_remove_business_account_profile_photo_request_2 = post_remove_business_account_profile_photo_request_convertToJSON(post_remove_business_account_profile_photo_request_2);
	printf("repeating post_remove_business_account_profile_photo_request:\n%s\n", cJSON_Print(jsonpost_remove_business_account_profile_photo_request_2));
}

int main() {
  test_post_remove_business_account_profile_photo_request(1);
  test_post_remove_business_account_profile_photo_request(0);

  printf("Hello world \n");
  return 0;
}

#endif // post_remove_business_account_profile_photo_request_MAIN
#endif // post_remove_business_account_profile_photo_request_TEST
