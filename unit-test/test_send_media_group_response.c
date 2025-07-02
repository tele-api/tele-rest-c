#ifndef send_media_group_response_TEST
#define send_media_group_response_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define send_media_group_response_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/send_media_group_response.h"
send_media_group_response_t* instantiate_send_media_group_response(int include_optional);



send_media_group_response_t* instantiate_send_media_group_response(int include_optional) {
  send_media_group_response_t* send_media_group_response = NULL;
  if (include_optional) {
    send_media_group_response = send_media_group_response_create(
      1,
      list_createList()
    );
  } else {
    send_media_group_response = send_media_group_response_create(
      1,
      list_createList()
    );
  }

  return send_media_group_response;
}


#ifdef send_media_group_response_MAIN

void test_send_media_group_response(int include_optional) {
    send_media_group_response_t* send_media_group_response_1 = instantiate_send_media_group_response(include_optional);

	cJSON* jsonsend_media_group_response_1 = send_media_group_response_convertToJSON(send_media_group_response_1);
	printf("send_media_group_response :\n%s\n", cJSON_Print(jsonsend_media_group_response_1));
	send_media_group_response_t* send_media_group_response_2 = send_media_group_response_parseFromJSON(jsonsend_media_group_response_1);
	cJSON* jsonsend_media_group_response_2 = send_media_group_response_convertToJSON(send_media_group_response_2);
	printf("repeating send_media_group_response:\n%s\n", cJSON_Print(jsonsend_media_group_response_2));
}

int main() {
  test_send_media_group_response(1);
  test_send_media_group_response(0);

  printf("Hello world \n");
  return 0;
}

#endif // send_media_group_response_MAIN
#endif // send_media_group_response_TEST
