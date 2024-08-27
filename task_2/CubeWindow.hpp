#ifndef CUBEWINDOW_HPP
#define CUBEWINDOW_HPP
#include "openglwindow.h"
#include "cube.h"
#include <QOpenGLShaderProgram>
#include <QScreen>
#include <QVector2D>
#include <QVector3D>
#include <QQuaternion>
#include <QColorDialog>
#include <QOpenGLWidget>
#include <QBasicTimer>


class CubeWindow : public OpenGLWindow
{
    Q_OBJECT
public:
    using OpenGLWindow::OpenGLWindow;
    void create_cube(int n_triangles, float square);
    void initialize() override;
    void render() override;

    void mousePressEvent(QMouseEvent *e) override;
    void mouseReleaseEvent(QMouseEvent *e) override;
    void timerEvent(QTimerEvent *e) override;
    void keyPressEvent(QKeyEvent *e) override;


private:
    GLint posAttr = 0;
    GLint colAttr = 0;
    GLint matrixUniform = 0;
    GLint morphUniform_ = 0;
    std::vector<coordinate> _vector;
    QBasicTimer timer;
    float morph_parameter = 0.0f;
    QVector2D mousePressPosition;
    QVector3D rotationAxis = {0,1,0};
    QQuaternion rotation;
    qreal angularSpeed = 0;

    QVector4D color{1.0f, 1.0f, 1.0f, 1.2f};


    QOpenGLShaderProgram *m_program = nullptr;
    int m_frame = 0;
};


#endif // CUBEWINDOW_HPP
