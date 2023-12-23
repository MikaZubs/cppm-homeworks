#include "0_Figure.h"
#include "ValError.h"


Figure::Figure():Figure(0) {
    setName("Фигура");
}

Figure::Figure(int n) {
    setShape(n);
    setName("Фигура");
    if (n != 0) {
        std::stringstream defstr;
        defstr << this -> getName() << " не создана. Причина - количество сторон должно равнятся \"0\" вместо \"" << this -> ShapeCount << "\"!\n";
        throw ValExcept(defstr.str());
    }
}

int Figure::getShapeCount() {
    return this->ShapeCount;
}
std::string Figure::getName() {
    return this->shapeName;
}

void Figure::displayName() {
    std::cout << this->getName() << ":" << std::endl;
};
void Figure::displayShapeCount() {
    std::cout << "Количество сторон: " << this->getShapeCount() << std::endl; 
};
void Figure::displaySide() {
    std::cout << "Стороны: ";
    for (int i = 0; i < this->getShapeCount(); ++i) {
        std::cout << sidesName[i] << "=" << *(this->sideCntr() + i) << " ";
    };
    std::cout << std::endl;
};
void Figure::displayAngle() {
    std::cout << "Углы: ";
    for (int i = 0; i < this->getShapeCount(); ++i) {
        std::cout << anglesName[i] << "=" << *(this->angleCntr() + i) << " ";
    };
};


void Figure::printInfo() {
    displayName();
    displayShapeCount();
    if (this->ShapeCount != 0) {
        displaySide();
        displayAngle();
    }
    std::cout << std::endl;
}

const int* Figure::sideCntr() {
    return nullptr;
}
const int* Figure::angleCntr() {
    return nullptr;
}

void Figure::setName(std::string _n) {
    this->shapeName = _n;
}
void Figure::setShape(int _s) {
    this->ShapeCount = _s;
}


char sidesName[4] = { 'a', 'b', 'c', 'd' };
char anglesName[4] = { 'A', 'B', 'C', 'D' };
int ShapeCount;
std::string shapeName;