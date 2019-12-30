//
// TODO: don't use pointer, use reference
//  TODO: not use new, delete
//

#include <iostream>
#include <cstdlib>

// interface
class IDrawStrategy {
public:
    virtual void draw() const = 0;
};

class Grapher {
public:
    Grapher(IDrawStrategy* drawStrategy = nullptr) : _drawStrategy(drawStrategy) {}

public:
    void drawShape() const;
    void setShape(IDrawStrategy* drawStrategy);

protected:
    IDrawStrategy* _drawStrategy;
};

// 因為給constrcutor的drawStrategy有相同介面，
// 必有實作draw()，因此不必修改Grapherc
void Grapher::drawShape() const {
    if (_drawStrategy)
        _drawStrategy->draw();
}

void Grapher::setShape(IDrawStrategy* drawStrategy){
    this->_drawStrategy = drawStrategy;
}

// 繼承自interface，而非Grapher
class Triangle : public IDrawStrategy {
public:
    void draw() const;
};

void Triangle::draw() const{
    std::cout<<"draw triangle" << std::endl;
}

// 繼承自interface，而非Grapher
class Circle : public IDrawStrategy {
public:
    void draw() const;
};

void Circle::draw() const{
    std::cout<<"draw circle" << std::endl;
}

// 繼承自interface，而非Grapher
class Square : public IDrawStrategy {
public:
    void draw() const;
};

void Square::draw() const{
    std::cout<<"draw square" << std::endl;
}


int main() {
    IDrawStrategy* obj= new Square();
    Grapher grapher(obj);
    grapher.drawShape();

    IDrawStrategy* obj2= new Circle();
    grapher.setShape(obj2);
    grapher.drawShape();

    delete obj;
    delete obj2;
    return 0;
}