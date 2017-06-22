//
// Created by raj on 22/06/17.
//

#ifndef OBSERVER_OBSERVER_H
#define OBSERVER_OBSERVER_H

#include "stock_model.h"

class stock_observer {
public:
    stock_observer(stock_model *);
    virtual void update() = 0;

    virtual ~stock_observer();

protected:
    stock_model *get_subject();

private:
    stock_model *model;
};

#endif //OBSERVER_OBSERVER_H
