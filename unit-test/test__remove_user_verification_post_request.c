#ifndef _remove_user_verification_post_request_TEST
#define _remove_user_verification_post_request_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define _remove_user_verification_post_request_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/_remove_user_verification_post_request.h"
_remove_user_verification_post_request_t* instantiate__remove_user_verification_post_request(int include_optional);



_remove_user_verification_post_request_t* instantiate__remove_user_verification_post_request(int include_optional) {
  _remove_user_verification_post_request_t* _remove_user_verification_post_request = NULL;
  if (include_optional) {
    _remove_user_verification_post_request = _remove_user_verification_post_request_create(
      56
    );
  } else {
    _remove_user_verification_post_request = _remove_user_verification_post_request_create(
      56
    );
  }

  return _remove_user_verification_post_request;
}


#ifdef _remove_user_verification_post_request_MAIN

void test__remove_user_verification_post_request(int include_optional) {
    _remove_user_verification_post_request_t* _remove_user_verification_post_request_1 = instantiate__remove_user_verification_post_request(include_optional);

	cJSON* json_remove_user_verification_post_request_1 = _remove_user_verification_post_request_convertToJSON(_remove_user_verification_post_request_1);
	printf("_remove_user_verification_post_request :\n%s\n", cJSON_Print(json_remove_user_verification_post_request_1));
	_remove_user_verification_post_request_t* _remove_user_verification_post_request_2 = _remove_user_verification_post_request_parseFromJSON(json_remove_user_verification_post_request_1);
	cJSON* json_remove_user_verification_post_request_2 = _remove_user_verification_post_request_convertToJSON(_remove_user_verification_post_request_2);
	printf("repeating _remove_user_verification_post_request:\n%s\n", cJSON_Print(json_remove_user_verification_post_request_2));
}

int main() {
  test__remove_user_verification_post_request(1);
  test__remove_user_verification_post_request(0);

  printf("Hello world \n");
  return 0;
}

#endif // _remove_user_verification_post_request_MAIN
#endif // _remove_user_verification_post_request_TEST
