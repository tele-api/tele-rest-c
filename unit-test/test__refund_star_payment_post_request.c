#ifndef _refund_star_payment_post_request_TEST
#define _refund_star_payment_post_request_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define _refund_star_payment_post_request_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/_refund_star_payment_post_request.h"
_refund_star_payment_post_request_t* instantiate__refund_star_payment_post_request(int include_optional);



_refund_star_payment_post_request_t* instantiate__refund_star_payment_post_request(int include_optional) {
  _refund_star_payment_post_request_t* _refund_star_payment_post_request = NULL;
  if (include_optional) {
    _refund_star_payment_post_request = _refund_star_payment_post_request_create(
      56,
      "0"
    );
  } else {
    _refund_star_payment_post_request = _refund_star_payment_post_request_create(
      56,
      "0"
    );
  }

  return _refund_star_payment_post_request;
}


#ifdef _refund_star_payment_post_request_MAIN

void test__refund_star_payment_post_request(int include_optional) {
    _refund_star_payment_post_request_t* _refund_star_payment_post_request_1 = instantiate__refund_star_payment_post_request(include_optional);

	cJSON* json_refund_star_payment_post_request_1 = _refund_star_payment_post_request_convertToJSON(_refund_star_payment_post_request_1);
	printf("_refund_star_payment_post_request :\n%s\n", cJSON_Print(json_refund_star_payment_post_request_1));
	_refund_star_payment_post_request_t* _refund_star_payment_post_request_2 = _refund_star_payment_post_request_parseFromJSON(json_refund_star_payment_post_request_1);
	cJSON* json_refund_star_payment_post_request_2 = _refund_star_payment_post_request_convertToJSON(_refund_star_payment_post_request_2);
	printf("repeating _refund_star_payment_post_request:\n%s\n", cJSON_Print(json_refund_star_payment_post_request_2));
}

int main() {
  test__refund_star_payment_post_request(1);
  test__refund_star_payment_post_request(0);

  printf("Hello world \n");
  return 0;
}

#endif // _refund_star_payment_post_request_MAIN
#endif // _refund_star_payment_post_request_TEST
