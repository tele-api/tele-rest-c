#ifndef promote_chat_member_response_TEST
#define promote_chat_member_response_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define promote_chat_member_response_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/promote_chat_member_response.h"
promote_chat_member_response_t* instantiate_promote_chat_member_response(int include_optional);



promote_chat_member_response_t* instantiate_promote_chat_member_response(int include_optional) {
  promote_chat_member_response_t* promote_chat_member_response = NULL;
  if (include_optional) {
    promote_chat_member_response = promote_chat_member_response_create(
      1,
      1
    );
  } else {
    promote_chat_member_response = promote_chat_member_response_create(
      1,
      1
    );
  }

  return promote_chat_member_response;
}


#ifdef promote_chat_member_response_MAIN

void test_promote_chat_member_response(int include_optional) {
    promote_chat_member_response_t* promote_chat_member_response_1 = instantiate_promote_chat_member_response(include_optional);

	cJSON* jsonpromote_chat_member_response_1 = promote_chat_member_response_convertToJSON(promote_chat_member_response_1);
	printf("promote_chat_member_response :\n%s\n", cJSON_Print(jsonpromote_chat_member_response_1));
	promote_chat_member_response_t* promote_chat_member_response_2 = promote_chat_member_response_parseFromJSON(jsonpromote_chat_member_response_1);
	cJSON* jsonpromote_chat_member_response_2 = promote_chat_member_response_convertToJSON(promote_chat_member_response_2);
	printf("repeating promote_chat_member_response:\n%s\n", cJSON_Print(jsonpromote_chat_member_response_2));
}

int main() {
  test_promote_chat_member_response(1);
  test_promote_chat_member_response(0);

  printf("Hello world \n");
  return 0;
}

#endif // promote_chat_member_response_MAIN
#endif // promote_chat_member_response_TEST
