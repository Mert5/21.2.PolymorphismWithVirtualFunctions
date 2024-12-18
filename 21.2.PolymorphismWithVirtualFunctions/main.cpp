#include <iostream>
#include "shape.h"
#include "oval.h"
#include "circle.h"

//  Reference => https://www.youtube.com/watch?v=8jLOx1hD3_o

void shape_draw(Shape *s){
    s->draw();
}

void draw_shape_ref(const Shape &s_r){
    s_r.draw();
}

int main(){

    Shape shape1{"Shape1"};
    //shape1.draw();

    Oval oval1{2.0,3.5,"Oval1"};
    //oval1.draw();

    Circle circle1(3.3, "Circle");
    //circle1.draw();

    
    // Base pointers
    Shape *shape_ptr = &shape1; 
    //shape_ptr->draw();       

    shape_ptr = &oval1;
    //shape_ptr->draw();    // Oval::draw()

    shape_ptr = &circle1;
    //shape_ptr->draw();    // Circle::draw()
    
    
    // Base references  => // you can not rebind references!!!
    //Shape& shape_ref = circle1;      
    //shape_ref.draw();

    //std::cout << "---------------" << std::endl;
    
    // Drawing shapes
    //shape_draw(&oval1);
    //draw_shape_ref(circle1);

    
    // Raw pointers
    shape_ptr = &oval1;
    //shape_ptr->get_x_rad(); // will give you compiler error
                            // even if you make it public, if it is not virtual, that's not work
                            // because Shape class does not have that method

    
    /*
    // Shapes stored in collections - Bad design - Dirty
    Circle circle_collection[]{circle1, Circle(10.2,"Circle2"), Circle(20.3,"Circle3")};
    Oval oval_collection[]{oval1, Oval(21.5,52.3,"Oval2")};
    // More arrays as you have more types, right?
    */

    // Shapes stored in collections - Good one
    Shape *shape_colletion[]{&shape1,&oval1,&circle1};

    for(Shape *s_ptr : shape_colletion){
        s_ptr->draw();
    }
    
    return 0;
}