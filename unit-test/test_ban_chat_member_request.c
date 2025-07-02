#ifndef ban_chat_member_request_TEST
#define ban_chat_member_request_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define ban_chat_member_request_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/ban_chat_member_request.h"
ban_chat_member_request_t* instantiate_ban_chat_member_request(int include_optional);

#include "test_ban_chat_member_request_chat_id.c"


ban_chat_member_request_t* instantiate_ban_chat_member_request(int include_optional) {
  ban_chat_member_request_t* ban_chat_member_request = NULL;
  if (include_optional) {
    ban_chat_member_request = ban_chat_member_request_create(
      null,
      56,
      56,
      1
    );
  } else {
    ban_chat_member_request = ban_chat_member_request_create(
      null,
      56,
      56,
      1
    );
  }

  return ban_chat_member_request;
}


#ifdef ban_chat_member_request_MAIN

void test_ban_chat_member_request(int include_optional) {
    ban_chat_member_request_t* ban_chat_member_request_1 = instantiate_ban_chat_member_request(include_optional);

	cJSON* jsonban_chat_member_request_1 = ban_chat_member_request_convertToJSON(ban_chat_member_request_1);
	printf("ban_chat_member_request :\n%s\n", cJSON_Print(jsonban_chat_member_request_1));
	ban_chat_member_request_t* ban_chat_member_request_2 = ban_chat_member_request_parseFromJSON(jsonban_chat_member_request_1);
	cJSON* jsonban_chat_member_request_2 = ban_chat_member_request_convertToJSON(ban_chat_member_request_2);
	printf("repeating ban_chat_member_request:\n%s\n", cJSON_Print(jsonban_chat_member_request_2));
}

int main() {
  test_ban_chat_member_request(1);
  test_ban_chat_member_request(0);

  printf("Hello world \n");
  return 0;
}

#endif // ban_chat_member_request_MAIN
#endif // ban_chat_member_request_TEST
