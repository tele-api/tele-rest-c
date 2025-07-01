#ifndef user_chat_boosts_TEST
#define user_chat_boosts_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define user_chat_boosts_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/user_chat_boosts.h"
user_chat_boosts_t* instantiate_user_chat_boosts(int include_optional);



user_chat_boosts_t* instantiate_user_chat_boosts(int include_optional) {
  user_chat_boosts_t* user_chat_boosts = NULL;
  if (include_optional) {
    user_chat_boosts = user_chat_boosts_create(
      list_createList()
    );
  } else {
    user_chat_boosts = user_chat_boosts_create(
      list_createList()
    );
  }

  return user_chat_boosts;
}


#ifdef user_chat_boosts_MAIN

void test_user_chat_boosts(int include_optional) {
    user_chat_boosts_t* user_chat_boosts_1 = instantiate_user_chat_boosts(include_optional);

	cJSON* jsonuser_chat_boosts_1 = user_chat_boosts_convertToJSON(user_chat_boosts_1);
	printf("user_chat_boosts :\n%s\n", cJSON_Print(jsonuser_chat_boosts_1));
	user_chat_boosts_t* user_chat_boosts_2 = user_chat_boosts_parseFromJSON(jsonuser_chat_boosts_1);
	cJSON* jsonuser_chat_boosts_2 = user_chat_boosts_convertToJSON(user_chat_boosts_2);
	printf("repeating user_chat_boosts:\n%s\n", cJSON_Print(jsonuser_chat_boosts_2));
}

int main() {
  test_user_chat_boosts(1);
  test_user_chat_boosts(0);

  printf("Hello world \n");
  return 0;
}

#endif // user_chat_boosts_MAIN
#endif // user_chat_boosts_TEST
