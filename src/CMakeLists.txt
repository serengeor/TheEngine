cmake_minimum_required (VERSION 2.6)
set(Python_ADDITIONAL_VERSIONS 3.4)
project (ENGINE)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -w -Wfatal-errors -std=c++11")


set(PROJECT_PATH "" CACHE FILEPATH "Path to root directory of project")
set(ENGINE_PATH "${ENGINE_SOURCE_DIR}" )
set(LIB_PATH "${PROJECT_PATH}/libs/" )
set(LIBBIN_PATH "${PROJECT_PATH}/libs/linux" )

#libraries
find_package(PythonLibs REQUIRED)
message(${PYTHON_INCLUDE_DIRS})
message(${PYTHON_LIBRARIES})

include_directories(
	#libraries
	"${LIB_PATH}/boost/"
	"${LIB_PATH}/freetype/include"
	"${LIB_PATH}/glfw/include"
	"${LIB_PATH}/glm"
	"${LIB_PATH}/glad/include"
	"${LIB_PATH}/physfs"
	"${LIB_PATH}/tinyxml2/src"
	"${LIB_PATH}/freetype2/include"
	"${LIB_PATH}/libsigc++"
	"${LIB_PATH}/libccd"
	"${LIB_PATH}/stb_image"
	"${PYTHON_INCLUDE_DIRS}"

	#engine includes
	"${ENGINE_SOURCE_DIR}"
	"${ENGINE_SOURCE_DIR}/application"
	"${ENGINE_SOURCE_DIR}/core"
	"${ENGINE_SOURCE_DIR}/opengl"
	"${ENGINE_SOURCE_DIR}/gui"
	"${ENGINE_SOURCE_DIR}/resources"
	"${ENGINE_SOURCE_DIR}/scenegraph"
	"${ENGINE_SOURCE_DIR}/utility"
)

add_library(engine STATIC 

./opengl/material/ShaderBinding.cpp
./opengl/material/TBindingValue.cpp
./opengl/material/Shader.cpp
./opengl/material/IRenderObject.cpp
./opengl/material/Material.cpp
./opengl/IBufferObject.cpp
./opengl/BufferObject.cpp
./opengl/RenderStateManager.cpp
./opengl/Camera.cpp
./opengl/RenderBufferObject.cpp
./opengl/OpenGLExtensionLoader.cpp
./opengl/Mesh.cpp
./opengl/AABB.cpp
./opengl/RenderObjectManager.cpp
./opengl/Texture.cpp
./opengl/GLObject.cpp
./opengl/FrameBufferObject.cpp
./opengl/geometry/CubeMesh.cpp
./opengl/geometry/Quad.cpp
./opengl/geometry/GridMesh.cpp
./utility/SimplexNoise.cpp
./utility/Util.cpp
./utility/Helpers.cpp
./utility/Timer.cpp
./utility/Logger.cpp
./Precomp.cpp
./core/FileSystem.cpp
./core/VarGroup.cpp
./core/Var.cpp
./core/VarJsonReader.cpp
./core/File.cpp
./gui/font_rendering/FontFamily.cpp
./gui/font_rendering/Font.cpp
./gui/font_rendering/FontRenderer.cpp
./gui/GUIEnvironment.cpp
./gui/GUIImage.cpp
./gui/GUICheckbox.cpp
./gui/custom_elements/ToggleGroup.cpp
./gui/custom_elements/GUIColorPicker.cpp
./gui/GUIEditBox.cpp
./gui/GUISlider.cpp
./gui/GUIButton.cpp
./gui/GUIElement.cpp
./gui/GUISkin.cpp
./gui/GUIWindow.cpp
./gui/GUIStaticText.cpp
./gui/GUIPane.cpp
./application/AppContext.cpp
./application/ApplicationLauncher.cpp
./application/Window.cpp
./application/SettingsManager.cpp
./application/InputHandler.cpp
./application/Application.cpp
./resources/PNGLoader.cpp
./resources/ResourceManager.cpp
./resources/MeshLoader.cpp
./resources/Image.cpp
./resources/ImageLoader.cpp
./resources/ShaderLoader.cpp
./resources/ResourceCache.cpp
./resources/TGAloader.cpp
./resources/IQMLoader.cpp
./resources/IImageLoader.cpp
./resources/IMeshLoader.cpp

)


