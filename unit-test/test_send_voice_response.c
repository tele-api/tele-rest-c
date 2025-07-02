#ifndef send_voice_response_TEST
#define send_voice_response_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define send_voice_response_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/send_voice_response.h"
send_voice_response_t* instantiate_send_voice_response(int include_optional);

#include "test_message.c"


send_voice_response_t* instantiate_send_voice_response(int include_optional) {
  send_voice_response_t* send_voice_response = NULL;
  if (include_optional) {
    send_voice_response = send_voice_response_create(
      1,
       // false, not to have infinite recursion
      instantiate_message(0)
    );
  } else {
    send_voice_response = send_voice_response_create(
      1,
      NULL
    );
  }

  return send_voice_response;
}


#ifdef send_voice_response_MAIN

void test_send_voice_response(int include_optional) {
    send_voice_response_t* send_voice_response_1 = instantiate_send_voice_response(include_optional);

	cJSON* jsonsend_voice_response_1 = send_voice_response_convertToJSON(send_voice_response_1);
	printf("send_voice_response :\n%s\n", cJSON_Print(jsonsend_voice_response_1));
	send_voice_response_t* send_voice_response_2 = send_voice_response_parseFromJSON(jsonsend_voice_response_1);
	cJSON* jsonsend_voice_response_2 = send_voice_response_convertToJSON(send_voice_response_2);
	printf("repeating send_voice_response:\n%s\n", cJSON_Print(jsonsend_voice_response_2));
}

int main() {
  test_send_voice_response(1);
  test_send_voice_response(0);

  printf("Hello world \n");
  return 0;
}

#endif // send_voice_response_MAIN
#endif // send_voice_response_TEST
