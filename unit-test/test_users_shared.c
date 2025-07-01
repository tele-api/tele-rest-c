#ifndef users_shared_TEST
#define users_shared_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define users_shared_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/users_shared.h"
users_shared_t* instantiate_users_shared(int include_optional);



users_shared_t* instantiate_users_shared(int include_optional) {
  users_shared_t* users_shared = NULL;
  if (include_optional) {
    users_shared = users_shared_create(
      56,
      list_createList()
    );
  } else {
    users_shared = users_shared_create(
      56,
      list_createList()
    );
  }

  return users_shared;
}


#ifdef users_shared_MAIN

void test_users_shared(int include_optional) {
    users_shared_t* users_shared_1 = instantiate_users_shared(include_optional);

	cJSON* jsonusers_shared_1 = users_shared_convertToJSON(users_shared_1);
	printf("users_shared :\n%s\n", cJSON_Print(jsonusers_shared_1));
	users_shared_t* users_shared_2 = users_shared_parseFromJSON(jsonusers_shared_1);
	cJSON* jsonusers_shared_2 = users_shared_convertToJSON(users_shared_2);
	printf("repeating users_shared:\n%s\n", cJSON_Print(jsonusers_shared_2));
}

int main() {
  test_users_shared(1);
  test_users_shared(0);

  printf("Hello world \n");
  return 0;
}

#endif // users_shared_MAIN
#endif // users_shared_TEST
