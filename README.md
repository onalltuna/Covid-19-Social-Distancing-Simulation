# Covid-19 Social Distancing Simulation

The Covid-19 pandemic has drastically changed the way we live, introducing terms like "social distancing" into our everyday vocabulary. This assignment involves simulating the effects of social distancing in a grid-based world and understanding its critical importance. You will also gain experience in using dynamic arrays and managing memory.

## Introduction

In this simulation, you will investigate the impact of social distancing within a grid world. The simulation will consider various parameters and allow you to analyze how different levels of compliance with social distancing rules affect the spread of a disease. The grid world represents individuals, and you will simulate the spread of a disease within this population.

### Fixed Parameters

1. **Grid World:** Assume a grid world of size N x N, with each cell representing an individual. Individuals can transmit the disease to neighboring cells.

2. **Fatality Rate:** Set the fatality rate to 3%. This means that 3% of the infected cases will die after 4 cycles of being infected, during which they can still spread the disease.

3. **Recover Rate:** The remaining 97% of infected people recover from the infection after 4 cycles, becoming immune for the rest of the simulation.

4. **Initial Active Cases:** Assume 5% of the population as initial active cases. The population is defined by the grid world size, which is equal to N^2.

### Input Parameters

1. **World Size:** The size of the grid world, denoted as N.

2. **Social Distancing:** The percentage of people who comply with social distancing rules, affecting the chance of infection. For example, 60% social distancing means there is a 40% chance of transmitting the disease on contact with infected individuals.

3. **Simulation Length:** The number of cycles your code should run the simulation. In each cycle, the status of each person is evaluated and the world is updated.

4. **Random Seed:** Provide a random seed for all random functions in the code. This seed can be passed as the last command-line argument.

### Simulation Output

After running the simulation, the code prints the following information:

1. **Total Infections:** The total number of infections during the simulation.

2. **Total Deaths:** The total number of deaths during the simulation.

3. **Total Recovered Cases:** The total number of recovered cases during the simulation.

4. **Max Active Cases:** The peak number of active cases during the simulation.

5. **Cyclic Visualization:** Provide a file for each cycle (CYCLENUM.txt) showing the status of the grid world. Use ASCII art, where '0' represents a dead person, '1' represents a healthy person, and '*' represents an active case.


## Conclusion

This project allows you to simulate the impact of social distancing in a grid world and analyze how different levels of compliance can affect the spread of a disease. It provides a practical example of using dynamic arrays and memory management.

Feel free to adapt the code to explore various scenarios and understand the significance of social distancing in the current pandemic.


