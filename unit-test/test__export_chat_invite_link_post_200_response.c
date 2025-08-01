#ifndef _export_chat_invite_link_post_200_response_TEST
#define _export_chat_invite_link_post_200_response_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define _export_chat_invite_link_post_200_response_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/_export_chat_invite_link_post_200_response.h"
_export_chat_invite_link_post_200_response_t* instantiate__export_chat_invite_link_post_200_response(int include_optional);



_export_chat_invite_link_post_200_response_t* instantiate__export_chat_invite_link_post_200_response(int include_optional) {
  _export_chat_invite_link_post_200_response_t* _export_chat_invite_link_post_200_response = NULL;
  if (include_optional) {
    _export_chat_invite_link_post_200_response = _export_chat_invite_link_post_200_response_create(
      1,
      "0"
    );
  } else {
    _export_chat_invite_link_post_200_response = _export_chat_invite_link_post_200_response_create(
      1,
      "0"
    );
  }

  return _export_chat_invite_link_post_200_response;
}


#ifdef _export_chat_invite_link_post_200_response_MAIN

void test__export_chat_invite_link_post_200_response(int include_optional) {
    _export_chat_invite_link_post_200_response_t* _export_chat_invite_link_post_200_response_1 = instantiate__export_chat_invite_link_post_200_response(include_optional);

	cJSON* json_export_chat_invite_link_post_200_response_1 = _export_chat_invite_link_post_200_response_convertToJSON(_export_chat_invite_link_post_200_response_1);
	printf("_export_chat_invite_link_post_200_response :\n%s\n", cJSON_Print(json_export_chat_invite_link_post_200_response_1));
	_export_chat_invite_link_post_200_response_t* _export_chat_invite_link_post_200_response_2 = _export_chat_invite_link_post_200_response_parseFromJSON(json_export_chat_invite_link_post_200_response_1);
	cJSON* json_export_chat_invite_link_post_200_response_2 = _export_chat_invite_link_post_200_response_convertToJSON(_export_chat_invite_link_post_200_response_2);
	printf("repeating _export_chat_invite_link_post_200_response:\n%s\n", cJSON_Print(json_export_chat_invite_link_post_200_response_2));
}

int main() {
  test__export_chat_invite_link_post_200_response(1);
  test__export_chat_invite_link_post_200_response(0);

  printf("Hello world \n");
  return 0;
}

#endif // _export_chat_invite_link_post_200_response_MAIN
#endif // _export_chat_invite_link_post_200_response_TEST
