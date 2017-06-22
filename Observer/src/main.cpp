#include <iostream>
#include <stock_model.h>
#include <stock_view.h>

int main() {
    stock_model stock(17.43);

    stock_view desktop_client(&stock);
    stock_view mobile_client(&stock);

    std::cout << "Stock price (Desktop - moment 1) : " <<desktop_client.get_stock_price()<<std::endl;
    std::cout << "Stock price (Mobile - moment 1) : " <<mobile_client.get_stock_price()<<std::endl;

    stock.set_price(16.29);

    std::cout << "Stock price (Desktop - moment 2) : " <<desktop_client.get_stock_price()<<std::endl;
    std::cout << "Stock price (Mobile - moment 2) : " <<mobile_client.get_stock_price()<<std::endl;

    return 0;
}