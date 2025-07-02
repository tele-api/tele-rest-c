#ifndef get_user_profile_photos_response_TEST
#define get_user_profile_photos_response_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define get_user_profile_photos_response_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/get_user_profile_photos_response.h"
get_user_profile_photos_response_t* instantiate_get_user_profile_photos_response(int include_optional);

#include "test_user_profile_photos.c"


get_user_profile_photos_response_t* instantiate_get_user_profile_photos_response(int include_optional) {
  get_user_profile_photos_response_t* get_user_profile_photos_response = NULL;
  if (include_optional) {
    get_user_profile_photos_response = get_user_profile_photos_response_create(
      1,
       // false, not to have infinite recursion
      instantiate_user_profile_photos(0)
    );
  } else {
    get_user_profile_photos_response = get_user_profile_photos_response_create(
      1,
      NULL
    );
  }

  return get_user_profile_photos_response;
}


#ifdef get_user_profile_photos_response_MAIN

void test_get_user_profile_photos_response(int include_optional) {
    get_user_profile_photos_response_t* get_user_profile_photos_response_1 = instantiate_get_user_profile_photos_response(include_optional);

	cJSON* jsonget_user_profile_photos_response_1 = get_user_profile_photos_response_convertToJSON(get_user_profile_photos_response_1);
	printf("get_user_profile_photos_response :\n%s\n", cJSON_Print(jsonget_user_profile_photos_response_1));
	get_user_profile_photos_response_t* get_user_profile_photos_response_2 = get_user_profile_photos_response_parseFromJSON(jsonget_user_profile_photos_response_1);
	cJSON* jsonget_user_profile_photos_response_2 = get_user_profile_photos_response_convertToJSON(get_user_profile_photos_response_2);
	printf("repeating get_user_profile_photos_response:\n%s\n", cJSON_Print(jsonget_user_profile_photos_response_2));
}

int main() {
  test_get_user_profile_photos_response(1);
  test_get_user_profile_photos_response(0);

  printf("Hello world \n");
  return 0;
}

#endif // get_user_profile_photos_response_MAIN
#endif // get_user_profile_photos_response_TEST
