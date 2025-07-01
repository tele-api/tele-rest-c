#ifndef shared_user_TEST
#define shared_user_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define shared_user_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/shared_user.h"
shared_user_t* instantiate_shared_user(int include_optional);



shared_user_t* instantiate_shared_user(int include_optional) {
  shared_user_t* shared_user = NULL;
  if (include_optional) {
    shared_user = shared_user_create(
      56,
      "0",
      "0",
      "0",
      list_createList()
    );
  } else {
    shared_user = shared_user_create(
      56,
      "0",
      "0",
      "0",
      list_createList()
    );
  }

  return shared_user;
}


#ifdef shared_user_MAIN

void test_shared_user(int include_optional) {
    shared_user_t* shared_user_1 = instantiate_shared_user(include_optional);

	cJSON* jsonshared_user_1 = shared_user_convertToJSON(shared_user_1);
	printf("shared_user :\n%s\n", cJSON_Print(jsonshared_user_1));
	shared_user_t* shared_user_2 = shared_user_parseFromJSON(jsonshared_user_1);
	cJSON* jsonshared_user_2 = shared_user_convertToJSON(shared_user_2);
	printf("repeating shared_user:\n%s\n", cJSON_Print(jsonshared_user_2));
}

int main() {
  test_shared_user(1);
  test_shared_user(0);

  printf("Hello world \n");
  return 0;
}

#endif // shared_user_MAIN
#endif // shared_user_TEST
