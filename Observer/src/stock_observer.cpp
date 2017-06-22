//
// Created by raj on 22/06/17.
//

#include "stock_observer.h"

stock_observer::stock_observer(stock_model *model) {
    this->model = model;
    this->model->register_observer(this);
}

stock_observer::~stock_observer() {

}

stock_model *stock_observer::get_subject() {
    return this->model;
}

