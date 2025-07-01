#ifndef text_quote_TEST
#define text_quote_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define text_quote_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/text_quote.h"
text_quote_t* instantiate_text_quote(int include_optional);



text_quote_t* instantiate_text_quote(int include_optional) {
  text_quote_t* text_quote = NULL;
  if (include_optional) {
    text_quote = text_quote_create(
      "0",
      56,
      list_createList(),
      1
    );
  } else {
    text_quote = text_quote_create(
      "0",
      56,
      list_createList(),
      1
    );
  }

  return text_quote;
}


#ifdef text_quote_MAIN

void test_text_quote(int include_optional) {
    text_quote_t* text_quote_1 = instantiate_text_quote(include_optional);

	cJSON* jsontext_quote_1 = text_quote_convertToJSON(text_quote_1);
	printf("text_quote :\n%s\n", cJSON_Print(jsontext_quote_1));
	text_quote_t* text_quote_2 = text_quote_parseFromJSON(jsontext_quote_1);
	cJSON* jsontext_quote_2 = text_quote_convertToJSON(text_quote_2);
	printf("repeating text_quote:\n%s\n", cJSON_Print(jsontext_quote_2));
}

int main() {
  test_text_quote(1);
  test_text_quote(0);

  printf("Hello world \n");
  return 0;
}

#endif // text_quote_MAIN
#endif // text_quote_TEST
