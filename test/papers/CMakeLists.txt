set(TARGET_LINK_TO_TEST ${PROJECT_NAME}-papers tinyxml2
                        ${PROJECT_NAME}-cliparse ${PROJECT_NAME}-query)
add_boost_test(papers_test.cpp "${TARGET_LINK_TO_TEST}")
