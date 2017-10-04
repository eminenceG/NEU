## Unit Testing and Document Generation
### Creating Unit Tests
- Separating code into separate modules by functionality simplifies creating separate unit test modules for them.
- Using unit test framework automates unit tests for a number of modules and reporting results.

#### General Usage
1. Write functions for tests (and suite init/cleanup if necessary).
2. Initialize the test registry - CU_initialize_registry()
3. Add suites to the test registry - CU_add_suite()
4. Add tests to the suites - CU_add_test()
5. Run tests using an appropriate interface, e.g. CU_console_run_tests
6. Cleanup the test registry - CU_cleanup_registry

#### Writing CUnit Test Cases
##### Test Functions
A CUnit "test" is a C function having the signature:

	void test_func(void)

##### CUnit Assertions
CUnit provides a set of assertions for testing logical conditions. The success or failure of these assertions is tracked by the framework, and can be viewed when a test run is complete.

'xxx_FATAL' version of an assertion means the test function is aborted and returns immediately upon failure

	// Assert that expression is TRUE (non-zero)
	CU_ASSERT(int expression)
	CU_ASSERT_FATAL(int expression)
	CU_TEST(int expression)
	CU_TEST_FATAL(int expression)

	// Assert that value is TRUE (non-zero)
	CU_ASSERT_TRUE(value)
	CU_ASSERT_TRUE_FATAL(value)

	// Assert that value is FALSE (zero)
	CU_ASSERT_FALSE(value)
	CU_ASSERT_FALSE_FATAL(value)


#### The Test Registry
The test registry is the repository for suites and associated tests. CUnit maintains an active test registry which is updated when the user adds a suite or test. The suites in this active registry are the ones run when the user chooses to run all tests.
##### Initialization
The active CUnit test registry must be initialized before use. The user should call `CU_initialize_registry()` before calling any other CUnit functions. Failure to do so will likely result in a crash.
```
CU_ErrorCode CU_initialize_registry(void)
```
##### Cleanup
When testing is complete, the user should call this function to clean up and release memory used by the framework. This should be the last CUnit function called.
```
void CU_cleanup_registry(void)
```




#### Running Tests
CUnit supports running all tests in all registered suites, but individual tests or suites can also be run.

CUnit provides simplified user interfaces that handle the details of interaction with the framework.

##### Interface Automated
##### Interface Basic
Basic interface provides the most flexibility to clients desiring simplified access
- Non-interactive
- Results output to stdout
- Support running individual suites or tests
- Allows to control the type of output displayed during each run

```
/**
* Sets the basic run mode, which controls the output during test runs. Choices are:
* CU_BRM_NORMAL	 Failures and run summary are printed.
* CU_BRM_SILENT	 No output is printed except error messages.
* CU_BRM_VERBOSE	Maximum output of run details.
*/
void CU_basic_set_mode(CU_BasicRunMode mode)

/**
* Runs all tests in all registered suites.
* @return the 1st error code occurring during the test run.
*/
CU_ErrorCode CU_basic_run_tests(void)
```

##### Interface Console
##### Interface Curses
