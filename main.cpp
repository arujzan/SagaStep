#include "saga_steps.h"
#include "saga_orchestrator.h"
#include <vector>

int main() {
    // Configure steps (true to simulate failure)
    std::vector<SagaStep*> steps = {
        new PaymentStep(false),
        new InventoryStep(false),
        new ShippingStep(true)  // Try changing this to false for successful completion
    };
    
    SagaOrchestrator orchestrator(steps);
    
    try {
        orchestrator.executeSaga();
        std::cout << "\nCheckout completed successfully!" << std::endl;
    } catch(const std::exception& e) {
        std::cout << "\nCheckout failed: " << e.what() << std::endl;
    }
    
    // Cleanup
    for(auto step : steps) {
        delete step;
    }
    
    return 0;
}