#ifndef reaction_type_paid_TEST
#define reaction_type_paid_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define reaction_type_paid_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/reaction_type_paid.h"
reaction_type_paid_t* instantiate_reaction_type_paid(int include_optional);



reaction_type_paid_t* instantiate_reaction_type_paid(int include_optional) {
  reaction_type_paid_t* reaction_type_paid = NULL;
  if (include_optional) {
    reaction_type_paid = reaction_type_paid_create(
      "paid"
    );
  } else {
    reaction_type_paid = reaction_type_paid_create(
      "paid"
    );
  }

  return reaction_type_paid;
}


#ifdef reaction_type_paid_MAIN

void test_reaction_type_paid(int include_optional) {
    reaction_type_paid_t* reaction_type_paid_1 = instantiate_reaction_type_paid(include_optional);

	cJSON* jsonreaction_type_paid_1 = reaction_type_paid_convertToJSON(reaction_type_paid_1);
	printf("reaction_type_paid :\n%s\n", cJSON_Print(jsonreaction_type_paid_1));
	reaction_type_paid_t* reaction_type_paid_2 = reaction_type_paid_parseFromJSON(jsonreaction_type_paid_1);
	cJSON* jsonreaction_type_paid_2 = reaction_type_paid_convertToJSON(reaction_type_paid_2);
	printf("repeating reaction_type_paid:\n%s\n", cJSON_Print(jsonreaction_type_paid_2));
}

int main() {
  test_reaction_type_paid(1);
  test_reaction_type_paid(0);

  printf("Hello world \n");
  return 0;
}

#endif // reaction_type_paid_MAIN
#endif // reaction_type_paid_TEST
