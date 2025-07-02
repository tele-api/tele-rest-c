#ifndef send_game_request_TEST
#define send_game_request_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define send_game_request_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/send_game_request.h"
send_game_request_t* instantiate_send_game_request(int include_optional);

#include "test_reply_parameters.c"
#include "test_inline_keyboard_markup.c"


send_game_request_t* instantiate_send_game_request(int include_optional) {
  send_game_request_t* send_game_request = NULL;
  if (include_optional) {
    send_game_request = send_game_request_create(
      56,
      "0",
      "0",
      56,
      1,
      1,
      1,
      "0",
       // false, not to have infinite recursion
      instantiate_reply_parameters(0),
       // false, not to have infinite recursion
      instantiate_inline_keyboard_markup(0)
    );
  } else {
    send_game_request = send_game_request_create(
      56,
      "0",
      "0",
      56,
      1,
      1,
      1,
      "0",
      NULL,
      NULL
    );
  }

  return send_game_request;
}


#ifdef send_game_request_MAIN

void test_send_game_request(int include_optional) {
    send_game_request_t* send_game_request_1 = instantiate_send_game_request(include_optional);

	cJSON* jsonsend_game_request_1 = send_game_request_convertToJSON(send_game_request_1);
	printf("send_game_request :\n%s\n", cJSON_Print(jsonsend_game_request_1));
	send_game_request_t* send_game_request_2 = send_game_request_parseFromJSON(jsonsend_game_request_1);
	cJSON* jsonsend_game_request_2 = send_game_request_convertToJSON(send_game_request_2);
	printf("repeating send_game_request:\n%s\n", cJSON_Print(jsonsend_game_request_2));
}

int main() {
  test_send_game_request(1);
  test_send_game_request(0);

  printf("Hello world \n");
  return 0;
}

#endif // send_game_request_MAIN
#endif // send_game_request_TEST
