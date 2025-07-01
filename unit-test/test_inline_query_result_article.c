#ifndef inline_query_result_article_TEST
#define inline_query_result_article_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define inline_query_result_article_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/inline_query_result_article.h"
inline_query_result_article_t* instantiate_inline_query_result_article(int include_optional);

#include "test_input_message_content.c"
#include "test_inline_keyboard_markup.c"


inline_query_result_article_t* instantiate_inline_query_result_article(int include_optional) {
  inline_query_result_article_t* inline_query_result_article = NULL;
  if (include_optional) {
    inline_query_result_article = inline_query_result_article_create(
      "article",
      "0",
      "0",
      null,
       // false, not to have infinite recursion
      instantiate_inline_keyboard_markup(0),
      "0",
      "0",
      "0",
      56,
      56
    );
  } else {
    inline_query_result_article = inline_query_result_article_create(
      "article",
      "0",
      "0",
      null,
      NULL,
      "0",
      "0",
      "0",
      56,
      56
    );
  }

  return inline_query_result_article;
}


#ifdef inline_query_result_article_MAIN

void test_inline_query_result_article(int include_optional) {
    inline_query_result_article_t* inline_query_result_article_1 = instantiate_inline_query_result_article(include_optional);

	cJSON* jsoninline_query_result_article_1 = inline_query_result_article_convertToJSON(inline_query_result_article_1);
	printf("inline_query_result_article :\n%s\n", cJSON_Print(jsoninline_query_result_article_1));
	inline_query_result_article_t* inline_query_result_article_2 = inline_query_result_article_parseFromJSON(jsoninline_query_result_article_1);
	cJSON* jsoninline_query_result_article_2 = inline_query_result_article_convertToJSON(inline_query_result_article_2);
	printf("repeating inline_query_result_article:\n%s\n", cJSON_Print(jsoninline_query_result_article_2));
}

int main() {
  test_inline_query_result_article(1);
  test_inline_query_result_article(0);

  printf("Hello world \n");
  return 0;
}

#endif // inline_query_result_article_MAIN
#endif // inline_query_result_article_TEST
