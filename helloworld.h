#ifndef HELLOWORLD_H_
#define HELLOWORLD_H_

#include "example.pb.h"

inline example::Example create() {
    example::Example example;
    example.set_id("Hello world");
    example.mutable_duration()->set_seconds(3);
    return example;
}

#endif // HELLOWORLD_H_