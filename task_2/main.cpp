#include "CubeWindow.hpp"
#include <QApplication>
#include <QHBoxLayout>
#include <QSlider>
#include <QLabel>

int main(int argc, char **argv)
{
    QApplication app(argc, argv);

    QSurfaceFormat format;
    format.setSamples(16);

    CubeWindow window;
    window.setFormat(format);
    window.resize(1000, 640);
    window.show();
    window.setAnimating(true);

    return app.exec();
}
