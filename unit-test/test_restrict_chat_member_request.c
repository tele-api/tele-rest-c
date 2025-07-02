#ifndef restrict_chat_member_request_TEST
#define restrict_chat_member_request_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define restrict_chat_member_request_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/restrict_chat_member_request.h"
restrict_chat_member_request_t* instantiate_restrict_chat_member_request(int include_optional);

#include "test_bot_command_scope_chat_chat_id.c"
#include "test_chat_permissions.c"


restrict_chat_member_request_t* instantiate_restrict_chat_member_request(int include_optional) {
  restrict_chat_member_request_t* restrict_chat_member_request = NULL;
  if (include_optional) {
    restrict_chat_member_request = restrict_chat_member_request_create(
      null,
      56,
       // false, not to have infinite recursion
      instantiate_chat_permissions(0),
      1,
      56
    );
  } else {
    restrict_chat_member_request = restrict_chat_member_request_create(
      null,
      56,
      NULL,
      1,
      56
    );
  }

  return restrict_chat_member_request;
}


#ifdef restrict_chat_member_request_MAIN

void test_restrict_chat_member_request(int include_optional) {
    restrict_chat_member_request_t* restrict_chat_member_request_1 = instantiate_restrict_chat_member_request(include_optional);

	cJSON* jsonrestrict_chat_member_request_1 = restrict_chat_member_request_convertToJSON(restrict_chat_member_request_1);
	printf("restrict_chat_member_request :\n%s\n", cJSON_Print(jsonrestrict_chat_member_request_1));
	restrict_chat_member_request_t* restrict_chat_member_request_2 = restrict_chat_member_request_parseFromJSON(jsonrestrict_chat_member_request_1);
	cJSON* jsonrestrict_chat_member_request_2 = restrict_chat_member_request_convertToJSON(restrict_chat_member_request_2);
	printf("repeating restrict_chat_member_request:\n%s\n", cJSON_Print(jsonrestrict_chat_member_request_2));
}

int main() {
  test_restrict_chat_member_request(1);
  test_restrict_chat_member_request(0);

  printf("Hello world \n");
  return 0;
}

#endif // restrict_chat_member_request_MAIN
#endif // restrict_chat_member_request_TEST
