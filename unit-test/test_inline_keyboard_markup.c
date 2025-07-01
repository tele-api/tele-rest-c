#ifndef inline_keyboard_markup_TEST
#define inline_keyboard_markup_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define inline_keyboard_markup_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/inline_keyboard_markup.h"
inline_keyboard_markup_t* instantiate_inline_keyboard_markup(int include_optional);



inline_keyboard_markup_t* instantiate_inline_keyboard_markup(int include_optional) {
  inline_keyboard_markup_t* inline_keyboard_markup = NULL;
  if (include_optional) {
    inline_keyboard_markup = inline_keyboard_markup_create(
      list_createList()
    );
  } else {
    inline_keyboard_markup = inline_keyboard_markup_create(
      list_createList()
    );
  }

  return inline_keyboard_markup;
}


#ifdef inline_keyboard_markup_MAIN

void test_inline_keyboard_markup(int include_optional) {
    inline_keyboard_markup_t* inline_keyboard_markup_1 = instantiate_inline_keyboard_markup(include_optional);

	cJSON* jsoninline_keyboard_markup_1 = inline_keyboard_markup_convertToJSON(inline_keyboard_markup_1);
	printf("inline_keyboard_markup :\n%s\n", cJSON_Print(jsoninline_keyboard_markup_1));
	inline_keyboard_markup_t* inline_keyboard_markup_2 = inline_keyboard_markup_parseFromJSON(jsoninline_keyboard_markup_1);
	cJSON* jsoninline_keyboard_markup_2 = inline_keyboard_markup_convertToJSON(inline_keyboard_markup_2);
	printf("repeating inline_keyboard_markup:\n%s\n", cJSON_Print(jsoninline_keyboard_markup_2));
}

int main() {
  test_inline_keyboard_markup(1);
  test_inline_keyboard_markup(0);

  printf("Hello world \n");
  return 0;
}

#endif // inline_keyboard_markup_MAIN
#endif // inline_keyboard_markup_TEST
