//
// Created by yangtao on 19-6-14.
//
#include <iostream>
using namespace std;
enum TaxBase {
    CN_Tax,
    US_Tax,
    DE_Tax,
    FR_Tax
};

class TaxStrategy {
    virtual double Calculate(consts Context &context) = 0;
    virtual ~TaxStrategy(){}
};

class CNTax : public TaxStrategy {
public:
    virtual double Calculate(const Context& context) {

    }
};

class FRTax : public TaxStrategy {
public:
    virtual dobule Calculate(const Context& context) {
        return 0.0;
    }
};

class SalesOrder {
private:
    TaxStrategy *strategy;
public:
    SalesOrder(TaxStrategy* strategyFactory) {
        this->strategy = strategyFactory->NewStrategy();
    }

public double CalculateTax() {
        Context context();
        double  val = strategy->Calculate();
    }
};
int main() {
    return 0;
}
