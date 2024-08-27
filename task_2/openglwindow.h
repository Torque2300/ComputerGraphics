// Copyright (C) 2016 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR BSD-3-Clause

#include <QWindow>
#include <memory>

#include <QOpenGLContext>
#include <QOpenGLFunctions>
#include <QOpenGLPaintDevice>

//! [1]
class OpenGLWindow : public QWindow, protected QOpenGLFunctions
{
    Q_OBJECT
public:

    explicit OpenGLWindow(QWindow *parent = nullptr);

    virtual void render(const QPainter &painter);
    virtual void render();

    virtual void initialize();

    void setAnimating(bool animating);

public slots:

    void renderLater();

    void renderNow();

protected:

    bool event(QEvent *event) override;

    void exposeEvent(QExposeEvent *event) override;

private:

    bool m_animating = false;
    std::unique_ptr<QOpenGLContext> m_context = nullptr;
    std::unique_ptr<QOpenGLPaintDevice> m_device = nullptr;

};
//! [1]

