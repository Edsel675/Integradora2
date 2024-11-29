add_test([=[BasicTest.PointCreation]=]  /Users/edselcisneros/Documents/Integradora2/build/network_tests [==[--gtest_filter=BasicTest.PointCreation]==] --gtest_also_run_disabled_tests)
set_tests_properties([=[BasicTest.PointCreation]=]  PROPERTIES WORKING_DIRECTORY /Users/edselcisneros/Documents/Integradora2/build SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==])
set(  network_tests_TESTS BasicTest.PointCreation)
