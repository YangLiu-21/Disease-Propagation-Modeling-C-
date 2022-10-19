# Disease Propagation Modeling (C++ Software Package)
description
We start by writing code that models a single person. The main methods serve to infect a person,
and to track their state. We need to have some methods for inspecting that state.

``Person class``:

``status string()``: returns a description of the person's state as a string;

``update()``: update the person's status to the next day;

``infect(int n)``: infect a person, with the disease to run for n days;

``is_stable()``: return a bool indicating whether the person has been sick and is recovered;

``is_susceptible()``: return a bool indicating whether the person has been susceptible or not;

``vaccinated()``: have a person be vaccinated, they are healthy, do not carry the disease, and can
not be infected;

``get_state()``: get the person's state as a single integer.

Next we need a Population class. Implement a population as a vector consisting of Person objects.
Initially we only infect one person, and there is no transmission of the disease.

``Population class``:

``Population(int people number, int nday, 
oat percentage)``: the constructor takes the
number of people;

``random_infection()``: a method that infects a random person;

``count_infected()``: counts how many people are infected;

``update()``: updates all persons in the population;

``string_displays()``: displays the state of the popular, using for instance: ' ?' for susceptible, '+'
for infected (get sick), '-' for recovered, 'v' for vaccinated.
