target_sources(sort
	PRIVATE
		print.cpp
		sort.cpp
		print.hpp
		sort.hpp
)

target_include_directories(sort
	PRIVATE
		"${PROJECT_SOURCE_DIR}/src"
)