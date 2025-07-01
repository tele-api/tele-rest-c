#ifndef business_messages_deleted_TEST
#define business_messages_deleted_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define business_messages_deleted_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/business_messages_deleted.h"
business_messages_deleted_t* instantiate_business_messages_deleted(int include_optional);

#include "test_chat.c"


business_messages_deleted_t* instantiate_business_messages_deleted(int include_optional) {
  business_messages_deleted_t* business_messages_deleted = NULL;
  if (include_optional) {
    business_messages_deleted = business_messages_deleted_create(
      "0",
       // false, not to have infinite recursion
      instantiate_chat(0),
      list_createList()
    );
  } else {
    business_messages_deleted = business_messages_deleted_create(
      "0",
      NULL,
      list_createList()
    );
  }

  return business_messages_deleted;
}


#ifdef business_messages_deleted_MAIN

void test_business_messages_deleted(int include_optional) {
    business_messages_deleted_t* business_messages_deleted_1 = instantiate_business_messages_deleted(include_optional);

	cJSON* jsonbusiness_messages_deleted_1 = business_messages_deleted_convertToJSON(business_messages_deleted_1);
	printf("business_messages_deleted :\n%s\n", cJSON_Print(jsonbusiness_messages_deleted_1));
	business_messages_deleted_t* business_messages_deleted_2 = business_messages_deleted_parseFromJSON(jsonbusiness_messages_deleted_1);
	cJSON* jsonbusiness_messages_deleted_2 = business_messages_deleted_convertToJSON(business_messages_deleted_2);
	printf("repeating business_messages_deleted:\n%s\n", cJSON_Print(jsonbusiness_messages_deleted_2));
}

int main() {
  test_business_messages_deleted(1);
  test_business_messages_deleted(0);

  printf("Hello world \n");
  return 0;
}

#endif // business_messages_deleted_MAIN
#endif // business_messages_deleted_TEST
