if(PROJECT_SOURCE_DIR STREQUAL PROJECT_BINARY_DIR)
  message(
    FATAL_ERROR
      "\n"
      "In-source builds are not allowed.\n"
      "Instead, provide the path to the build tree from the root of the project:\n"
      "cmake -B build -S .\n"
      "\n"
      "To remove files you accidentally created, execute:\n"
      "rm -rf CMakeFiles CMakeCache.txt\n")
endif()
