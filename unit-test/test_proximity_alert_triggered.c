#ifndef proximity_alert_triggered_TEST
#define proximity_alert_triggered_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define proximity_alert_triggered_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/proximity_alert_triggered.h"
proximity_alert_triggered_t* instantiate_proximity_alert_triggered(int include_optional);

#include "test_user.c"
#include "test_user.c"


proximity_alert_triggered_t* instantiate_proximity_alert_triggered(int include_optional) {
  proximity_alert_triggered_t* proximity_alert_triggered = NULL;
  if (include_optional) {
    proximity_alert_triggered = proximity_alert_triggered_create(
       // false, not to have infinite recursion
      instantiate_user(0),
       // false, not to have infinite recursion
      instantiate_user(0),
      56
    );
  } else {
    proximity_alert_triggered = proximity_alert_triggered_create(
      NULL,
      NULL,
      56
    );
  }

  return proximity_alert_triggered;
}


#ifdef proximity_alert_triggered_MAIN

void test_proximity_alert_triggered(int include_optional) {
    proximity_alert_triggered_t* proximity_alert_triggered_1 = instantiate_proximity_alert_triggered(include_optional);

	cJSON* jsonproximity_alert_triggered_1 = proximity_alert_triggered_convertToJSON(proximity_alert_triggered_1);
	printf("proximity_alert_triggered :\n%s\n", cJSON_Print(jsonproximity_alert_triggered_1));
	proximity_alert_triggered_t* proximity_alert_triggered_2 = proximity_alert_triggered_parseFromJSON(jsonproximity_alert_triggered_1);
	cJSON* jsonproximity_alert_triggered_2 = proximity_alert_triggered_convertToJSON(proximity_alert_triggered_2);
	printf("repeating proximity_alert_triggered:\n%s\n", cJSON_Print(jsonproximity_alert_triggered_2));
}

int main() {
  test_proximity_alert_triggered(1);
  test_proximity_alert_triggered(0);

  printf("Hello world \n");
  return 0;
}

#endif // proximity_alert_triggered_MAIN
#endif // proximity_alert_triggered_TEST
