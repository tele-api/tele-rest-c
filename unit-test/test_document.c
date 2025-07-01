#ifndef document_TEST
#define document_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define document_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/document.h"
document_t* instantiate_document(int include_optional);

#include "test_photo_size.c"


document_t* instantiate_document(int include_optional) {
  document_t* document = NULL;
  if (include_optional) {
    document = document_create(
      "0",
      "0",
       // false, not to have infinite recursion
      instantiate_photo_size(0),
      "0",
      "0",
      56
    );
  } else {
    document = document_create(
      "0",
      "0",
      NULL,
      "0",
      "0",
      56
    );
  }

  return document;
}


#ifdef document_MAIN

void test_document(int include_optional) {
    document_t* document_1 = instantiate_document(include_optional);

	cJSON* jsondocument_1 = document_convertToJSON(document_1);
	printf("document :\n%s\n", cJSON_Print(jsondocument_1));
	document_t* document_2 = document_parseFromJSON(jsondocument_1);
	cJSON* jsondocument_2 = document_convertToJSON(document_2);
	printf("repeating document:\n%s\n", cJSON_Print(jsondocument_2));
}

int main() {
  test_document(1);
  test_document(0);

  printf("Hello world \n");
  return 0;
}

#endif // document_MAIN
#endif // document_TEST
