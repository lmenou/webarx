include(GNUInstallDirs)

# install(
#   TARGETS query
#   EXPORT ${PROJECT_NAME}
#   LIBRARY COMPONENT runtime
#   PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/webarx
#                 COMPONENT runtime)
# 
# install(
#   EXPORT ${PROJECT_NAME}
#   DESTINATION ${CMAKE_INSTALL_LIBDIR}/webarx/cmake
#   NAMESPACE webarx::
#   COMPONENT runtime)

install(TARGETS ${PROJECT_NAME} RUNTIME COMPONENT runtime)
