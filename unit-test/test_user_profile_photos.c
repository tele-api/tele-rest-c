#ifndef user_profile_photos_TEST
#define user_profile_photos_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define user_profile_photos_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/user_profile_photos.h"
user_profile_photos_t* instantiate_user_profile_photos(int include_optional);



user_profile_photos_t* instantiate_user_profile_photos(int include_optional) {
  user_profile_photos_t* user_profile_photos = NULL;
  if (include_optional) {
    user_profile_photos = user_profile_photos_create(
      56,
      list_createList()
    );
  } else {
    user_profile_photos = user_profile_photos_create(
      56,
      list_createList()
    );
  }

  return user_profile_photos;
}


#ifdef user_profile_photos_MAIN

void test_user_profile_photos(int include_optional) {
    user_profile_photos_t* user_profile_photos_1 = instantiate_user_profile_photos(include_optional);

	cJSON* jsonuser_profile_photos_1 = user_profile_photos_convertToJSON(user_profile_photos_1);
	printf("user_profile_photos :\n%s\n", cJSON_Print(jsonuser_profile_photos_1));
	user_profile_photos_t* user_profile_photos_2 = user_profile_photos_parseFromJSON(jsonuser_profile_photos_1);
	cJSON* jsonuser_profile_photos_2 = user_profile_photos_convertToJSON(user_profile_photos_2);
	printf("repeating user_profile_photos:\n%s\n", cJSON_Print(jsonuser_profile_photos_2));
}

int main() {
  test_user_profile_photos(1);
  test_user_profile_photos(0);

  printf("Hello world \n");
  return 0;
}

#endif // user_profile_photos_MAIN
#endif // user_profile_photos_TEST
