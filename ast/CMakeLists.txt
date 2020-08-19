set(HEADER_FILES
        Node.h
        Program.h

        Statement.h
        Let.h

        Expression.h
        )

set(SOURCE_FILES
        Node.cpp
        Program.cpp

        Statement.cpp
        Let.cpp

        Expression.cpp
        )

add_library(ast STATIC ${SOURCE_FILES} ${HEADER_FILES})