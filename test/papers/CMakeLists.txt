set(TARGET_LINK_TO_TEST ${PROJECT_NAME}-papers tinyxml2)
add_boost_test(papers_test.cpp "${TARGET_LINK_TO_TEST}")
