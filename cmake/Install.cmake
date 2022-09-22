include(GNUInstallDirs)

install(
  TARGETS cliparse
  EXPORT WebArxLibs
  LIBRARY DESTINATION ${CMAKE_INSTALL_PREFIX}/lib/webarx
  ARCHIVE DESTINATION ${CMAKE_INSTALL_PREFIX}/lib/webarx
  PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/webarx)

install(
  EXPORT WebArxLibs
  FILE WebArxLibs.cmake
  NAMESPACE WebArx::
  DESTINATION ${CMAKE_INSTALL_PREFIX}/lib/cmake/webarx)

install(FILES "WebArxConfig.cmake"
        DESTINATION ${CMAKE_INSTALL_PREFIX}/lib/cmake/webarx)
