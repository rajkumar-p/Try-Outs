//
// Created by raj on 22/06/17.
//

#ifndef OBSERVER_STOCKOBSERVER_H
#define OBSERVER_STOCKOBSERVER_H

#include "stock_observer.h"

class stock_view: public stock_observer {
public:
    stock_view(stock_model *);
    ~stock_view();
    void update();

    float get_stock_price();

private:
    void update_price(float newPrice);

    float current_price;
};

#endif //OBSERVER_STOCKOBSERVER_H
