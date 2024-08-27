#include <stdio.h>
#include "CubeWindow.hpp"
#include <QMouseEvent>
#include <QScreen>
#include <iostream>


void CubeWindow::create_cube(int n_triangles, float square)
{
    Cube tmp(n_triangles, square);
    _vector = tmp.create_cube();
}


void CubeWindow::initialize()
{
    m_program = new QOpenGLShaderProgram(this);
    m_program->addShaderFromSourceFile(QOpenGLShader::Vertex, "D:\\Qt_tasks\\task_2\\shaders\\VertexShader.vsh");
    m_program->addShaderFromSourceFile(QOpenGLShader::Fragment, "D:\\Qt_tasks\\task_2\\shaders\\FragmentShader.fsh");
    m_program->link();
    posAttr = m_program->attributeLocation("posAttr");
    Q_ASSERT(posAttr != -1);
    colAttr = m_program->uniformLocation("color");
    Q_ASSERT(colAttr != -1);
    matrixUniform = m_program->uniformLocation("matrix");
    Q_ASSERT(matrixUniform != -1);
    morphUniform_ = m_program->uniformLocation("morph");
    Q_ASSERT(morphUniform_ != -1);
}


void CubeWindow::render()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    const qreal retinaScale = devicePixelRatio();
    glViewport(0, 0, width() * retinaScale, height() * retinaScale);
    timer.start(12, this);
    m_program->bind();

    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);

    create_cube(40,1);
    GLfloat vertices[_vector.size()*3];
    GLfloat colors[_vector.size()*3];
    for (int i = 0; i < static_cast<int>(_vector.size()); i++)
    {
        vertices[i*3] = _vector[i].get_x()-0.5;
        vertices[i*3+1] = _vector[i].get_y()-0.5;
        vertices[i*3+2] = _vector[i].get_z()-0.5;
    }


    QMatrix4x4 matrix;
    matrix.perspective(60.0f, 4.0f / 3.0f, 0.1f, 100.0f);
    matrix.translate(0, 0, -4);
    matrix.rotate(45.0f * m_frame / screen()->refreshRate(), rotationAxis);

    m_program->setUniformValue(matrixUniform, matrix);
    m_program->setUniformValue(colAttr, color);
    m_program->setUniformValue(morphUniform_, morph_parameter);

    glVertexAttribPointer(posAttr, 3, GL_FLOAT, GL_FALSE, 0, vertices);
    glVertexAttribPointer(colAttr, 3, GL_FLOAT, GL_FALSE, 0, colors);

    glEnableVertexAttribArray(posAttr);
    glEnableVertexAttribArray(colAttr);

    glDrawArrays(GL_TRIANGLES, 0, _vector.size());

    glDisableVertexAttribArray(posAttr);
    glDisableVertexAttribArray(colAttr);

    m_program->release();

    ++m_frame;
}


void CubeWindow::mousePressEvent(QMouseEvent *e)
{
    mousePressPosition = QVector2D(e->position());
}


void CubeWindow::mouseReleaseEvent(QMouseEvent *e)
{
    QVector2D diff = QVector2D(e->position()) - mousePressPosition;

    QVector3D n = QVector3D(diff.y(), diff.x(), 0.0).normalized();

    qreal acc = diff.length() / 100.0;

    rotationAxis = (rotationAxis * angularSpeed + n * acc).normalized();

    angularSpeed += acc;
}


void CubeWindow::timerEvent(QTimerEvent *)
{
    angularSpeed *= 0.99;

    if (angularSpeed < 0.01) {
        angularSpeed = 0.0;
    } else {
        rotation = QQuaternion::fromAxisAndAngle(rotationAxis, angularSpeed) * rotation;
    }
}


void CubeWindow::keyPressEvent(QKeyEvent *e) {
    if (e->key() == Qt::Key_C)
    {
        const auto chosen_color = QColorDialog::getColor();
        color = QVector4D(chosen_color.red() / 255.0f, chosen_color.green() / 255.0f, chosen_color.blue() / 255.0f, 1.2f);
    }
    if (e->key() == Qt::Key_1)
    {
        if(morph_parameter + 0.1f <= 1.0f)
        {
            morph_parameter += 0.02f;
        }
    }
    if (e->key() == Qt::Key_2)
    {
        if (morph_parameter - 0.1f >= 0.0f)
        {
            morph_parameter -= 0.02f;
        }
    }
}
