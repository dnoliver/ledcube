#include "cubeeffect.h"

CubeEffect::CubeEffect(std::string name, int type, std::string code){
    this->name = name;
    this->type = type;
    this->code = code;
}

std::string CubeEffect::getName(){
    return this->name;
}

std::string CubeEffect::getCode(){
    return this->code;
}

int CubeEffect::getType(){
    return this->type;
}

CubeEffect* CubeEffect::Create(CubeEffectType type){
    switch(type){
        case CubeEffect::ShutDownEffect:
            return new CubeEffect("Shutdown",type,"0");
            break;
        case CubeEffect::BlinkEffect:
            return new CubeEffect("Blink",type,"1");
            break;
        case CubeEffect::PlainBoingEffect:
            return new CubeEffect("PlainBoing",type,"2");
            break;
        case CubeEffect::RainEffect:
            return new CubeEffect("Rain",type,"3");
            break;
        case CubeEffect::RandomFillerEffect:
            return new CubeEffect("RandomFiller",type,"4");
            break;
        case CubeEffect::BoxsideRandsend:
            return new CubeEffect("BoxsideRandsend",type,"5");
            break;
        case CubeEffect::PreviewEffect:
            return new CubeEffect("Preview",type,"6");
            break;
        default:
            throw "Unknown CubeEffectType";
    }
}
