//
// Created by raj on 22/06/17.
//

#include <stock_observer.h>
#include <iostream>

stock_model::stock_model(float stockPrice) {
    this->price = stockPrice;
}

void stock_model::register_observer(stock_observer *obs) {
    this->views.push_back(obs);
}

void stock_model::deregister_observer(stock_observer *obs) {
    //TODO: Search for and remove stock_observer
    std::cout << "Deregistering observer..." << std::endl;
}

void stock_model::set_price(float newValue) {
    this->price = newValue;

    this->notify();
}

float stock_model::get_price() {
    return price;
}

void stock_model::notify() {
    for (unsigned int i = 0; i < views.size(); ++i) {
       views[i]->update();
    }
}

