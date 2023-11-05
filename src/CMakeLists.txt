add_subdirectory(FQHUtils)

set(PROJECT_SHORTNAME "Fast-Quick-Hull")

MakeLibrary(${PROJECT_SHORTNAME} header)

target_link_libraries(${PROJECT_SHORTNAME} PUBLIC
Hull
)

find_package(OpenMP)
if(OpenMP_CXX_FOUND)
	target_link_libraries(${PROJECT_SHORTNAME} PRIVATE OpenMP::OpenMP_CXX)
endif()