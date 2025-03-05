#include <stdexcept>
#include <iostream>

class SagaStep {
public:
    virtual void doStep() = 0;
    virtual void compensate() = 0;
    virtual ~SagaStep() = default;
};

class PaymentStep : public SagaStep {
    bool shouldFail;
public:
    PaymentStep(bool fail) : shouldFail(fail) {}
    
    void doStep() override {
        std::cout << "Processing payment..." << std::endl;
        if(shouldFail) {
            throw std::runtime_error("Payment failed");
        }
        std::cout << "Payment processed successfully!" << std::endl;
    }
    
    void compensate() override {
        std::cout << "Refunding payment..." << std::endl;
    }
};

class InventoryStep : public SagaStep {
    bool shouldFail;
public:
    InventoryStep(bool fail) : shouldFail(fail) {}
    
    void doStep() override {
        std::cout << "Updating inventory..." << std::endl;
        if(shouldFail) {
            throw std::runtime_error("Inventory update failed");
        }
        std::cout << "Inventory updated successfully!" << std::endl;
    }
    
    void compensate() override {
        std::cout << "Restoring inventory..." << std::endl;
    }
};

class ShippingStep : public SagaStep {
    bool shouldFail;
public:
    ShippingStep(bool fail) : shouldFail(fail) {}
    
    void doStep() override {
        std::cout << "Scheduling shipping..." << std::endl;
        if(shouldFail) {
            throw std::runtime_error("Shipping failed");
        }
        std::cout << "Shipping scheduled successfully!" << std::endl;
    }
    
    void compensate() override {
        std::cout << "Canceling shipping..." << std::endl;
    }
};