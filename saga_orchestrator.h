#include <vector>
#include <stdexcept>

class SagaOrchestrator {
    std::vector<SagaStep*> steps;
    
public:
    SagaOrchestrator(std::vector<SagaStep*> steps) : steps(steps) {}
    
    void executeSaga() {
        std::vector<SagaStep*> completedSteps;
        
        try {
            for(auto step : steps) {
                step->doStep();
                completedSteps.push_back(step);
            }
        } catch(const std::exception& e) {
            std::cerr << "\nError: " << e.what() << "\nStarting compensation..." << std::endl;
            for(auto it = completedSteps.rbegin(); it != completedSteps.rend(); ++it) {
                try {
                    (*it)->compensate();
                } catch(const std::exception& ex) {
                    std::cerr << "Compensation failed: " << ex.what() << std::endl;
                }
            }
            throw;
        }
    }
};