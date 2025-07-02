#ifndef ban_chat_member_request_chat_id_TEST
#define ban_chat_member_request_chat_id_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define ban_chat_member_request_chat_id_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/ban_chat_member_request_chat_id.h"
ban_chat_member_request_chat_id_t* instantiate_ban_chat_member_request_chat_id(int include_optional);



ban_chat_member_request_chat_id_t* instantiate_ban_chat_member_request_chat_id(int include_optional) {
  ban_chat_member_request_chat_id_t* ban_chat_member_request_chat_id = NULL;
  if (include_optional) {
    ban_chat_member_request_chat_id = ban_chat_member_request_chat_id_create(
    );
  } else {
    ban_chat_member_request_chat_id = ban_chat_member_request_chat_id_create(
    );
  }

  return ban_chat_member_request_chat_id;
}


#ifdef ban_chat_member_request_chat_id_MAIN

void test_ban_chat_member_request_chat_id(int include_optional) {
    ban_chat_member_request_chat_id_t* ban_chat_member_request_chat_id_1 = instantiate_ban_chat_member_request_chat_id(include_optional);

	cJSON* jsonban_chat_member_request_chat_id_1 = ban_chat_member_request_chat_id_convertToJSON(ban_chat_member_request_chat_id_1);
	printf("ban_chat_member_request_chat_id :\n%s\n", cJSON_Print(jsonban_chat_member_request_chat_id_1));
	ban_chat_member_request_chat_id_t* ban_chat_member_request_chat_id_2 = ban_chat_member_request_chat_id_parseFromJSON(jsonban_chat_member_request_chat_id_1);
	cJSON* jsonban_chat_member_request_chat_id_2 = ban_chat_member_request_chat_id_convertToJSON(ban_chat_member_request_chat_id_2);
	printf("repeating ban_chat_member_request_chat_id:\n%s\n", cJSON_Print(jsonban_chat_member_request_chat_id_2));
}

int main() {
  test_ban_chat_member_request_chat_id(1);
  test_ban_chat_member_request_chat_id(0);

  printf("Hello world \n");
  return 0;
}

#endif // ban_chat_member_request_chat_id_MAIN
#endif // ban_chat_member_request_chat_id_TEST
