#ifndef CUBEEFFECT_H
#define CUBEEFFECT_H

#include <QDebug>
#include <string>

class CubeEffect
{
public:
    enum CubeEffectType{
        ShutDownEffect,
        BlinkEffect,
        PlainBoingEffect,
        RainEffect,
        RandomFillerEffect,
        BoxsideRandsend,
        PreviewEffect
    };

    CubeEffect(std::string name, int type, std::string code);
    std::string getName();
    std::string getCode();
    int getType();

    static CubeEffect* Create(CubeEffectType);

private:

    std::string name;
    std::string code;
    int type;
};

#endif // CUBEEFFECT_H
