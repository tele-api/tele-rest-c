#ifndef _send_media_group_post_200_response_TEST
#define _send_media_group_post_200_response_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define _send_media_group_post_200_response_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/_send_media_group_post_200_response.h"
_send_media_group_post_200_response_t* instantiate__send_media_group_post_200_response(int include_optional);



_send_media_group_post_200_response_t* instantiate__send_media_group_post_200_response(int include_optional) {
  _send_media_group_post_200_response_t* _send_media_group_post_200_response = NULL;
  if (include_optional) {
    _send_media_group_post_200_response = _send_media_group_post_200_response_create(
      1,
      list_createList()
    );
  } else {
    _send_media_group_post_200_response = _send_media_group_post_200_response_create(
      1,
      list_createList()
    );
  }

  return _send_media_group_post_200_response;
}


#ifdef _send_media_group_post_200_response_MAIN

void test__send_media_group_post_200_response(int include_optional) {
    _send_media_group_post_200_response_t* _send_media_group_post_200_response_1 = instantiate__send_media_group_post_200_response(include_optional);

	cJSON* json_send_media_group_post_200_response_1 = _send_media_group_post_200_response_convertToJSON(_send_media_group_post_200_response_1);
	printf("_send_media_group_post_200_response :\n%s\n", cJSON_Print(json_send_media_group_post_200_response_1));
	_send_media_group_post_200_response_t* _send_media_group_post_200_response_2 = _send_media_group_post_200_response_parseFromJSON(json_send_media_group_post_200_response_1);
	cJSON* json_send_media_group_post_200_response_2 = _send_media_group_post_200_response_convertToJSON(_send_media_group_post_200_response_2);
	printf("repeating _send_media_group_post_200_response:\n%s\n", cJSON_Print(json_send_media_group_post_200_response_2));
}

int main() {
  test__send_media_group_post_200_response(1);
  test__send_media_group_post_200_response(0);

  printf("Hello world \n");
  return 0;
}

#endif // _send_media_group_post_200_response_MAIN
#endif // _send_media_group_post_200_response_TEST
