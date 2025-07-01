#ifndef input_media_document_TEST
#define input_media_document_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define input_media_document_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/input_media_document.h"
input_media_document_t* instantiate_input_media_document(int include_optional);



input_media_document_t* instantiate_input_media_document(int include_optional) {
  input_media_document_t* input_media_document = NULL;
  if (include_optional) {
    input_media_document = input_media_document_create(
      "document",
      "0",
      "0",
      "0",
      "0",
      list_createList(),
      1
    );
  } else {
    input_media_document = input_media_document_create(
      "document",
      "0",
      "0",
      "0",
      "0",
      list_createList(),
      1
    );
  }

  return input_media_document;
}


#ifdef input_media_document_MAIN

void test_input_media_document(int include_optional) {
    input_media_document_t* input_media_document_1 = instantiate_input_media_document(include_optional);

	cJSON* jsoninput_media_document_1 = input_media_document_convertToJSON(input_media_document_1);
	printf("input_media_document :\n%s\n", cJSON_Print(jsoninput_media_document_1));
	input_media_document_t* input_media_document_2 = input_media_document_parseFromJSON(jsoninput_media_document_1);
	cJSON* jsoninput_media_document_2 = input_media_document_convertToJSON(input_media_document_2);
	printf("repeating input_media_document:\n%s\n", cJSON_Print(jsoninput_media_document_2));
}

int main() {
  test_input_media_document(1);
  test_input_media_document(0);

  printf("Hello world \n");
  return 0;
}

#endif // input_media_document_MAIN
#endif // input_media_document_TEST
