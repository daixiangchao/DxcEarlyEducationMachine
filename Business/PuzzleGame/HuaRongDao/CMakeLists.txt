include_directories(
	${PROJECT_SOURCE_DIR}
	${PROJECT_BINARY_DIR}
)
#aux_source_directory():Save name to DIR_BUSINESS_PUZZLEGAME_HUARONGDAO varible
aux_source_directory(. DIR_BUSINESS_PUZZLEGAME_HUARONGDAO)
#add_library():The main function of this command is generate a linked file from a specified sourse file and add it to the project.  
#Generate Link Library
add_library(Business_PuzzleGame_HuaRongDao OBJECT ${DIR_BUSINESS_PUZZLEGAME_HUARONGDAO})