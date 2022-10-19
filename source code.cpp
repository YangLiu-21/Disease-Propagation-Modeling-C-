/* Program Author: Yang Liu
Program Function: infectuous disease simulation

#include<iostream>
#include<vector>
#include<string>
#include<random>
#include <cmath>

using namespace std;
using std::vector;
using std::string;
using std::to_string;
using std::cout;
using std::cin;
using std::endl;

class Person
{
      private:
              //healthy but not vaccinated, value 0
              //recovered, value -1
              //vaccinated, value -2
              //sick, with n days to go before recovery, modeled by value n
              int state = 0;
              int day = -1;
      public:
              Person(){};
              string status_string(){
                     string s;
                   switch (state) {
                   case 0:
                     return "susceptible";
                     break;
                   case -1:
                     return "recovered";
                     break;
                   case -2:
                     return "inoculated";
                     break;
                   case 1:
                     s = "sick, with " + to_string(day) + " days to go before recovery";
                     return s;
                   }
              }
              bool update(){
                   if (day > 1)
                   {
                      day = day - 1;
                   }
                   else if (day == 1)
                   {
                      state = -1;
                   }
              }

              bool is_susceptible(){
                   return state==0;
              }
              void infect(int n){
                   if (is_susceptible()){
                   day = n;
                   state = 1;
                   }
              }
              void vaccinated(){
                   if (is_susceptible()){
                   state = -2;
                   }
              }
              bool is_stable(){
                   return  state == -1 || state == -2;
              }
              int get_state(){
                   return  state;
              }
};

class Population
{
      private:
              int n, v, i, npeople, nvaccinate;
              vector<Person> people;
      public:
              Population(){};
              //initialization
              Population(int people_number, int nday, float percentage)
                 {
                    n = nday;
                    npeople = people_number;
                    for (int i=0; i < npeople; i++){
                       Person per;
                       people.push_back(per) ;
                    };
                    nvaccinate = round(percentage*npeople);
                   // cout << nvaccinate << endl;
                   for (int i=0; i < nvaccinate; ){
                       v = rand() % npeople;
                       people[v].vaccinated();
                       if (people[v].get_state()==-2){
                          i++;
                       };
                    };
                  //  cout << v << people[v].status_string() << endl;
                 };
              void random_infection()
                 {
                     for (int i=0; ; i++){
                     v = rand() % npeople;
                     people[v].infect(n);
                     if (people[v].get_state()==1){
                         break;};
                     }
                    // cout << v <<people[v].status_string() << endl;
                 };
              int count_infected()
                 {
                     int n_infected = 0;
                     for (int i=0; i < npeople; i++){
                          if (people[i].get_state()==1){
                          n_infected = n_infected + 1;};
                   // cout << people[i].get_state() << endl;
                     };
                     return n_infected;
                 };
               int count_recovered()
                 {
                     int n_recovered = 0;
                     for (int i=0; i < npeople; i++){
                          if (people[i].get_state()==-1){
                          n_recovered = n_recovered + 1;};
                         };
                      return n_recovered;
                    };

              int count_inoculated()
                 {
                     int n_inoculated = 0;
                     for (int i=0; i < npeople; i++){
                          if (people[i].get_state()==-2 || people[i].get_state()==-1){
                          n_inoculated = n_inoculated + 1;};
                         };
                      return n_inoculated;
                    };
              void update()
                 {
                     for (int i=0; i < npeople; i++){
                          people[i].update();
                     };
                 };
              bool is_stable(){
                     int flag = 0;
                     for (int i=0; i < npeople; i++){
                          if (people[i].get_state()== -1 || people[i].get_state()== 0 || people[i].get_state()== -2 )
                          { continue;}
                          else
                          {flag = 1;}
                     };
                     return  flag == 0;
                 };
              string displays(){
                     string dis = "";
                     string s = "";
                   for (int i=0; i < npeople; i++){
                        switch (people[i].get_state()) {
                             case 0:
                                s = "?";
                                break;
                               case -1:
                                s = "-";
                                break;
                             case -2:
                                s = "v";
                                break;
                             case 1:
                                s = "+";};
                         dis = dis + s;
                        };
                       return dis;
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
               void random_interactions(float probability, int ncontact){
                           int j, k;
                           int flag = 0;
                           int contact;
                           vector<int> peo_contacted;
                           for (int i=0; i < npeople; i++){
                               if (people[i].get_state()==1){
                                      for ( j=0; j < ncontact; ){
                                              v = rand() % npeople;
                                               if (i != v){
                                                       peo_contacted.push_back(v);
                                                       j++;
                                                 };
                                           };
                                      };
                                 };
                           if( peo_contacted.size() >= 0){
                            for (int i=0; i < peo_contacted.size(); i++){
                                    bool TrueFalse = (rand() % 100) < (probability*100);
                                    if (TrueFalse) {
                                        people[peo_contacted[i]].infect(n);
                                       };
                                   };
                              };
                        };

               void social_distancing_interactions(float probability, int ncontact){
                           int j, k;
                           int flag = 0;
                           int contact;
                           vector<int> peo_contacted;

                           for (int i=0; i < npeople; i++){
                               if (people[i].get_state()==1){
                                      for ( j=0; j < ncontact; ){
                                              v = rand() % npeople;
                                               if (i != v){
                                                       peo_contacted.push_back(v);
                                                       j++;
                                                 };
                                           };
                                      };
                                 };
                           if( peo_contacted.size() >= 0){
                            for (int i=0; i < peo_contacted.size(); i++){
                                    bool TrueFalse = (rand() % 100) < (probability*100);
                                    if (TrueFalse) {
                                        people[peo_contacted[i]].infect(n);
                                       };
                                   };
                              };
                        };
};

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
