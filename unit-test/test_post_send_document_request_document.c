#ifndef post_send_document_request_document_TEST
#define post_send_document_request_document_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define post_send_document_request_document_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/post_send_document_request_document.h"
post_send_document_request_document_t* instantiate_post_send_document_request_document(int include_optional);



post_send_document_request_document_t* instantiate_post_send_document_request_document(int include_optional) {
  post_send_document_request_document_t* post_send_document_request_document = NULL;
  if (include_optional) {
    post_send_document_request_document = post_send_document_request_document_create(
    );
  } else {
    post_send_document_request_document = post_send_document_request_document_create(
    );
  }

  return post_send_document_request_document;
}


#ifdef post_send_document_request_document_MAIN

void test_post_send_document_request_document(int include_optional) {
    post_send_document_request_document_t* post_send_document_request_document_1 = instantiate_post_send_document_request_document(include_optional);

	cJSON* jsonpost_send_document_request_document_1 = post_send_document_request_document_convertToJSON(post_send_document_request_document_1);
	printf("post_send_document_request_document :\n%s\n", cJSON_Print(jsonpost_send_document_request_document_1));
	post_send_document_request_document_t* post_send_document_request_document_2 = post_send_document_request_document_parseFromJSON(jsonpost_send_document_request_document_1);
	cJSON* jsonpost_send_document_request_document_2 = post_send_document_request_document_convertToJSON(post_send_document_request_document_2);
	printf("repeating post_send_document_request_document:\n%s\n", cJSON_Print(jsonpost_send_document_request_document_2));
}

int main() {
  test_post_send_document_request_document(1);
  test_post_send_document_request_document(0);

  printf("Hello world \n");
  return 0;
}

#endif // post_send_document_request_document_MAIN
#endif // post_send_document_request_document_TEST
