#ifndef send_game_response_TEST
#define send_game_response_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define send_game_response_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/send_game_response.h"
send_game_response_t* instantiate_send_game_response(int include_optional);

#include "test_message.c"


send_game_response_t* instantiate_send_game_response(int include_optional) {
  send_game_response_t* send_game_response = NULL;
  if (include_optional) {
    send_game_response = send_game_response_create(
      1,
       // false, not to have infinite recursion
      instantiate_message(0)
    );
  } else {
    send_game_response = send_game_response_create(
      1,
      NULL
    );
  }

  return send_game_response;
}


#ifdef send_game_response_MAIN

void test_send_game_response(int include_optional) {
    send_game_response_t* send_game_response_1 = instantiate_send_game_response(include_optional);

	cJSON* jsonsend_game_response_1 = send_game_response_convertToJSON(send_game_response_1);
	printf("send_game_response :\n%s\n", cJSON_Print(jsonsend_game_response_1));
	send_game_response_t* send_game_response_2 = send_game_response_parseFromJSON(jsonsend_game_response_1);
	cJSON* jsonsend_game_response_2 = send_game_response_convertToJSON(send_game_response_2);
	printf("repeating send_game_response:\n%s\n", cJSON_Print(jsonsend_game_response_2));
}

int main() {
  test_send_game_response(1);
  test_send_game_response(0);

  printf("Hello world \n");
  return 0;
}

#endif // send_game_response_MAIN
#endif // send_game_response_TEST
