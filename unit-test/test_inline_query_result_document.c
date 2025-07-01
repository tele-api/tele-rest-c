#ifndef inline_query_result_document_TEST
#define inline_query_result_document_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define inline_query_result_document_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/inline_query_result_document.h"
inline_query_result_document_t* instantiate_inline_query_result_document(int include_optional);

#include "test_inline_keyboard_markup.c"
#include "test_input_message_content.c"


inline_query_result_document_t* instantiate_inline_query_result_document(int include_optional) {
  inline_query_result_document_t* inline_query_result_document = NULL;
  if (include_optional) {
    inline_query_result_document = inline_query_result_document_create(
      "document",
      "0",
      "0",
      "0",
      telegram_bot_api_inline_query_result_document_MIMETYPE_application/pdf,
      "0",
      "0",
      list_createList(),
      "0",
       // false, not to have infinite recursion
      instantiate_inline_keyboard_markup(0),
      null,
      "0",
      56,
      56
    );
  } else {
    inline_query_result_document = inline_query_result_document_create(
      "document",
      "0",
      "0",
      "0",
      telegram_bot_api_inline_query_result_document_MIMETYPE_application/pdf,
      "0",
      "0",
      list_createList(),
      "0",
      NULL,
      null,
      "0",
      56,
      56
    );
  }

  return inline_query_result_document;
}


#ifdef inline_query_result_document_MAIN

void test_inline_query_result_document(int include_optional) {
    inline_query_result_document_t* inline_query_result_document_1 = instantiate_inline_query_result_document(include_optional);

	cJSON* jsoninline_query_result_document_1 = inline_query_result_document_convertToJSON(inline_query_result_document_1);
	printf("inline_query_result_document :\n%s\n", cJSON_Print(jsoninline_query_result_document_1));
	inline_query_result_document_t* inline_query_result_document_2 = inline_query_result_document_parseFromJSON(jsoninline_query_result_document_1);
	cJSON* jsoninline_query_result_document_2 = inline_query_result_document_convertToJSON(inline_query_result_document_2);
	printf("repeating inline_query_result_document:\n%s\n", cJSON_Print(jsoninline_query_result_document_2));
}

int main() {
  test_inline_query_result_document(1);
  test_inline_query_result_document(0);

  printf("Hello world \n");
  return 0;
}

#endif // inline_query_result_document_MAIN
#endif // inline_query_result_document_TEST
