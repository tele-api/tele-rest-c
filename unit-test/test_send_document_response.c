#ifndef send_document_response_TEST
#define send_document_response_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define send_document_response_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/send_document_response.h"
send_document_response_t* instantiate_send_document_response(int include_optional);

#include "test_message.c"


send_document_response_t* instantiate_send_document_response(int include_optional) {
  send_document_response_t* send_document_response = NULL;
  if (include_optional) {
    send_document_response = send_document_response_create(
      1,
       // false, not to have infinite recursion
      instantiate_message(0)
    );
  } else {
    send_document_response = send_document_response_create(
      1,
      NULL
    );
  }

  return send_document_response;
}


#ifdef send_document_response_MAIN

void test_send_document_response(int include_optional) {
    send_document_response_t* send_document_response_1 = instantiate_send_document_response(include_optional);

	cJSON* jsonsend_document_response_1 = send_document_response_convertToJSON(send_document_response_1);
	printf("send_document_response :\n%s\n", cJSON_Print(jsonsend_document_response_1));
	send_document_response_t* send_document_response_2 = send_document_response_parseFromJSON(jsonsend_document_response_1);
	cJSON* jsonsend_document_response_2 = send_document_response_convertToJSON(send_document_response_2);
	printf("repeating send_document_response:\n%s\n", cJSON_Print(jsonsend_document_response_2));
}

int main() {
  test_send_document_response(1);
  test_send_document_response(0);

  printf("Hello world \n");
  return 0;
}

#endif // send_document_response_MAIN
#endif // send_document_response_TEST
