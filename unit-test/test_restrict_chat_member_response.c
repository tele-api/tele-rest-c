#ifndef restrict_chat_member_response_TEST
#define restrict_chat_member_response_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define restrict_chat_member_response_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/restrict_chat_member_response.h"
restrict_chat_member_response_t* instantiate_restrict_chat_member_response(int include_optional);



restrict_chat_member_response_t* instantiate_restrict_chat_member_response(int include_optional) {
  restrict_chat_member_response_t* restrict_chat_member_response = NULL;
  if (include_optional) {
    restrict_chat_member_response = restrict_chat_member_response_create(
      1,
      1
    );
  } else {
    restrict_chat_member_response = restrict_chat_member_response_create(
      1,
      1
    );
  }

  return restrict_chat_member_response;
}


#ifdef restrict_chat_member_response_MAIN

void test_restrict_chat_member_response(int include_optional) {
    restrict_chat_member_response_t* restrict_chat_member_response_1 = instantiate_restrict_chat_member_response(include_optional);

	cJSON* jsonrestrict_chat_member_response_1 = restrict_chat_member_response_convertToJSON(restrict_chat_member_response_1);
	printf("restrict_chat_member_response :\n%s\n", cJSON_Print(jsonrestrict_chat_member_response_1));
	restrict_chat_member_response_t* restrict_chat_member_response_2 = restrict_chat_member_response_parseFromJSON(jsonrestrict_chat_member_response_1);
	cJSON* jsonrestrict_chat_member_response_2 = restrict_chat_member_response_convertToJSON(restrict_chat_member_response_2);
	printf("repeating restrict_chat_member_response:\n%s\n", cJSON_Print(jsonrestrict_chat_member_response_2));
}

int main() {
  test_restrict_chat_member_response(1);
  test_restrict_chat_member_response(0);

  printf("Hello world \n");
  return 0;
}

#endif // restrict_chat_member_response_MAIN
#endif // restrict_chat_member_response_TEST
