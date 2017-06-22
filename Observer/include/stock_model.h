//
// Created by raj on 22/06/17.
//

#ifndef OBSERVER_SUBJECT_H
#define OBSERVER_SUBJECT_H

#include <vector>

class stock_observer;

class stock_model {
public:
    stock_model(float stockPrice);

    void register_observer(stock_observer *obs);
    void deregister_observer(stock_observer *obs);

    void set_price(float newValue);
    float get_price();

    void notify();

private:
    std::vector<stock_observer *> views;
    float price;
};

#endif //OBSERVER_SUBJECT_H
