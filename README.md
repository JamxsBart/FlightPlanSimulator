# FlightPlanSimulator

A C++ flight-path simulator that models an aircraft or drone moving from a starting location to a destination while tracking flight details, obstacle proximity, and aircraft state changes.

## Overview

This project simulates a simplified aviation-style route:

- A flight is created with a start position and destination
- The aircraft follows a cruise speed and route direction
- The simulator calculates displacement and distance to the target
- Obstacles are generated along the flight path
- The aircraft reacts when an obstacle is near its route and transitions through flight states

## Features

- Flight route generation with start and destination coordinates
- Aircraft state control: OFF, TAKINGOFF, FLYING, LANDING, LANDED
- Live position updates during flight
- Distance and displacement calculations
- Obstacle modelling with type, position, and radius
- Basic obstacle detection and path obstruction handling
- Console-based simulation output for flight and obstacle details

## Project Structure

```text
FlightPlanSimulator/
├── README.md
├── src/
│   ├── AircraftData.h
│   ├── Flight.h
│   ├── Obstacle.h
│   ├── mainDrone.cpp
│   └── mainDrone
└── .gitignore
```

## Core Components

- `Flight.h`: defines the flight route structure and route metadata such as start position, destination, altitude, and speed.
- `AircraftData.h`: handles aircraft motion, state transitions, and route updates.
- `Obstacle.h`: defines obstacle types and obstacle data used to simulate hazards.
- `mainDrone.cpp`: contains the simulation loop and prints the flight information to the console.

## How It Works

1. A `Flight` object is created with a start point and destination.
2. A random obstacle is placed on or near the route.
3. An `AircraftData` object is initialized for the aircraft.
4. The aircraft starts moving along the flight vector.
5. The program repeatedly updates the position and checks whether the aircraft has reached the destination or is too close to an obstacle.
6. Relevant flight details are printed to the terminal during the simulation.

## Example Run

From the project root:

```bash
g++ -std=c++17 src/mainDrone.cpp -o mainDrone
./mainDrone
```

This will run the simulator and print the flight summary, obstacle details, and live positional updates while the aircraft is in flight.

## Notes

This is a lightweight educational simulation and is intended to demonstrate flight path and obstacle logic in C++. The code includes TODOs for future improvements such as:

- smoother animation
- more advanced rerouting logic
- added fuel, altitude, and cost calculations
- richer obstacle and event systems

## License

This project currently does not include a formal license file. If you plan to share or distribute it publicly, consider adding an appropriate open-source license such as MIT or GPL.

## Future Improvements

Potential next steps include:

- realistic aircraft physics and acceleration
- dynamic rerouting around obstacles
- GUI or visual map rendering
- weather and danger condition modelling
- route planning and efficiency calculations

