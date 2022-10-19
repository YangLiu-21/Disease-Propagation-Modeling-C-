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
                    cout << nvaccinate << endl;
                   for (int i=0; i < nvaccinate; ){
                       v = rand() % npeople;
                       people[v].vaccinated();
                       if (people[v].get_state()==-2){
                          i++;
                       };
                    };
                    cout << v << people[v].status_string() << endl;
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
