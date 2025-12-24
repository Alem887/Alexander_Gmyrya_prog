target_sources(${LIBRARY}
    PRIVATE 
        sort.cpp
    PUBLIC 
        sort.hpp
)

target_include_directories(${LIBRARY} 
	PUBLIC
		"${PROJECT_SOURCE_DIR}/src"
)