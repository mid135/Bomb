#ifndef FABRIC_H
#define FABRIC_H

#include <stdlib.h>
#include <stdio.h>
#include <memory>
#include <elements.h>
#include <cstdarg>
#include <arena.h>
#include <SFML/Graphics.hpp>

class Fabric {
    std::shared_ptr<Element> getObject(char* format, ...) {
        switch(format) {
        case 'player':
            va_list ap;
            va_start(ap,format);

        }
    }
};

#endif // FABRIC_H

