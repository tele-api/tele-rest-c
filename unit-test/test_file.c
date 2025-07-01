#ifndef file_TEST
#define file_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define file_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/file.h"
file_t* instantiate_file(int include_optional);



file_t* instantiate_file(int include_optional) {
  file_t* file = NULL;
  if (include_optional) {
    file = file_create(
      "0",
      "0",
      56,
      "0"
    );
  } else {
    file = file_create(
      "0",
      "0",
      56,
      "0"
    );
  }

  return file;
}


#ifdef file_MAIN

void test_file(int include_optional) {
    file_t* file_1 = instantiate_file(include_optional);

	cJSON* jsonfile_1 = file_convertToJSON(file_1);
	printf("file :\n%s\n", cJSON_Print(jsonfile_1));
	file_t* file_2 = file_parseFromJSON(jsonfile_1);
	cJSON* jsonfile_2 = file_convertToJSON(file_2);
	printf("repeating file:\n%s\n", cJSON_Print(jsonfile_2));
}

int main() {
  test_file(1);
  test_file(0);

  printf("Hello world \n");
  return 0;
}

#endif // file_MAIN
#endif // file_TEST
