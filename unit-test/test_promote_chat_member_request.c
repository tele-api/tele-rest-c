#ifndef promote_chat_member_request_TEST
#define promote_chat_member_request_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define promote_chat_member_request_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/promote_chat_member_request.h"
promote_chat_member_request_t* instantiate_promote_chat_member_request(int include_optional);

#include "test_send_message_request_chat_id.c"


promote_chat_member_request_t* instantiate_promote_chat_member_request(int include_optional) {
  promote_chat_member_request_t* promote_chat_member_request = NULL;
  if (include_optional) {
    promote_chat_member_request = promote_chat_member_request_create(
      null,
      56,
      1,
      1,
      1,
      1,
      1,
      1,
      1,
      1,
      1,
      1,
      1,
      1,
      1,
      1,
      1
    );
  } else {
    promote_chat_member_request = promote_chat_member_request_create(
      null,
      56,
      1,
      1,
      1,
      1,
      1,
      1,
      1,
      1,
      1,
      1,
      1,
      1,
      1,
      1,
      1
    );
  }

  return promote_chat_member_request;
}


#ifdef promote_chat_member_request_MAIN

void test_promote_chat_member_request(int include_optional) {
    promote_chat_member_request_t* promote_chat_member_request_1 = instantiate_promote_chat_member_request(include_optional);

	cJSON* jsonpromote_chat_member_request_1 = promote_chat_member_request_convertToJSON(promote_chat_member_request_1);
	printf("promote_chat_member_request :\n%s\n", cJSON_Print(jsonpromote_chat_member_request_1));
	promote_chat_member_request_t* promote_chat_member_request_2 = promote_chat_member_request_parseFromJSON(jsonpromote_chat_member_request_1);
	cJSON* jsonpromote_chat_member_request_2 = promote_chat_member_request_convertToJSON(promote_chat_member_request_2);
	printf("repeating promote_chat_member_request:\n%s\n", cJSON_Print(jsonpromote_chat_member_request_2));
}

int main() {
  test_promote_chat_member_request(1);
  test_promote_chat_member_request(0);

  printf("Hello world \n");
  return 0;
}

#endif // promote_chat_member_request_MAIN
#endif // promote_chat_member_request_TEST
