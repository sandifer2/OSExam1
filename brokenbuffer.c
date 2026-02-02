// Semaphore full = 1;  (Counts full slots)
// Semaphore empty = 0; (Counts empty slots) usually N not 0 
// Semaphore mutex = 1; (Protecting the buffer)

//Standard Producer code
void Producer(){
    P(empty);
    P(mutex);
    // Add item to buffer 
    V(mutex);
    V(full);


}





// Broken Producer code
void Producer() {
    P(mutex);  // Lock the buffer first [cite: 74, 75] mutex = 0 
    P(empty);  // Wait for an empty slot  empty alr = 0, cant perform wait here 
    
    // Add item to buffer
    
    V(mutex);
    V(full);
}

// Standard Consumer code
void Consumer() {
    P(full);   // Wait for a full slot full = 0 
    P(mutex);  // Lock the buffer [cite: 74, 75] mutex alr = 0 
    
    // Remove item from buffer
    
    V(mutex);
    V(empty);
}