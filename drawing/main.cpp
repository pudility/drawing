//
//  main.cpp
//  drawing
//
//  Created by Zoe IAMZOE.io on 1/15/18.
//  Copyright © 2018 Zoe IAMZOE.io. All rights reserved.
//

#include <iostream>
#include "app.hpp"

int main(int argc, const char * argv[]) {
    App *aApplication = new App();
    aApplication->run ( );
    
    delete aApplication;
    return 0;
}
