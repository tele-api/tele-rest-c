#ifndef send_audio_response_TEST
#define send_audio_response_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define send_audio_response_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/send_audio_response.h"
send_audio_response_t* instantiate_send_audio_response(int include_optional);

#include "test_message.c"


send_audio_response_t* instantiate_send_audio_response(int include_optional) {
  send_audio_response_t* send_audio_response = NULL;
  if (include_optional) {
    send_audio_response = send_audio_response_create(
      1,
       // false, not to have infinite recursion
      instantiate_message(0)
    );
  } else {
    send_audio_response = send_audio_response_create(
      1,
      NULL
    );
  }

  return send_audio_response;
}


#ifdef send_audio_response_MAIN

void test_send_audio_response(int include_optional) {
    send_audio_response_t* send_audio_response_1 = instantiate_send_audio_response(include_optional);

	cJSON* jsonsend_audio_response_1 = send_audio_response_convertToJSON(send_audio_response_1);
	printf("send_audio_response :\n%s\n", cJSON_Print(jsonsend_audio_response_1));
	send_audio_response_t* send_audio_response_2 = send_audio_response_parseFromJSON(jsonsend_audio_response_1);
	cJSON* jsonsend_audio_response_2 = send_audio_response_convertToJSON(send_audio_response_2);
	printf("repeating send_audio_response:\n%s\n", cJSON_Print(jsonsend_audio_response_2));
}

int main() {
  test_send_audio_response(1);
  test_send_audio_response(0);

  printf("Hello world \n");
  return 0;
}

#endif // send_audio_response_MAIN
#endif // send_audio_response_TEST
