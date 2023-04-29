message("Finding physlaub")

set(FIND_PHYSLAUB_PATHS /Users/elaube/CLionProjects/physlaub/)

find_path(PHYSLAUB_INCLUDE_DIR physlaub.h PATHS ${FIND_PHYSLAUB_PATHS})

find_library(PHYSLAUB_LIBRARY NAMES physlaub PATH_SUFFIXES build PATHS ${FIND_PHYSLAUB_PATHS})