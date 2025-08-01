#ifndef _get_user_chat_boosts_post_request_chat_id_TEST
#define _get_user_chat_boosts_post_request_chat_id_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define _get_user_chat_boosts_post_request_chat_id_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/_get_user_chat_boosts_post_request_chat_id.h"
_get_user_chat_boosts_post_request_chat_id_t* instantiate__get_user_chat_boosts_post_request_chat_id(int include_optional);



_get_user_chat_boosts_post_request_chat_id_t* instantiate__get_user_chat_boosts_post_request_chat_id(int include_optional) {
  _get_user_chat_boosts_post_request_chat_id_t* _get_user_chat_boosts_post_request_chat_id = NULL;
  if (include_optional) {
    _get_user_chat_boosts_post_request_chat_id = _get_user_chat_boosts_post_request_chat_id_create(
    );
  } else {
    _get_user_chat_boosts_post_request_chat_id = _get_user_chat_boosts_post_request_chat_id_create(
    );
  }

  return _get_user_chat_boosts_post_request_chat_id;
}


#ifdef _get_user_chat_boosts_post_request_chat_id_MAIN

void test__get_user_chat_boosts_post_request_chat_id(int include_optional) {
    _get_user_chat_boosts_post_request_chat_id_t* _get_user_chat_boosts_post_request_chat_id_1 = instantiate__get_user_chat_boosts_post_request_chat_id(include_optional);

	cJSON* json_get_user_chat_boosts_post_request_chat_id_1 = _get_user_chat_boosts_post_request_chat_id_convertToJSON(_get_user_chat_boosts_post_request_chat_id_1);
	printf("_get_user_chat_boosts_post_request_chat_id :\n%s\n", cJSON_Print(json_get_user_chat_boosts_post_request_chat_id_1));
	_get_user_chat_boosts_post_request_chat_id_t* _get_user_chat_boosts_post_request_chat_id_2 = _get_user_chat_boosts_post_request_chat_id_parseFromJSON(json_get_user_chat_boosts_post_request_chat_id_1);
	cJSON* json_get_user_chat_boosts_post_request_chat_id_2 = _get_user_chat_boosts_post_request_chat_id_convertToJSON(_get_user_chat_boosts_post_request_chat_id_2);
	printf("repeating _get_user_chat_boosts_post_request_chat_id:\n%s\n", cJSON_Print(json_get_user_chat_boosts_post_request_chat_id_2));
}

int main() {
  test__get_user_chat_boosts_post_request_chat_id(1);
  test__get_user_chat_boosts_post_request_chat_id(0);

  printf("Hello world \n");
  return 0;
}

#endif // _get_user_chat_boosts_post_request_chat_id_MAIN
#endif // _get_user_chat_boosts_post_request_chat_id_TEST
