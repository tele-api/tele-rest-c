#ifndef get_user_profile_photos_request_TEST
#define get_user_profile_photos_request_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define get_user_profile_photos_request_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/get_user_profile_photos_request.h"
get_user_profile_photos_request_t* instantiate_get_user_profile_photos_request(int include_optional);



get_user_profile_photos_request_t* instantiate_get_user_profile_photos_request(int include_optional) {
  get_user_profile_photos_request_t* get_user_profile_photos_request = NULL;
  if (include_optional) {
    get_user_profile_photos_request = get_user_profile_photos_request_create(
      56,
      56,
      1
    );
  } else {
    get_user_profile_photos_request = get_user_profile_photos_request_create(
      56,
      56,
      1
    );
  }

  return get_user_profile_photos_request;
}


#ifdef get_user_profile_photos_request_MAIN

void test_get_user_profile_photos_request(int include_optional) {
    get_user_profile_photos_request_t* get_user_profile_photos_request_1 = instantiate_get_user_profile_photos_request(include_optional);

	cJSON* jsonget_user_profile_photos_request_1 = get_user_profile_photos_request_convertToJSON(get_user_profile_photos_request_1);
	printf("get_user_profile_photos_request :\n%s\n", cJSON_Print(jsonget_user_profile_photos_request_1));
	get_user_profile_photos_request_t* get_user_profile_photos_request_2 = get_user_profile_photos_request_parseFromJSON(jsonget_user_profile_photos_request_1);
	cJSON* jsonget_user_profile_photos_request_2 = get_user_profile_photos_request_convertToJSON(get_user_profile_photos_request_2);
	printf("repeating get_user_profile_photos_request:\n%s\n", cJSON_Print(jsonget_user_profile_photos_request_2));
}

int main() {
  test_get_user_profile_photos_request(1);
  test_get_user_profile_photos_request(0);

  printf("Hello world \n");
  return 0;
}

#endif // get_user_profile_photos_request_MAIN
#endif // get_user_profile_photos_request_TEST
