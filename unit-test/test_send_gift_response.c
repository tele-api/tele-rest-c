#ifndef send_gift_response_TEST
#define send_gift_response_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define send_gift_response_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/send_gift_response.h"
send_gift_response_t* instantiate_send_gift_response(int include_optional);



send_gift_response_t* instantiate_send_gift_response(int include_optional) {
  send_gift_response_t* send_gift_response = NULL;
  if (include_optional) {
    send_gift_response = send_gift_response_create(
      1,
      1
    );
  } else {
    send_gift_response = send_gift_response_create(
      1,
      1
    );
  }

  return send_gift_response;
}


#ifdef send_gift_response_MAIN

void test_send_gift_response(int include_optional) {
    send_gift_response_t* send_gift_response_1 = instantiate_send_gift_response(include_optional);

	cJSON* jsonsend_gift_response_1 = send_gift_response_convertToJSON(send_gift_response_1);
	printf("send_gift_response :\n%s\n", cJSON_Print(jsonsend_gift_response_1));
	send_gift_response_t* send_gift_response_2 = send_gift_response_parseFromJSON(jsonsend_gift_response_1);
	cJSON* jsonsend_gift_response_2 = send_gift_response_convertToJSON(send_gift_response_2);
	printf("repeating send_gift_response:\n%s\n", cJSON_Print(jsonsend_gift_response_2));
}

int main() {
  test_send_gift_response(1);
  test_send_gift_response(0);

  printf("Hello world \n");
  return 0;
}

#endif // send_gift_response_MAIN
#endif // send_gift_response_TEST
