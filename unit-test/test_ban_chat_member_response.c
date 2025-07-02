#ifndef ban_chat_member_response_TEST
#define ban_chat_member_response_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define ban_chat_member_response_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/ban_chat_member_response.h"
ban_chat_member_response_t* instantiate_ban_chat_member_response(int include_optional);



ban_chat_member_response_t* instantiate_ban_chat_member_response(int include_optional) {
  ban_chat_member_response_t* ban_chat_member_response = NULL;
  if (include_optional) {
    ban_chat_member_response = ban_chat_member_response_create(
      1,
      1
    );
  } else {
    ban_chat_member_response = ban_chat_member_response_create(
      1,
      1
    );
  }

  return ban_chat_member_response;
}


#ifdef ban_chat_member_response_MAIN

void test_ban_chat_member_response(int include_optional) {
    ban_chat_member_response_t* ban_chat_member_response_1 = instantiate_ban_chat_member_response(include_optional);

	cJSON* jsonban_chat_member_response_1 = ban_chat_member_response_convertToJSON(ban_chat_member_response_1);
	printf("ban_chat_member_response :\n%s\n", cJSON_Print(jsonban_chat_member_response_1));
	ban_chat_member_response_t* ban_chat_member_response_2 = ban_chat_member_response_parseFromJSON(jsonban_chat_member_response_1);
	cJSON* jsonban_chat_member_response_2 = ban_chat_member_response_convertToJSON(ban_chat_member_response_2);
	printf("repeating ban_chat_member_response:\n%s\n", cJSON_Print(jsonban_chat_member_response_2));
}

int main() {
  test_ban_chat_member_response(1);
  test_ban_chat_member_response(0);

  printf("Hello world \n");
  return 0;
}

#endif // ban_chat_member_response_MAIN
#endif // ban_chat_member_response_TEST
