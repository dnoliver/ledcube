#ifndef CUBEEFFECTLUNCHERWIDGET_H
#define CUBEEFFECTLUNCHERWIDGET_H

#include <QWidget>
#include "cubeeffect.h"

namespace Ui {
class CubeEffectLuncherWidget;
}

class CubeEffectLuncherWidget : public QWidget
{
    Q_OBJECT

public:
    explicit CubeEffectLuncherWidget(QWidget *parent = 0);
    ~CubeEffectLuncherWidget();

private:
    Ui::CubeEffectLuncherWidget *ui;

    std::list<CubeEffect*> effects;
};

#endif // CUBEEFFECTLUNCHERWIDGET_H
