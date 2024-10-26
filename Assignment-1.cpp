// Program to calculate transition energy using simple Bohr formula
// Author: Clive Marvelous (10916086)
// Date: 02/05/23

#include<iostream>
#include<iomanip>
#include<cmath>

// Rydberg energy in eV
const float Ryd_energy{13.6}; 

// Functions
void getInput(const std::string& prompt, int& k);
float delta_E(int initial, int final, int atomic_n);
void getInput(const std::string& prompt, bool& j);


// Main function
int main()
{
  // Variable to repeat calculations
  bool repeat{true};

  while(repeat) 
  {
    // Declare variables here
    int n_initial, n_final, Z; 
    bool unit_in_joule; // Variable to determine unit of final answer 
    float E; 

    // Atomic number
    getInput("Enter atomic number, Z: ", Z);

    // Check for non-zer0 Z
    if(Z == 0)
    {
      std::cout<<"Z must be non-zero integer \n";
      getInput("Enter atomic number, Z: ", Z);
    }

    // Initial and final quantum numbers
    getInput("Enter initial quantum number, n_initial: ", n_initial);
    getInput("Enter final quantum number, n_final: ", n_final);

    // Check if transition is physically possible
    while(true) 
    {  
      if(n_initial == 0 or n_final == 0) 
      {
        std::cout<<"Quantum number must be non-zero integer \n";
        getInput("Enter initial quantum number, n_initial: ", n_initial);
        getInput("Enter final quantum number, n_final: ", n_final);
      }
      else if(n_initial >= n_final) break;
      else 
      {
        std::cout<<"Error: n_initial < n_final \n";
        getInput("Enter initial quantum number, n_initial: ", n_initial);
        getInput("Enter final quantum number, n_final: ", n_final);
      }
    }

    // Compute photon energy, Delta E 
    E = delta_E(n_initial, n_final, Z);

    // Output answer
    getInput("Unit of transition energy (Enter 0 for eV or 1 for Joules): ", unit_in_joule);
    if(unit_in_joule) 
    {
      E = E * 1.6e-19;
      std::cout<<std::scientific<<std::setprecision(1);
      std::cout<<"Transition energy, E = "<<E<<" J"<<std::endl;
    } 
    else
    {
      std::cout<<std::fixed<<std::setprecision(1);
      std::cout<<"Transition energy, E = "<<E<<" eV"<<std::endl;
    }

    
    // Check if user wants to repeat calculation
    while(true) 
    {
      // Declare local variable
      char c;

      // Prompt user for input
      std::cout<<"Repeat calculations? (y/n): ";
      std::cin>>c;

      // Validate input
      if(c == 'y') 
      {
        repeat = true; 
        break; 
      } 
      else if(c == 'n') 
      {
        repeat = false; 
        break;
      }
    }
  }

  return 0;
}

// Function to ask user for input and validate the input
void getInput(const std::string& prompt, int& k) 
{
  // Ask user for input
  std::cout<<prompt;
  std::cin>>k;
  
  // Check for validity 
  while(std::cin.fail()) 
  {
    std::cout<<"Sorry, your input was invalid. "<<prompt; 
    // Clear fail bit and ignore bad input
    std::cin.clear(); 
    std::cin.ignore(); 
    std::cin>>k;

  }
}

// Validate input for boolean
void getInput(const std::string& prompt, bool& j) 
{
  // Ask user for input
  std::cout<<prompt;
  std::cin>>j;
  
  // Check for validity 
  while(std::cin.fail()) 
  {
    std::cout<<"Sorry, your input was invalid. "<<prompt; 
    // Clear fail bit and ignore bad input
    std::cin.clear(); 
    std::cin.ignore(); 
    std::cin>>j;

  }
}

// Calculate photon energies, Delta E
float delta_E(int initial, int final, int atomic_n) 
{
  // Calculate energy
  return Ryd_energy * (std::pow(atomic_n, 2)) * (1/std::pow(final, 2) - 1/std::pow(initial, 2));
}
