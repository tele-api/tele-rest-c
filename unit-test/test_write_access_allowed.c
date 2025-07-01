#ifndef write_access_allowed_TEST
#define write_access_allowed_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define write_access_allowed_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/write_access_allowed.h"
write_access_allowed_t* instantiate_write_access_allowed(int include_optional);



write_access_allowed_t* instantiate_write_access_allowed(int include_optional) {
  write_access_allowed_t* write_access_allowed = NULL;
  if (include_optional) {
    write_access_allowed = write_access_allowed_create(
      1,
      "0",
      1
    );
  } else {
    write_access_allowed = write_access_allowed_create(
      1,
      "0",
      1
    );
  }

  return write_access_allowed;
}


#ifdef write_access_allowed_MAIN

void test_write_access_allowed(int include_optional) {
    write_access_allowed_t* write_access_allowed_1 = instantiate_write_access_allowed(include_optional);

	cJSON* jsonwrite_access_allowed_1 = write_access_allowed_convertToJSON(write_access_allowed_1);
	printf("write_access_allowed :\n%s\n", cJSON_Print(jsonwrite_access_allowed_1));
	write_access_allowed_t* write_access_allowed_2 = write_access_allowed_parseFromJSON(jsonwrite_access_allowed_1);
	cJSON* jsonwrite_access_allowed_2 = write_access_allowed_convertToJSON(write_access_allowed_2);
	printf("repeating write_access_allowed:\n%s\n", cJSON_Print(jsonwrite_access_allowed_2));
}

int main() {
  test_write_access_allowed(1);
  test_write_access_allowed(0);

  printf("Hello world \n");
  return 0;
}

#endif // write_access_allowed_MAIN
#endif // write_access_allowed_TEST
