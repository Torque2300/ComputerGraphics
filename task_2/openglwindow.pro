include(openglwindow.pri)

SOURCES += \
    CubeWindow.cpp \
    main.cpp

target.path = $$[QT_INSTALL_EXAMPLES]/opengl/openglwindow
INSTALLS += target
QT += widgets
QT += opengl
QT += core
LIBS += -lopengl32
QT += openglwidgets
HEADERS += \
    CubeWindow.hpp \
    cube.h

DISTFILES += \
    VertexShader.vsh \
    shaders/VertexShader.vsh
