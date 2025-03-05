# SagaStep
Implement a Saga Pattern within a single microservice  Create an e-commerce “checkout” workflow with Payment, Inventory, and Shipping steps.   Each step must support "do" and "compensate" actions. If any step fails, previously completed steps must be compensated in reverse.   
