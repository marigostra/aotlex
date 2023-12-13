
set(my_SOURCES
AncodePattern.cpp
BigramsReader.cpp
Homonym.cpp
LemWord.cpp
MorphXmlToken.cpp
PlmLine.cpp
gra_descr.cpp
rus_numerals.cpp
utilit.cpp
)

add_library(aot_common  ${my_SOURCES})

target_link_libraries(aot_common 
    iconv_subset
)
