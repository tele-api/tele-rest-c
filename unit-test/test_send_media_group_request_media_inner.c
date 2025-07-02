#ifndef send_media_group_request_media_inner_TEST
#define send_media_group_request_media_inner_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define send_media_group_request_media_inner_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/send_media_group_request_media_inner.h"
send_media_group_request_media_inner_t* instantiate_send_media_group_request_media_inner(int include_optional);



send_media_group_request_media_inner_t* instantiate_send_media_group_request_media_inner(int include_optional) {
  send_media_group_request_media_inner_t* send_media_group_request_media_inner = NULL;
  if (include_optional) {
    send_media_group_request_media_inner = send_media_group_request_media_inner_create(
      "video",
      "0",
      "0",
      "0",
      "0",
      list_createList(),
      56,
      "0",
      "0",
      1,
      1,
      1,
      "0",
      56,
      56,
      56,
      1
    );
  } else {
    send_media_group_request_media_inner = send_media_group_request_media_inner_create(
      "video",
      "0",
      "0",
      "0",
      "0",
      list_createList(),
      56,
      "0",
      "0",
      1,
      1,
      1,
      "0",
      56,
      56,
      56,
      1
    );
  }

  return send_media_group_request_media_inner;
}


#ifdef send_media_group_request_media_inner_MAIN

void test_send_media_group_request_media_inner(int include_optional) {
    send_media_group_request_media_inner_t* send_media_group_request_media_inner_1 = instantiate_send_media_group_request_media_inner(include_optional);

	cJSON* jsonsend_media_group_request_media_inner_1 = send_media_group_request_media_inner_convertToJSON(send_media_group_request_media_inner_1);
	printf("send_media_group_request_media_inner :\n%s\n", cJSON_Print(jsonsend_media_group_request_media_inner_1));
	send_media_group_request_media_inner_t* send_media_group_request_media_inner_2 = send_media_group_request_media_inner_parseFromJSON(jsonsend_media_group_request_media_inner_1);
	cJSON* jsonsend_media_group_request_media_inner_2 = send_media_group_request_media_inner_convertToJSON(send_media_group_request_media_inner_2);
	printf("repeating send_media_group_request_media_inner:\n%s\n", cJSON_Print(jsonsend_media_group_request_media_inner_2));
}

int main() {
  test_send_media_group_request_media_inner(1);
  test_send_media_group_request_media_inner(0);

  printf("Hello world \n");
  return 0;
}

#endif // send_media_group_request_media_inner_MAIN
#endif // send_media_group_request_media_inner_TEST
