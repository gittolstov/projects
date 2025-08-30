#ifndef TESTS_H
#define TESTS_H

/*!
*	unit test for nRoots, prints errors. SIZE max tests
*	\param[in] address - string with address to file with testdata
*/
void testNRoots(const char address[]);
/*!
*	reads single Testdata structure
*	\param[in] stream where the data is taken from
*	\param[out] Testdata structure with numbers or NAN if EOF
*	\returns 1 if successful, else 0
*/
int readTestdata(FILE *stream, struct Testdata *toChange);
/*!
*	performs one test of nRoots function
*	\param[in] Testdata structure containing test data, inputs, wanted outputs
*	\return 1 if no errors were found, 0 if there was an error
*/
int singularTestNRoots(struct Testdata *data);
#endif