//
// Created by raj on 22/06/17.
//

#include <stock_view.h>

stock_view::stock_view(stock_model *model) : stock_observer(model), current_price(model->get_price()) {}

stock_view::~stock_view() {
    this->get_subject()->deregister_observer(this);
}

void stock_view::update_price(float newPrice) {
    this->current_price = newPrice;
}

void stock_view::update() {
    update_price(get_subject()->get_price());
}

float stock_view::get_stock_price() {
    return current_price;
}

