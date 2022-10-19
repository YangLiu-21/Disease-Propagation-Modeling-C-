int main(){
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
}
