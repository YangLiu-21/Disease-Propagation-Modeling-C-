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
