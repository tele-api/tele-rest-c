#ifndef _leave_chat_post_request_chat_id_TEST
#define _leave_chat_post_request_chat_id_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define _leave_chat_post_request_chat_id_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/_leave_chat_post_request_chat_id.h"
_leave_chat_post_request_chat_id_t* instantiate__leave_chat_post_request_chat_id(int include_optional);



_leave_chat_post_request_chat_id_t* instantiate__leave_chat_post_request_chat_id(int include_optional) {
  _leave_chat_post_request_chat_id_t* _leave_chat_post_request_chat_id = NULL;
  if (include_optional) {
    _leave_chat_post_request_chat_id = _leave_chat_post_request_chat_id_create(
    );
  } else {
    _leave_chat_post_request_chat_id = _leave_chat_post_request_chat_id_create(
    );
  }

  return _leave_chat_post_request_chat_id;
}


#ifdef _leave_chat_post_request_chat_id_MAIN

void test__leave_chat_post_request_chat_id(int include_optional) {
    _leave_chat_post_request_chat_id_t* _leave_chat_post_request_chat_id_1 = instantiate__leave_chat_post_request_chat_id(include_optional);

	cJSON* json_leave_chat_post_request_chat_id_1 = _leave_chat_post_request_chat_id_convertToJSON(_leave_chat_post_request_chat_id_1);
	printf("_leave_chat_post_request_chat_id :\n%s\n", cJSON_Print(json_leave_chat_post_request_chat_id_1));
	_leave_chat_post_request_chat_id_t* _leave_chat_post_request_chat_id_2 = _leave_chat_post_request_chat_id_parseFromJSON(json_leave_chat_post_request_chat_id_1);
	cJSON* json_leave_chat_post_request_chat_id_2 = _leave_chat_post_request_chat_id_convertToJSON(_leave_chat_post_request_chat_id_2);
	printf("repeating _leave_chat_post_request_chat_id:\n%s\n", cJSON_Print(json_leave_chat_post_request_chat_id_2));
}

int main() {
  test__leave_chat_post_request_chat_id(1);
  test__leave_chat_post_request_chat_id(0);

  printf("Hello world \n");
  return 0;
}

#endif // _leave_chat_post_request_chat_id_MAIN
#endif // _leave_chat_post_request_chat_id_TEST
