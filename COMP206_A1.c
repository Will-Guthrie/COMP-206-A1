#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void badFile () {
    printf("Error: bad file");
    exit(-1);
}

void badValue () {
    printf("Error: bad float arg");
    exit(-1);
}

int main (int argc, char *argv[]) {
    if (argc != 4) {
        printf("Error: please submit exactly three arguments");
        exit(-1);
    }

    FILE* shapeTemplate = fopen(argv[1], "r");
    //FILE* shapeTemplate = fopen("shape_template.txt", "r");
    if (shapeTemplate == NULL) {
        badFile();
    //FIXEME: Need more checking for bad file
    }

    double paraA = 0.0, paraB = 0.0;

    //Rejecting 0.0 for failed atof and input of 0.0
    paraA = atof(argv[2]);
    if (paraA == 0.0) {
        badValue();
    }

    paraB = atof(argv[3]);
    if (paraA == 0.0) {
        badValue();
    }

    double a = 0.0, b = 0.0;
    int testCounter = 0;
    a = atof(argv[2]);
    b = atof(argv[3]);
    char templateLines[300];
    char* aTag = "#A#", *bTag = "#B#";

    while(fgets(templateLines, 300, shapeTemplate) != NULL) {
        if (strstr(templateLines, aTag)) {
            testCounter++;
        }
        else if (strstr(templateLines, bTag)) {
            testCounter++;
        }
    }

    if (testCounter != 2)
        badFile();

    while(fgets(templateLines, 100, shapeTemplate) != NULL) {
        if (strstr(templateLines, aTag)) {
            printf("%s\n", a);
        }

        else if (strstr(templateLines, bTag)) {
            printf("%s\n", b);
        }

        else
            printf("%s", templateLines);
    }

    fclose(shapeTemplate);

return 0;
}
