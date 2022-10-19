class Population
{
              . . . . . . 
              Population(int people_number, int nday, float percentage)
                 {
                    n = nday;
                    npeople = people_number;
                    for (int i=0; i < npeople; i++){
                       Person per;
                       people.push_back(per) ;
                    };
                    nvaccinate = round(percentage*npeople);
                    cout << nvaccinate << endl;
                   for (int i=0; i < nvaccinate; ){
                       v = rand() % npeople;
                       people[v].vaccinated();
                       if (people[v].get_state()==-2){
                          i++;
                       };
                    };
                  //  cout << v << people[v].status_string() << endl;
                 };
                   };
                   
              void set_probability_of_transfer(float probability){
                           int neighbor1, neighbor2;
                           int lower_bound, upper_bound;
                           lower_bound = 0;
                           upper_bound = npeople-1;
                           vector<int> direct_neighbors;
                           for (int i=0; i < npeople; i++){
                               if (people[i].get_state()==1){
                                      direct_neighbors.push_back(i);
                                     // cout << i << endl;
                                     };
                                 };
                           if( direct_neighbors.size() >= 0){
                             //  cout << direct_neighbors[0] << endl;
                               for (int i=0; i < direct_neighbors.size(); i++){
                       bool TrueFalse1 = (rand() % 100) < (probability*100);
                                    if (TrueFalse1) {
                                            neighbor1 = direct_neighbors[i] + 1;
                    if(neighbor1 >= lower_bound && neighbor1 <= upper_bound){
                                               people[neighbor1].infect(n);
                                            };};
                     bool TrueFalse2 = (rand() % 100) < (probability*100);
                                    if (TrueFalse2) {
                                            neighbor2 = direct_neighbors[i] - 1;
                    if(neighbor2 >= lower_bound && neighbor2 <= upper_bound){
                                               people[neighbor2].infect(n);
                                            };};
                                };
                            };
                        };
            . . . . . . 
\end{lstlisting}
main program:
\begin{lstlisting}[language=C++ , caption=main program: models a Population]
              . . . . . . 
              //Population
              int npeople = 50; // the  total  number  of the  population
              int n =5; //with n days to go  before  recovery
              float probability = 0.5; // the  probability  to get  sick  when  interactswith a sick  person
              iloat percentage = 0.04; // the  percentage  of  people  that  has  beenvaccinated
              int ncontact = 10; //the  number  of  people  that a person  comes  intocontact  with

              Population population(npeople, n, percentage);
              population.random_infection();
              cout << "Size of" << endl;
              cout << "population?" << endl;
              cout << npeople << " people" << endl;
             // population.random_interactions(probability,ncontact);
              for (int step = 1; ; step++ ) {
                  if (population.is_stable()){
                  cout <<"Disease ran its course by step"<< step-1<endl;
                  break;}
                  population.update();
                  cout << "In Step " << step << " #sick: " <<population.count_infected()
                       << " : " <<  population.displays() << endl;
                  population.set_probability_of_transfer(probability);
                 // population.random_interactions(probability,ncontact);

              };
