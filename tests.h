#ifndef TESTS_H
#define TESTS_H

void testNRoots(char address[]);
int readTestdata(FILE *stream, struct Testdata *toChange);
int singularTestNRoots(struct Testdata *data);
#endif