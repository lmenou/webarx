set(TARGET_LINK_TO_TEST papers tinyxml2)
add_boost_test(papers_test.cpp "${TARGET_LINK_TO_TEST}")
