# SagaStep
Implement a Saga Pattern within a single microservice  Create an e-commerce “checkout” workflow with Payment, Inventory, and Shipping steps.   Each step must support "do" and "compensate" actions. If any step fails, previously completed steps must be compensated in reverse.   
# Saga Pattern Implementation for E-commerce Checkout

## Overview
This implementation demonstrates the Saga Pattern within a single microservice for an e-commerce checkout workflow. The pattern ensures data consistency across multiple operations (Payment, Inventory, Shipping) by providing compensating transactions for rollback scenarios.

## Design
1. **Saga Steps**:
   - Each step (Payment, Inventory, Shipping) implements `doStep()` and `compensate()` methods
   - `doStep()` performs the business operation
   - `compensate()` rolls back the operation

2. **Saga Orchestrator**:
   - Executes steps sequentially
   - Maintains list of completed steps
   - Triggers compensation in reverse order on failure
   - Handles nested compensation failures

## Flow
1. Payment Processing
2. Inventory Update
3. Shipping Scheduling

If any step fails:
- Previous successful steps are compensated in reverse order

saga_pattern/
├── saga_orchestrator.h
├── saga_steps.h
└── main.cpp
- Compensation failures are logged but don't stop the process

## Usage
1. Configure steps with success/failure flags in `main.cpp`
2. Run the program to see either:
   - Successful checkout flow
   - Failed flow with compensation sequence

## Key 
- Error handling for compensation steps
- Proper resource cleanup
- Transactional boundaries within single service
- Simulated failure points for demonstration
- Real-world implementations would need:
  - Persistent state storage
  - Retry mechanisms
  - Proper logging/monitoring
  - Distributed transaction support
