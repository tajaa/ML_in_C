#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the training set: pairs of (x, y) values
float train[][2] = {{0, 0}, {1, 2}, {2, 4}, {3, 6}, {4, 8}};

// Calculate the number of training examples
#define train_count (sizeof(train) / sizeof(train[0]))

// Function to generate a random float between 0 and 1
float rand_float(void) { return (float)rand() / (float)RAND_MAX; }

// Cost function to calculate the mean squared error
float cost(float w) {
  float result = 0.0f;
  for (size_t i = 0; i < train_count; ++i) {
    float x = train[i][0];     // Input value
    float y = x * w;           // Predicted value
    float d = y - train[i][1]; // Difference between predicted and actual
    result += d * d;           // Sum of squared differences
  }
  result /= train_count; // Calculate mean
  return result;
}

int main() {
  // The model is y = x*w where x is the input and w is the parameter

  // Set random seed for reproducibility
  // srand(time(0));  // Uncomment this line to use current time as seed
  srand(69); // Use a fixed seed for reproducible results

  // Initialize w with a random value between 0 and 10
  float w = rand_float() * 10.0f;

  float eps = 1e-3;  // Small value for numerical approximation of derivative
  float rate = 1e-3; // Learning rate

  // Print initial cost
  printf("%f\n", cost(w));

  // Gradient descent loop
  for (size_t i = 0; i < 500; ++i) {
    // Numerical approximation of the derivative of the cost function
    float dcost = (cost(w + eps) - cost(w)) / eps;

    // Update w using gradient descent
    w -= rate * dcost;

    // Print cost at each iteration
    printf("%f\n", cost(w));
  }

  printf("------------------\n");
  // Print final value of w
  printf("%f\n", w);

  return 0;
}
