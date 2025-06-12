//
// Created by Maksym on 12.01.2025.
//

#ifndef SLICE_HPP
#define SLICE_HPP

#include "../../includes.hpp"

#include <list>
#include <memory>


namespace engine_lib {
    using namespace std;
    template <typename data_type>
    class slice {
    private:
        list<shared_ptr<data_type>> data_;
    };
} // engine_lib

#endif //SLICE_HPP
