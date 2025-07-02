#ifndef send_dice_response_TEST
#define send_dice_response_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define send_dice_response_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/send_dice_response.h"
send_dice_response_t* instantiate_send_dice_response(int include_optional);

#include "test_message.c"


send_dice_response_t* instantiate_send_dice_response(int include_optional) {
  send_dice_response_t* send_dice_response = NULL;
  if (include_optional) {
    send_dice_response = send_dice_response_create(
      1,
       // false, not to have infinite recursion
      instantiate_message(0)
    );
  } else {
    send_dice_response = send_dice_response_create(
      1,
      NULL
    );
  }

  return send_dice_response;
}


#ifdef send_dice_response_MAIN

void test_send_dice_response(int include_optional) {
    send_dice_response_t* send_dice_response_1 = instantiate_send_dice_response(include_optional);

	cJSON* jsonsend_dice_response_1 = send_dice_response_convertToJSON(send_dice_response_1);
	printf("send_dice_response :\n%s\n", cJSON_Print(jsonsend_dice_response_1));
	send_dice_response_t* send_dice_response_2 = send_dice_response_parseFromJSON(jsonsend_dice_response_1);
	cJSON* jsonsend_dice_response_2 = send_dice_response_convertToJSON(send_dice_response_2);
	printf("repeating send_dice_response:\n%s\n", cJSON_Print(jsonsend_dice_response_2));
}

int main() {
  test_send_dice_response(1);
  test_send_dice_response(0);

  printf("Hello world \n");
  return 0;
}

#endif // send_dice_response_MAIN
#endif // send_dice_response_TEST
