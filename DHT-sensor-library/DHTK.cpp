//
//  DHTK.cpp
//  SAE_1
//
//  Created by Tomny Hang on 10/12/18.
//  Copyright © 2018 SAE. All rights reserved.
//

#include <stdio.h>
#include "DHTK.h"


    float DHTK::ConvertCtoK(float c) {
        return c + 273.15;
    }
    float DHTK::ConvertFtoK(float f) {
        return ((f -32)/1.8) + 273.15;
    }
