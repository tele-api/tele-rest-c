#ifndef paid_message_price_changed_TEST
#define paid_message_price_changed_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define paid_message_price_changed_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/paid_message_price_changed.h"
paid_message_price_changed_t* instantiate_paid_message_price_changed(int include_optional);



paid_message_price_changed_t* instantiate_paid_message_price_changed(int include_optional) {
  paid_message_price_changed_t* paid_message_price_changed = NULL;
  if (include_optional) {
    paid_message_price_changed = paid_message_price_changed_create(
      56
    );
  } else {
    paid_message_price_changed = paid_message_price_changed_create(
      56
    );
  }

  return paid_message_price_changed;
}


#ifdef paid_message_price_changed_MAIN

void test_paid_message_price_changed(int include_optional) {
    paid_message_price_changed_t* paid_message_price_changed_1 = instantiate_paid_message_price_changed(include_optional);

	cJSON* jsonpaid_message_price_changed_1 = paid_message_price_changed_convertToJSON(paid_message_price_changed_1);
	printf("paid_message_price_changed :\n%s\n", cJSON_Print(jsonpaid_message_price_changed_1));
	paid_message_price_changed_t* paid_message_price_changed_2 = paid_message_price_changed_parseFromJSON(jsonpaid_message_price_changed_1);
	cJSON* jsonpaid_message_price_changed_2 = paid_message_price_changed_convertToJSON(paid_message_price_changed_2);
	printf("repeating paid_message_price_changed:\n%s\n", cJSON_Print(jsonpaid_message_price_changed_2));
}

int main() {
  test_paid_message_price_changed(1);
  test_paid_message_price_changed(0);

  printf("Hello world \n");
  return 0;
}

#endif // paid_message_price_changed_MAIN
#endif // paid_message_price_changed_TEST
