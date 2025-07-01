#ifndef location_address_TEST
#define location_address_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define location_address_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/location_address.h"
location_address_t* instantiate_location_address(int include_optional);



location_address_t* instantiate_location_address(int include_optional) {
  location_address_t* location_address = NULL;
  if (include_optional) {
    location_address = location_address_create(
      "0",
      "0",
      "0",
      "0"
    );
  } else {
    location_address = location_address_create(
      "0",
      "0",
      "0",
      "0"
    );
  }

  return location_address;
}


#ifdef location_address_MAIN

void test_location_address(int include_optional) {
    location_address_t* location_address_1 = instantiate_location_address(include_optional);

	cJSON* jsonlocation_address_1 = location_address_convertToJSON(location_address_1);
	printf("location_address :\n%s\n", cJSON_Print(jsonlocation_address_1));
	location_address_t* location_address_2 = location_address_parseFromJSON(jsonlocation_address_1);
	cJSON* jsonlocation_address_2 = location_address_convertToJSON(location_address_2);
	printf("repeating location_address:\n%s\n", cJSON_Print(jsonlocation_address_2));
}

int main() {
  test_location_address(1);
  test_location_address(0);

  printf("Hello world \n");
  return 0;
}

#endif // location_address_MAIN
#endif // location_address_TEST
