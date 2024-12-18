#ifndef SHAPE_H
#define SHAPE_H

#include <string>
#include <string_view>
#include <iostream>

class Shape{
    public:
        Shape() = default;
        Shape(std::string_view description);
        ~Shape();

        virtual void draw() const{  // Dynamic binding
                    // with dynamic binding, we tell the compiler to look at not the type of base pointer 
                    // but to type of actual object that the pointer managing
            std::cout << "Shape::draw() called. Drawing " << m_description << std::endl;
        }

    protected:
        std::string m_description{""};
};

#endif  // SHAPE_H