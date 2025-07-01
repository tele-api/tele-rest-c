#ifndef pre_checkout_query_TEST
#define pre_checkout_query_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define pre_checkout_query_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/pre_checkout_query.h"
pre_checkout_query_t* instantiate_pre_checkout_query(int include_optional);

#include "test_user.c"
#include "test_order_info.c"


pre_checkout_query_t* instantiate_pre_checkout_query(int include_optional) {
  pre_checkout_query_t* pre_checkout_query = NULL;
  if (include_optional) {
    pre_checkout_query = pre_checkout_query_create(
      "0",
       // false, not to have infinite recursion
      instantiate_user(0),
      "0",
      56,
      "0",
      "0",
       // false, not to have infinite recursion
      instantiate_order_info(0)
    );
  } else {
    pre_checkout_query = pre_checkout_query_create(
      "0",
      NULL,
      "0",
      56,
      "0",
      "0",
      NULL
    );
  }

  return pre_checkout_query;
}


#ifdef pre_checkout_query_MAIN

void test_pre_checkout_query(int include_optional) {
    pre_checkout_query_t* pre_checkout_query_1 = instantiate_pre_checkout_query(include_optional);

	cJSON* jsonpre_checkout_query_1 = pre_checkout_query_convertToJSON(pre_checkout_query_1);
	printf("pre_checkout_query :\n%s\n", cJSON_Print(jsonpre_checkout_query_1));
	pre_checkout_query_t* pre_checkout_query_2 = pre_checkout_query_parseFromJSON(jsonpre_checkout_query_1);
	cJSON* jsonpre_checkout_query_2 = pre_checkout_query_convertToJSON(pre_checkout_query_2);
	printf("repeating pre_checkout_query:\n%s\n", cJSON_Print(jsonpre_checkout_query_2));
}

int main() {
  test_pre_checkout_query(1);
  test_pre_checkout_query(0);

  printf("Hello world \n");
  return 0;
}

#endif // pre_checkout_query_MAIN
#endif // pre_checkout_query_TEST
