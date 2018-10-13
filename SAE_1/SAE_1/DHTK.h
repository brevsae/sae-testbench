//
//  DHTK.h
//  SAE_1
//
//  Created by Tomny Hang on 10/12/18.
//  Copyright © 2018 SAE. All rights reserved.
//

#ifndef DHTK_h
#define DHTK_h
#include "DHT.h"

class DHTK : public DHT {
    public:
    float ConvertCtoK(float);
    float ConvertFtoK(float);
};

#endif /* DHTK_h */
