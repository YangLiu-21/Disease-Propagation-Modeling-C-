int main() {
              srand((unsigned)time(0));
              //single person
              Person joe;
              for ( int step= 1; ; step++) {

              float bad_luck = (float) rand()/(float) RAND_MAX;
              if (bad_luck >.95)
                 joe.infect(5);

              joe.update();
              cout << "On day " << step << ", Joe is "
                   << joe.status_string() << endl;
              if (joe.is_stable())
                 break;
              }

              int npeople = 40000; // the  total  number  of the  population
              int n =5; //with n days to go  before  recovery
              float probability = 0.1; // the  probability  to get  sick  when  interactswith a sick  person
              float percentage = 0; // the  percentage  of  people  that  has  beenvaccinated
              int ncontact = 15; //the  number  of  people  that a person  comes  intocontact  with
              int maximum = 0; // maximum number of sick people
              Population population(npeople, n, percentage);
              population.random_infection();
              cout << "Size of" << endl;
              cout << "population?" << endl;
              cout << npeople << " people" << endl;

              int vaccinated_people;
              int not_vaccinated_people;
              vaccinated_people = round(percentage*npeople);
              not_vaccinated_people = npeople-vaccinated_people;
              float not_sick_rate;

              for (int step = 1; ; step++ ) {
                  if (population.is_stable()){

                  cout <<"Total days of disease propagation: "<< step-1 <<endl;
                  cout << "Maximum number of sick people: " << maximum<< endl;
                  cout<< "Population that is inoculated: "<< population.count_inoculated() << endl;
                 // not_sick_rate = 1.0*(npeople - population.count_inoculated())/not_vaccinated_people;
                 /* cout <<"Number of people that cannot be vaccinated: "<< not_vaccinated_people << endl;
                  cout <<"Number of people who will never get sick: "
                       << (npeople - population.count_inoculated()) << endl;
                  cout << "this probability of people who cannot get vaccinated will never get sick is over "
                       << not_sick_rate*100 <<" %" << endl;*/
                  break;}
                  population.update();
                 // cout << population.count_infected() << endl;
                  cout << "In Step " << step << " #sick: " <<population.count_infected() << endl;
                 // cout << step <<"  "<< population.count_infected() << endl;
                    //   << " : " <<  population.displays() << endl;
                 // population.set_probability_of_transfer(probability);
                  if (maximum < population.count_infected()){
                  maximum = population.count_infected();}
                  population.random_interactions(probability,ncontact);
